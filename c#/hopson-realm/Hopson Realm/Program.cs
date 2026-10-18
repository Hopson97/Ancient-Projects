using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Hopson_Realm
{
    class Program
    {
        public static void initOne()
        {
            Console.SetWindowSize(80, 45);
            GUI.Logo(35);
            Console.ReadLine();
            Console.Clear();

            Console.WriteLine("Please, enter a name for your character: ");
            GUI.TextColour("yellow");
            Player.name = Console.ReadLine();
            GUI.TextColour("white");
            Console.WriteLine("\nHello {0}", Player.name);
            Console.WriteLine("");
        }
        //sets window size, asks player for a name and shows the logo

        public static void colourPick()
        {
            Console.WriteLine("What colour shall your character be?");
            GUI.TextColour("blue");
            Console.Write("[B]");
            GUI.TextColour("white");
            Console.Write("lue, ");
            GUI.TextColour("red");
            Console.Write("[R]");
            GUI.TextColour("white");
            Console.Write("ed, ");
            GUI.TextColour("magenta");
            Console.Write("[M]");
            GUI.TextColour("white");
            Console.Write("agenta or ");
            GUI.TextColour("yellow");
            Console.Write("[Y]");
            GUI.TextColour("white");
            Console.Write("ellow? \n");

            Player.colour = Console.ReadLine();
            if (Player.colour == "B")
            {
                Player.colour = "blue";
                Console.WriteLine("Good choice. Press enter to begin.");
                Console.ReadLine();
            }            
            else if (Player.colour == "R")
            {
                Player.colour = "red";
                Console.WriteLine("Good choice. Press enter to begin.");
                Console.ReadLine();
            }            
            else if (Player.colour == "M")
            {
                Player.colour = "magenta";
                Console.WriteLine("Good choice. Press enter to begin.");
                Console.ReadLine();
            }           
            else if (Player.colour == "Y")
            {
                Player.colour = "yellow";
                Console.WriteLine("Good choice. Press enter to begin.");
                Console.ReadLine();
            }
            else
            {
                Console.Clear();
                Console.WriteLine("That is not a valid input. Did you type B, R, M or Y,\n and make sure they are capitalised?");
                Console.WriteLine();
                colourPick();
            }
            
        }
        

        static void Main(string[] args)
        {
            initOne();
            colourPick();
            Player.init();
            GameLoop.TheLoop();
            Console.ReadLine();


        }
    }
}
