using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Hopson_Realm
{
    class GUI
    {
        
        public static void TextColour(string colour)
        {
            #region red
            if (colour == "red")
            {
                Console.ForegroundColor = ConsoleColor.Red;
            }

            if (colour == "darkRed")
            {
                Console.ForegroundColor = ConsoleColor.DarkRed;
            }
            #endregion

            #region blue
            if (colour == "blue")
            {
                Console.ForegroundColor = ConsoleColor.Blue;
            }
            if (colour == "cyan")
            {
                Console.ForegroundColor = ConsoleColor.Cyan;
            }
            if (colour == "darkBlue")
            {
                Console.ForegroundColor = ConsoleColor.DarkBlue;
            }
            #endregion

            #region red
            if (colour == "red")
            {
                Console.ForegroundColor = ConsoleColor.Red;
            }
            #endregion

            #region green
            if (colour == "green")
            {
                Console.ForegroundColor = ConsoleColor.Green;
            }
            if (colour == "darkGreen")
            {
                Console.ForegroundColor = ConsoleColor.DarkGreen;
            }
            
            #endregion

            #region yellow
            if (colour == "yellow")
            {
                Console.ForegroundColor = ConsoleColor.Yellow;
            }
            #endregion

            #region yellow
            if (colour == "yellow")
            {
                Console.ForegroundColor = ConsoleColor.Yellow;
            }
            #endregion

            #region magenta
            if (colour == "magenta")
            {
                Console.ForegroundColor = ConsoleColor.Magenta;
            }
            #endregion

            #region white
            if (colour == "white")
            {
                Console.ForegroundColor = ConsoleColor.White;
            }
            #endregion

            #region black
            if (colour == "black")
            {
                Console.ForegroundColor = ConsoleColor.Black;
            }
            #endregion
        }

        public static void bgColour(string colour)
        {
            if (colour == "red")
            {
                Console.BackgroundColor = ConsoleColor.Red;
            }
            if (colour == "grey")
            {
                Console.BackgroundColor = ConsoleColor.Gray;
            }
            if (colour == "blue")
            {
                Console.BackgroundColor = ConsoleColor.Blue;
            }
            if (colour == "green")
            {
                Console.BackgroundColor = ConsoleColor.Green;
            }
            if (colour == "black")
            {
                Console.BackgroundColor = ConsoleColor.Black;

            }
            if (colour == "white")
            {
                Console.BackgroundColor = ConsoleColor.White;

            }
            if (colour == "yellow")
            {
                Console.BackgroundColor = ConsoleColor.Yellow;

            }
        }

        public static void Logo(int delay)
        {
            #region "Hopson Realm"
            TextColour("blue");
            Console.WriteLine(" _   _                                      ");
            System.Threading.Thread.Sleep(delay);
            Console.WriteLine("| | | |                                     ");
            System.Threading.Thread.Sleep(delay);
            Console.WriteLine("| |_| |  ___   _ __   ___   ___   _ __      ");
            System.Threading.Thread.Sleep(delay);
            Console.WriteLine("|  _  | / _ \\ | '_ \\ / __| / _ \\ | '_ \\ ");
            System.Threading.Thread.Sleep(delay);
            Console.WriteLine("| | | || (_) || |_) |\\__ \\| (_) || | | |  ");
            System.Threading.Thread.Sleep(delay);
            Console.WriteLine("\\_| |_/ \\___/ | .__/ |___/ \\___/ |_| |_| ");
            System.Threading.Thread.Sleep(delay);
            Console.WriteLine("______        | |   _                       ");
            System.Threading.Thread.Sleep(delay);
            Console.WriteLine("| ___ \\       |_|  | |                     ");
            System.Threading.Thread.Sleep(delay);
            Console.WriteLine("| |_/ / ___   __ _ | | _ __ ___             ");
            System.Threading.Thread.Sleep(delay);
            Console.WriteLine("|    / / _ \\ / _` || || '_ ` _ \\          ");
            System.Threading.Thread.Sleep(delay);
            Console.WriteLine("| |\\ \\|  __/| (_| || || | | | | |         ");
            System.Threading.Thread.Sleep(delay);
            Console.WriteLine("\\_| \\_|\\___| \\__,_||_||_| |_| |_|       ");
            #endregion
            #region Sword
            System.Threading.Thread.Sleep(delay);
            Console.WriteLine("                 __                         ");
            System.Threading.Thread.Sleep(delay);
            Console.WriteLine("                /  |                        ");
            System.Threading.Thread.Sleep(delay);
            Console.WriteLine("               /  /                         ");
            System.Threading.Thread.Sleep(delay);
            Console.WriteLine("              /  /                          ");
            System.Threading.Thread.Sleep(delay);
            Console.WriteLine("             /  /                           ");
            System.Threading.Thread.Sleep(delay);
            Console.WriteLine("            /  /                            ");
            System.Threading.Thread.Sleep(delay);
            Console.WriteLine("       _   /  /                             ");
            System.Threading.Thread.Sleep(delay);
            Console.WriteLine("       \\ \\/  /                            ");
            System.Threading.Thread.Sleep(delay);
            Console.WriteLine("        /   /                               ");
            System.Threading.Thread.Sleep(delay);
            Console.WriteLine("      _/ /\\ \\                             ");
            System.Threading.Thread.Sleep(delay);
            Console.WriteLine("     / \\/  \\_\\                           ");
            System.Threading.Thread.Sleep(delay);
            Console.WriteLine("    | O /                                   ");
            System.Threading.Thread.Sleep(delay);
            Console.WriteLine("     \\_/                                   ");
            System.Threading.Thread.Sleep(delay);
            Console.WriteLine("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
            System.Threading.Thread.Sleep(delay * 5);
            #endregion

            TextColour("red");
            Console.WriteLine("Press enter to begin.");

        }

        public static void EncounterHUD()
        {
            Console.Clear();
            Player.whichWeapon();
            Player.statHandler();
            GUI.HUDs();
        }


        public static void HUDs()
        {
            TopHUD();
            weaponHUD();
            MeleeHUD();
            rangeHUD();
            magicHUD();
            Console.BackgroundColor = ConsoleColor.Black;
        }

        public static void TopHUD()
        {
            Console.Clear();
            Console.BackgroundColor = ConsoleColor.Black;

            TextColour("magenta");
            Console.Write("{0}  ", Player.name);

            TextColour("cyan");
            Console.Write("Average Level: {0}| ", Player.averageLevel);
            TextColour("blue");
            Console.Write("Total Level: {0}| ", Player.totalLevel);
            TextColour("cyan");
            Console.Write("Total Exp: {0}  ", Player.totalXP);

            if (Player.health > ((Player.maxHealth/10)*3))
            {
                TextColour("darkGreen");
                Console.Write("Health: {0} / {1}  ", Player.health, Player.maxHealth);
            }
            else
            {
                TextColour("darkRed");
                Console.Write("Health: {0} / {1}  ", Player.health, Player.maxHealth);
            }

            Console.Write(new String(' ', Console.BufferWidth - Console.CursorLeft));

            
        }

        public static void weaponHUD()
        {
            bgColour("grey");
            TextColour("red");
            Console.Write("Current Weapon: ");
            TextColour("darkRed");
            Console.Write(" {0} ({1})", Player.displayWeapon, Player.styleType);
            TextColour("black");
            Console.Write("  Damage: {0}", Player.damage);
            Console.Write(new String(' ', Console.BufferWidth - Console.CursorLeft));
        }

        public static void MeleeHUD()
        {
            Console.BackgroundColor = ConsoleColor.Red;

            TextColour("yellow");
            Console.Write("Melee level: {0}  ", Player.meleeLevel);

            TextColour("green");
            Console.Write("Next Level: {0} / {1}  ", Player.currMeleeXP, Player.nextMeleeXP);

            TextColour("darkGreen");
            Console.Write("Total Melee Exp: {0}  ", Player.totalMeleeExp );

            Console.Write(new String(' ', Console.BufferWidth - Console.CursorLeft));
        }

        public static void rangeHUD()
        {
            Console.BackgroundColor = ConsoleColor.Green;

            TextColour("yellow");
            Console.Write("Range level: {0}  ", Player.rangeLevel);

            TextColour("blue");
            Console.Write("Next Level: {0} / {1}  ", Player.currRangeXP, Player.nextRangeXP);

            TextColour("darkBlue");
            Console.Write("Total Range Exp: {0}  ", Player.totalRangeExp);

            Console.Write(new String(' ', Console.BufferWidth - Console.CursorLeft));
        }

        public static void magicHUD()
        {
            Console.BackgroundColor = ConsoleColor.Blue;

            TextColour("yellow");
            Console.Write("Magic level: {0}  ", Player.magicLevel);

            TextColour("red");
            Console.Write("Next Level: {0} / {1}  ", Player.currMagicXP, Player.nextMagicXP);

            TextColour("black");
            Console.Write("Total Magic Exp: {0}  ", Player.totalMagicExp);

            Console.Write(new String(' ', Console.BufferWidth - Console.CursorLeft));
        }

        public static void mapInstruction()
        {
            TextColour("white");
            Console.WriteLine("");
            Console.WriteLine("Use arrow keys to move.");
            Console.Write("You may interact with \"");
            TextColour("red");
            Console.Write(" 1 ");
            TextColour("white");
            Console.Write("\" (doors), and \"");
            TextColour("red");
            Console.Write("  ^ > v <  ");
            TextColour("white");
            Console.Write("\" (new area locations)");
            Console.WriteLine("");

        }

        public static void OtherActions()
        {
            Console.WriteLine("");
            Console.Write("Press \"");
            GUI.TextColour("red");
            Console.Write(" s ");
            GUI.TextColour("white");
            Console.Write("\" to switch between combat styles (magic,melee and range)");
        }

        public static void Debug()
        {
            Console.WriteLine("");
            Console.WriteLine("");
            Console.WriteLine(Player.style);
        }
    }
}
