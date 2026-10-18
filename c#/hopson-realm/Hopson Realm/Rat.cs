using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Hopson_Realm
{
    class Rat
    {
        public int drawType;



        public int CustomDifficulty { get; set; }

        public int Level { get; set; }
        public int Health { get; set; }
        public int Damage { get; set; }



        public Rat(int level)
        {
            Level = level;
        }

        public void Draw()
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
            drawType = 1;
        }






    }
}
