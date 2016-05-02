using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProyectoFinal
{
    public class Reg
    {
        public int origin;
        public int destiny;
        public int current;
        public int total;
        public string statusProd;
        public bool isInsert;

        public Reg(int ori, int des)
        {
            origin = ori;
            destiny = des;
            current = 0;
            total = 0;
            statusProd = "";
        }
    }
}
