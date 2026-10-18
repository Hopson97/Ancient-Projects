using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Hopson_RPG
{
    class UI
    {
        public int health;
        public string playerName;
        public int level;
        public int x;
        public int y;


        //UI Handler Class
        //Developed (mostly) by Liam Newman
        //Idea by him I guess

        //test te


        public static void bgColour(string colour)
        {
            if (colour == "red")
            {
                Console.BackgroundColor = ConsoleColor.Red;
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

        public static void textColour(string colour)
        {
            if (colour == "red")
            {
                Console.ForegroundColor = ConsoleColor.Red;
            }
            if (colour == "blue")
            {
                Console.ForegroundColor = ConsoleColor.Blue;
            }
            if (colour == "green")
            {
                Console.ForegroundColor = ConsoleColor.Green;
            }
            if (colour == "white")
            {
                Console.ForegroundColor = ConsoleColor.White;

            }
            if (colour == "yellow")
            {
                Console.ForegroundColor = ConsoleColor.Yellow;

            }

        }

        public void addLine(string text, ConsoleColor background, ConsoleColor foreground)
        {
            Console.BackgroundColor = background;
            Console.ForegroundColor = foreground;
            Console.Write(text);
            Console.Write(new String(' ', Console.BufferWidth - Console.CursorLeft));
        }

        public void setBackground(ConsoleColor background, bool fill)
        {
            Console.BackgroundColor = background;
            if (fill)
            {
                Console.Clear();
            }
        }




        public void initUI(int uihealth, string uiplayerName, int uilevel, int uix, int uiy)
        {
            health = uihealth;
            playerName = uiplayerName;
            level = uilevel;
            x = uix;
            y = uiy;
        }

        public void updateUI()
        {

            Console.Clear();
            Console.BackgroundColor = ConsoleColor.DarkBlue;
            Console.ForegroundColor = ConsoleColor.Yellow;
            Console.Write("" + playerName + "  "); //-------------------------------Name
            Console.ForegroundColor = ConsoleColor.Green;
            Console.Write("HP: " + health + "/" + Player.maxHealth + "  ");//-------Health
            Console.ForegroundColor = ConsoleColor.White;
            Console.Write("Level " + level + "  ");//-------------------------------Level
            Console.ForegroundColor = ConsoleColor.Cyan;
            Console.Write("XP: " + Player.expNow + "/" + Player.expNext + "  ");//--Exp
            Console.ForegroundColor = ConsoleColor.Red;
            Console.Write("X: " + x + "  ");//--------------------------------------X Pos
            Console.Write("Y: " + y + "  ");//--------------------------------------Y Pos
            Console.Write(new String(' ', Console.BufferWidth - Console.CursorLeft));
        }

        public static void dungeonInstructions()
        {
            Player.statHandler();
            Player.currentStats();
            Maps.blockPrinter();


            UI.bgColour("black");
            UI.textColour("white");

            Maps.whereAmID1();

            Console.WriteLine("");
            Console.WriteLine("The X represents you. Use the arrow keys to move.");
            Console.WriteLine("You can also use basic text commands (look, grab, drop, etc). Press enter to open a prompt.");
            Random rand = new Random();
            int weaponFind = rand.Next(0, 2);
            if (weaponFind >= 1)
            {
                Console.WriteLine("You have found a weapon.");
                Weapon.generateWeapon();
            }

        }




    }
}
