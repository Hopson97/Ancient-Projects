using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Hopson_Realm
{
    class Draw
    {
        public static void encounterAnimation()
        {
            Console.Clear();
            short delay = 30;
            Random animate = new Random();
            for (int i = 0; i < 40; i++)
            {
                int lineType = animate.Next(1, 5);
                if (lineType == 1)
                {
                    GUI.bgColour("red");
                    Console.Write(new String(' ', Console.BufferWidth - Console.CursorLeft));
                    System.Threading.Thread.Sleep(delay);
                }
                if (lineType == 2)
                {
                    GUI.bgColour("blue");
                    Console.Write(new String(' ', Console.BufferWidth - Console.CursorLeft));
                    System.Threading.Thread.Sleep(delay);
                }
                if (lineType == 3)
                {
                    GUI.bgColour("green");
                    Console.Write(new String(' ', Console.BufferWidth - Console.CursorLeft));
                    System.Threading.Thread.Sleep(delay);
                }
                if (lineType == 4)
                {
                    GUI.bgColour("yellow");
                    Console.Write(new String(' ', Console.BufferWidth - Console.CursorLeft));
                    System.Threading.Thread.Sleep(delay);
                }
                

            }
            System.Threading.Thread.Sleep(250);
            GUI.bgColour("black");
            Console.Clear();
        }

        public static byte drawType = 1; //1 = norm, 2 = hurt, 3 = attacking

        public static void TEMPLATE()
        {

            #region Colours
            if (drawType == 1)
            {
                GUI.TextColour("white");
            }
            if (drawType == 2)
            {
                GUI.TextColour("red");
            }
            if (drawType == 3)
            {
                GUI.TextColour("darkRed");
            }
            #endregion
            #region Drawing
            GUI.TextColour("white");
            Console.WriteLine("~~~~~~~~~~~~~~~~~~~~~~~~~~~");
            Console.WriteLine("                           ");
            Console.WriteLine("                           ");
            Console.WriteLine("                           ");
            Console.WriteLine("                           ");
            Console.WriteLine("                           ");
            Console.WriteLine("                           ");
            Console.WriteLine("                           ");
            Console.WriteLine("                           ");
            Console.WriteLine("                           ");
            Console.WriteLine("                           ");
            Console.WriteLine("~~~~~~~~~~~~~~~~~~~~~~~~~~~");              
            #endregion
            GUI.TextColour("white");
            
        }

        public static void Rat()
        {
            #region Colours
            if (drawType == 1)
            {
                GUI.TextColour("white");
            }
            if (drawType == 2)
            {
                GUI.TextColour("red");
            }
            if (drawType == 3)
            {
                GUI.TextColour("darkRed");
            }
            #endregion
            #region Drawing
            Console.WriteLine("~~~~~~~~~~~~~~~~~~~~~~~~~~~");
            Console.WriteLine("    __              __     ");
            Console.WriteLine("   /  \\            /  \\    ");
            Console.WriteLine("   | \\|            | /|   ");
            Console.WriteLine("    \\ /\\-----------/\\ /    ");
            Console.WriteLine("     \\_  O   '  O   _/     ");
            Console.WriteLine("     | __` |' |  __  |     ");
            Console.WriteLine("      \\  \\/ [] \\/`` /      ");
            Console.WriteLine("       \\ /\\____/\\  /       ");
            Console.WriteLine("       |\\___--____/|       ");
            Console.WriteLine("       |  `''  `' ' |      ");
            Console.WriteLine("~~~~~~~~~~~~~~~~~~~~~~~~~~~");
            #endregion

        }
    }
}
