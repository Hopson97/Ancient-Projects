using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Flappy_Bird
{
    class Program
    {
        

        static void Main(string[] args)
        {
            int delay = 500;
            Bird bird = new Bird();
            Field background = new Field();
            background.SetMap();
            Console.Clear();

            bird.x = 3;
            bird.y = 10;

            while(true)                
            {
                background.updateBackground();

                bird.logic();
                Console.WriteLine("Bird x {0}, Bird y {1}", bird.x, bird.y);
                System.Threading.Thread.Sleep(delay);
                Console.Clear();              
            }
        }
    }
}
