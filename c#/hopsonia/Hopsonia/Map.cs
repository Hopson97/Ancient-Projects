using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Hopsonia
{
    class Map
    {
        public int y;
        public int x;

        public Map()
        {
            x = 0;
            y = 0;
        }


        public string[,] map;

        private void colour(string[,] map, int j, int i)
        {
            UI ui = new UI();
            
            if (map[j,i] == ".")
            {
                ui.textColor("green");
            }
            if (map[j, i] == "#")
            {
                ui.textColor("red");
            }
            if (map[j, i] == "@")
            {
                ui.textColor("white");
            }
            if (map[j, i] == ">" || map[j, i] == "<" || map[j, i] == "^" || map[j, i] == "v")
            {
                ui.textColor("green");
            }
        }

        public void draw(int playerX, int playerY, string[,] map)
        {
            map[playerY, playerX] = "@";

            for (int i = 0; i < 10; i++)
            {
                for (int j = 0; j < 10; j++)
                {
                    this.colour(map, i, j);
                    Console.Write("{0} ", map[i,j]);
                }
                Console.WriteLine();
            }
        }

        public void mapLayout()
        {
            #region y = 0
            if (y == 0)
            {
                if (x == 0)
                {
                    map = new string[10, 10]
                    {
                        {"#","#","#","#","#","#","#","#","#","#"},
                        {"#",".",".",".",".",".",".",".",".","#"},
                        {"#",".",".",".",".",".",".",".",".","#"},
                        {"#",".",".",".",".",".",".",".",".","#"},
                        {"#",".",".",".",".",".",".",".",".","#"},
                        {"#",".",".",".",".",".",".",".",".",">"},
                        {"#",".",".",".",".",".",".",".",".","#"},
                        {"#",".",".",".",".",".",".",".",".","#"},
                        {"#",".",".",".",".",".",".",".",".","#"},
                        {"#","#","#","#","#","#","#","#","#","#"},
                    };
                }
                if (x == 1)
                {
                    map = new string[10, 10]
                    {
                        {"#","#","#","#","#","#","#","#","#","#"},
                        {"#",".",".",".",".",".",".",".",".","#"},
                        {"#",".",".",".",".",".",".",".",".","#"},
                        {"#",".",".",".",".",".",".",".",".","#"},
                        {"#",".",".",".",".",".",".",".",".","#"},
                        {"<",".",".",".",".",".",".",".",".","#"},
                        {"#",".",".",".",".",".",".",".",".","#"},
                        {"#",".",".",".",".",".",".",".",".","#"},
                        {"#",".",".",".",".",".",".",".",".","#"},
                        {"#","#","#","#","#","#","#","#","#","#"},
                    };
                }
            }
            #endregion
        }
    }
}
