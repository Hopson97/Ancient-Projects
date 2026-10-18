using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Hopsonia
{
    class UI
    {
        public void drawLogo()
        {
            byte delay = 100;
            Console.WriteLine(" _   _                                   _        ");
            System.Threading.Thread.Sleep(delay);
            Console.WriteLine("| | | |                                 (_)       ");
            System.Threading.Thread.Sleep(delay);
            Console.WriteLine("| |_| |  ___   _ __   ___   ___   _ __   _   __ _ ");
            System.Threading.Thread.Sleep(delay);
            Console.WriteLine("|  _  | / _ \\ | '_ \\ / __| / _ \\ | '_ \\ | | / _` |");
            System.Threading.Thread.Sleep(delay);
            Console.WriteLine("| | | || (_) || |_) |\\__ \\| (_) || | | || || (_| |");
            System.Threading.Thread.Sleep(delay);
            Console.WriteLine("\\_| |_/ \\___/ | .__/ |___/ \\___/ |_| |_||_| \\__,_|");
            System.Threading.Thread.Sleep(delay);
            Console.WriteLine("              | |                                 ");
            System.Threading.Thread.Sleep(delay);
            Console.WriteLine("              |_|                                 ");
            System.Threading.Thread.Sleep(delay);
            Console.WriteLine("");
        }

        public void textColor(string colour)
        {
            switch (colour)
            {
                case "yellow":
                    Console.ForegroundColor = ConsoleColor.Yellow;
                    break; 
                case "green":
                    Console.ForegroundColor = ConsoleColor.Green;
                    break;
                case "white":
                    Console.ForegroundColor = ConsoleColor.White;
                    break;
                case "red":
                    Console.ForegroundColor = ConsoleColor.Red;
                    break;
                case "blue":
                    Console.ForegroundColor = ConsoleColor.Blue;
                    break; 
            }
        }

        public void debug(int mapX, int mapdir)
        {
            Console.WriteLine("Map X: {0}", mapX);
            Console.WriteLine("Map dir: {0}", mapdir);
        }

        public void InfoBar(string name)
        {
            UI ui = new UI();
            Console.BackgroundColor = ConsoleColor.Blue;

            ui.textColor("white");
            Console.Write(name);



            Console.Write(new String(' ', Console.BufferWidth - Console.CursorLeft));
            Console.BackgroundColor = ConsoleColor.Black;
        }


    }
}
