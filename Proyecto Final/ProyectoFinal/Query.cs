using MySql.Data.MySqlClient;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ProyectoFinal
{
    class Query
    {
        MySqlConnection connection;
        MySqlCommand function;

        public void initializate(String myConnectionString)
        {
            connection = new MySqlConnection(myConnectionString);
        }

        public bool openConnection()
        {
            try
            {
                connection.Open();

                return true;
            }
            catch (Exception)
            {
                return false;
            }

        }

        public bool closeConnection()
        {
            try
            {
                connection.Close();
                return true;
            }
            catch (Exception)
            {
                return false;
            }

        }


        public void insert(String origen, String destino)
        {
            String query = "INSERT INTO lista_transaccion(origen,destino) VALUES(" + "'" + origen + "'" + "," + "'" + destino + "'" + ");";
            function = new MySqlCommand(query, connection);

            try
            {

                if (openConnection() == true)
                {
                    if (function.ExecuteNonQuery() == 1)
                    {
                        //MessageBox.Show("Query Executed");
                    }
                    else {
                        //MessageBox.Show("Query Not Executed");
                    }
                }

            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
            finally
            {
                closeConnection();
            }

        }

        public void delete(String origen, String destino)
        {
            String query = "DELETE FROM lista_transaccion WHERE origen = '" + origen + "' AND destino = '" + destino + "' LIMIT 1";
            if (openConnection() == true)
            {

                function = new MySqlCommand(query, connection);
                function.ExecuteNonQuery();
                //close connection
                closeConnection();
            }

        }

    }
}
