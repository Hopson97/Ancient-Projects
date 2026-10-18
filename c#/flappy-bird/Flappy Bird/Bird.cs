using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Flappy_Bird
{
    class Bird
    {
        ConsoleKeyInfo KeyPressed = Console.ReadKey();

        public int x;
        public int y;
        
        public Bird()
        {
            x = 3;
            y = 10;
        }

        public void logic()
        {
            input();
        }

        private void input()
        {
            

            if (KeyPressed.Key == ConsoleKey.UpArrow)
            {
                x++;        
            }


        }

    }
}
