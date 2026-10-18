using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Hopsonia
{
    class Player
    {
        public string name;
        public int x;
        public int y;

        public Player()
        {
            x = 3;
            y = 3;
        }
        
        public string askName()
        {
            string askname;
            Console.WriteLine("What is your name?");
            askname = Console.ReadLine();

            return askname;
        }

        public int input(string[,] map)
        {
            #region Ver and Horr movement
            if (Console.ReadKey(true).Key == ConsoleKey.UpArrow)
            {
                if(map[y-1,x] == ".")
                {
                    y--;
                    return 0;
                }
                if (map[y - 1, x] == "v")
                {
                    return 2;
                }
            }
            else if (Console.ReadKey(true).Key == ConsoleKey.DownArrow)
            {
                if (map[y + 1, x] == ".")
                {
                    y++;
                    return 0;
                }
                if (map[y+1, x] == "v")
                {
                    return 4;
                }
            }
            else if (Console.ReadKey(true).Key == ConsoleKey.LeftArrow)
            {
                if (map[y, x - 1] == ".")
                {
                    x--;
                    return 0;
                }
                if (map[y, x - 1] == "<")
                {
                    return 1;
                }
            }
            else if (Console.ReadKey(true).Key == ConsoleKey.RightArrow)
            {
                if (map[y, x + 1] == ".")
                {
                    x++;
                    return 0;
                }
                if (map[y, x + 1] == ">")
                {                  
                    return 3;
                }
            }
            return 0;
            #endregion
            
        }
    }
}
