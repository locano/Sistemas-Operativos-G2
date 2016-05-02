using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Threading;
using Amib.Threading;

namespace ProyectoFinal
{
    public partial class Form1 : Form
    {
        //Threadpools
        SmartThreadPool producers = new SmartThreadPool();
        SmartThreadPool consumers = new SmartThreadPool();
        //Parámetros de inicialización y máximos
        int numProducers = 0, numConsumers = 0, queueSize = 0;
        //Cola compartida
        Queue<Reg> regQueue = new Queue<Reg>();
        //Utilizado para saber si hay que hacer refresh del datagridview
        bool queueChanged = false;
        bool produciendo = true;
        //Utilizados para exclusión mutua
        private Mutex _lock = new Mutex();
        private int regCount = 0;

        //Utilizados para retrasar a los métodos y visualizar el progreso
        const int producerSleepTime = 100, consumerSleepTime = 100, refreshTime = 50;

        #region Inicializar parámetros de thread pools y cola
        private void button1_Click(object sender, EventArgs e)
        {
            //Inicializar los thread pools y asignar capacidad máxima de la cola
            numProducers = Int32.Parse(txtProductores.Text);
            numConsumers = Int32.Parse(txtConsumidores.Text);
            queueSize = Int32.Parse(txtCola.Text);

            producers.MaxThreads = numProducers;
            consumers.MaxThreads = numConsumers;

            //Crear a los consumidores iniciales
            for (int i = 0; i < numConsumers; i++)
            {
                consumers.QueueWorkItem(consume);
            }

            //Cambio de form, de inicializador a normal
            groupIni.Visible = false;
            groupDet.Visible = true;

            //Timer encargado de refrescar los datagridview
            timerUpdate.Interval = refreshTime;
            timerUpdate.Start();
        }
        #endregion

        //Botón de producir
        private void button2_Click(object sender, EventArgs e)
        {
            //Crea una nueva task para producir un INSERT
            int times = Int32.Parse(txtVeces.Text);
            int origin = Int32.Parse(txtOrigen.Text);
            int destiny = Int32.Parse(txtDestino.Text);
            Reg reg = new Reg(origin, destiny);
            reg.total = times;
            reg.isInsert = true;
            producers.QueueWorkItem(produce, reg, times);
        }

        public void produce(Reg reg, int times)
        {
            for (int i = 0; i < times; i++)
            {
                while (!produciendo) { }
                _lock.WaitOne();
                try
                {
                    reg.statusProd = "En Proceso";
                    regQueue.Enqueue(reg);
                    queueChanged = true;
                    regCount++;
                    reg.current++;

                    if (regCount >= queueSize)
                    {
                        produciendo = false;
                    }
                    reg.statusProd = "En Espera";
                }
                finally
                {
                    _lock.ReleaseMutex();
                    System.Threading.Thread.Sleep(producerSleepTime);
                }
            }
        }

        public void consume()
        {
            while (produciendo) { }
            Reg dequeued = null;
            _lock.WaitOne();
            try
            {
                dequeued = regQueue.Dequeue();
                queueChanged = true;
                regCount--;
                if (regCount == 0)
                {
                    produciendo = true;
                }
            }
            finally
            {
                _lock.ReleaseMutex();
                
                String origen = dequeued.origin.ToString();
                String destino = dequeued.destiny.ToString();

                string myConnectionString = "server=localhost;database=lista_transaccion;uid=pfinal;pwd=pfinal;";
                Query querys = new Query();
                querys.initializate(myConnectionString);
                if (dequeued.isInsert)
                    querys.insert(origen, destino);
                else
                    querys.delete(origen, destino);
                consumers.QueueWorkItem(consume);
                System.Threading.Thread.Sleep(consumerSleepTime);
            }
        }

        //Refresca los datagridview utilizados en el debugging de qué hace cada thread
        private void updateDataGridView()
        {
            if (queueChanged)
            {
                List<Reg> cola = regQueue.ToList();
                dataGridCola.Rows.Clear();
                for (int i = 0; i < cola.Count; i++)
                {
                    dataGridCola.Rows.Add(cola[i].origin, cola[i].destiny);
                }
                queueChanged = false;
            }

            dataGridProducers.Rows.Clear();
            if (producers != null)
            {
                List<Reg> regs = producers.getWorkerThreads();
                string statusProd = "Procesando";
                if (!produciendo)
                    statusProd = "En Espera";
                for (int i = 0; i < regs.Count; i++)
                {
                    dataGridProducers.Rows.Add("Thread " + i.ToString() + " - (" + regs[i].origin.ToString() + ", " + regs[i].destiny.ToString() + ")"
                        , statusProd, regs[i].current + "/" + regs[i].total);
                }
                for (int i = regs.Count; i < numProducers; i++)
                {
                    dataGridProducers.Rows.Add("Thread " + i.ToString(), "Libre", "-");
                }
            }

            dataGridConsumers.Rows.Clear();
            if (consumers != null)
            {
                List<Reg> regs = consumers.getWorkerThreads();
                string statusProd = "Procesando";
                if (produciendo)
                    statusProd = "En Espera";
                for (int i = 0; i < consumers.ActiveThreads; i++)
                {
                    dataGridConsumers.Rows.Add("Thread " + i.ToString(), statusProd);
                }
                for (int i = consumers.ActiveThreads; i < numConsumers; i++)
                {
                    dataGridConsumers.Rows.Add("Thread " + i.ToString(), "Libre");
                }
            }
        }

        public Form1()
        {
            InitializeComponent();
        }

        #region Text Box Formatting (not important)
        private void textBox3_KeyPress(object sender, KeyPressEventArgs e)
        {
            BlockABC(e);
        }

        private void textBox4_KeyPress(object sender, KeyPressEventArgs e)
        {
            BlockABC(e);
        }

        private void textBox5_KeyPress(object sender, KeyPressEventArgs e)
        {
            BlockABC(e);
        }

        private void txtProductores_KeyPress_1(object sender, KeyPressEventArgs e)
        {
            BlockABC(e);
        }

        private void button3_Click(object sender, EventArgs e)
        {
            //Crea una nueva task para producir un DELETE
            int times = Int32.Parse(txtVeces.Text);
            int origin = Int32.Parse(txtOrigen.Text);
            int destiny = Int32.Parse(txtDestino.Text);
            Reg reg = new Reg(origin, destiny);
            reg.total = times;
            reg.isInsert = false;
            producers.QueueWorkItem(produce, reg, times);
        }

        private void timerUpdate_Tick(object sender, EventArgs e)
        {
            updateDataGridView();
        }

        private void txtConsumidores_KeyPress(object sender, KeyPressEventArgs e)
        {
            BlockABC(e);
        }

        private void txtCola_KeyPress(object sender, KeyPressEventArgs e)
        {
            BlockABC(e);
        }

        public void BlockABC(KeyPressEventArgs e)
        {
            if (Char.IsDigit(e.KeyChar))
            {
                e.Handled = false;
            }
            else if (Char.IsControl(e.KeyChar))
            {
                e.Handled = false;
            }
            else
            {
                e.Handled = true;
            }
        }
        #endregion
    }
}
