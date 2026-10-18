using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Hopson_RPG
{
    class Program
    {
        public static string drawType;

        public static string playerClass; //The 'class' the player chose
        public static int dungeon; // Which dungeon the player is in.

        static void Main(string[] args)
        {
            Console.SetWindowSize(80, 33);
            UI.textColour("blue");
            logo();
            Console.ForegroundColor = ConsoleColor.DarkGray;
            Console.WriteLine("Hopson RPG V.0.2 newman-edit");
            UI.textColour("white");
            Console.WriteLine("Welcome!");
            UI.textColour("red");
            Console.WriteLine("Please maximise this window for full experience, or it may look odd!");
            UI.textColour("white");
            Console.WriteLine("");
            Console.Write("[");
            UI.textColour("yellow");
            Console.Write("S");
            UI.textColour("white");
            Console.Write("]tart Game");
            do
            {
                while (!Console.KeyAvailable)
                {
                    // Do something
                }
            } while (Console.ReadKey(true).Key != ConsoleKey.S);
            options();
            chooseClass();
        }
        static void chooseClass()
        {
            Console.Clear();
            UI classMenu = new UI();
            classMenu.addLine("Choose Class", ConsoleColor.DarkBlue, ConsoleColor.Green);
            classMenu.setBackground(ConsoleColor.Black, false);
            bool classSelected = false;
            UI.textColour("white");
            Console.Write("[");
            UI.textColour("yellow");
            Console.Write("W");
            UI.textColour("white");
            Console.Write("]arrior: ");
            UI.textColour("green");
            Console.WriteLine("Can deal more damage and has a lower chance of missing");
            UI.textColour("red");
            Console.WriteLine("Takes significantly more damage");
            Console.WriteLine("");
            UI.textColour("white");
            Console.Write("[");
            UI.textColour("yellow");
            Console.Write("A");
            UI.textColour("white");
            Console.Write("]rcher: ");
            UI.textColour("green");
            Console.WriteLine("Takes less damage and can enchant arrows");
            UI.textColour("red");
            Console.WriteLine("Has lower base damage and higher chance of missing");
            while (classSelected != true)
            {
                if (Console.ReadKey(true).Key == ConsoleKey.W)
                {
                    Warrior();
                    classSelected = true;
                }

                if (Console.ReadKey(true).Key == ConsoleKey.A)
                {
                    Archer();
                    classSelected = true;
                }
            }


        } //Where the player chooses their class
        public static void Warrior()
        {
            playerClass = "warrior";
            Console.Clear();
            UI.textColour("yellow");
            Console.WriteLine("You have selected a warrior. Do you want to choose this class? [y/N]");
            bool chosen = false;
            while (chosen != true)
            {
                if (Console.ReadKey(true).Key == ConsoleKey.Y)
                {
                    UI.textColour("green");
                    Console.WriteLine("You are now a warrior!");
                    continueOne();
                    chosen = false;
                }

                if (Console.ReadKey(true).Key == ConsoleKey.N)
                {
                    chooseClass();
                }
            }

        } //If they chose Sword Man
        public static void Archer()
        {
            playerClass = "archer";
            Console.Clear();
            UI.textColour("yellow");
            Console.WriteLine("You have selected an archer. Do you want to choose this class? [y/N]");
            bool chosen = false;
            while (chosen != true)
            {
                if (Console.ReadKey(true).Key == ConsoleKey.Y)
                {
                    UI.textColour("green");
                    Console.WriteLine("You are now an archer!");
                    continueOne();
                    chosen = false;
                }

                if (Console.ReadKey(true).Key == ConsoleKey.N)
                {
                    chooseClass();
                }
            }

        } // If they chose Bow Man
        public static void continueOne()
        {

            Console.WriteLine("Now, we just need a name for your hero! Type one in now.");
            UI.textColour("white");
            Player.playerName = Console.ReadLine();
            Console.WriteLine("Alright, " + Player.playerName + ", lets go! Press enter to begin.");
            dungeon = 1;
            Console.ReadLine();

            Player.maxHealth = 10;
            Player.health = 10;
            Player.playerX = 1;
            Player.playerY = 2;
            Player.level = 1;
            Player.expNow = 0;
            Player.expNext = 10;
            Player.weapon = 1;
            Player.armour = 1;

            DungeonOne.dungOneInit();
        } //Start the adventure

        public static void logo()
        {
            int printDelay = 50;
            Console.WriteLine("          _______  _______  _______  _______  _       ");
            System.Threading.Thread.Sleep(printDelay);
            Console.WriteLine("|\\     /|(  ___  )(  ____ )(  ____ \\(  ___  )( (    /|");
            System.Threading.Thread.Sleep(printDelay);
            Console.WriteLine("| )   ( || (   ) || (    )|| (    \\/| (   ) ||  \\  ( |");
            System.Threading.Thread.Sleep(printDelay);
            Console.WriteLine("| (___) || |   | || (____)|| (_____ | |   | ||   \\ | |");
            System.Threading.Thread.Sleep(printDelay);
            Console.WriteLine("|  ___  || |   | ||  _____)(_____  )| |   | || (\\ \\) |");
            System.Threading.Thread.Sleep(printDelay);
            Console.WriteLine("| (   ) || |   | || (            ) || |   | || | \\   |");
            System.Threading.Thread.Sleep(printDelay);
            Console.WriteLine("|/     \\|(_______)|/       \\_______)(_______)|/    )_)");
            System.Threading.Thread.Sleep(printDelay);
            Console.WriteLine("");
            System.Threading.Thread.Sleep(printDelay);
            Console.WriteLine(" _______  _______  _______ ");
            System.Threading.Thread.Sleep(printDelay);
            Console.WriteLine("(  ____ )(  ____ )(  ____ \\");
            System.Threading.Thread.Sleep(printDelay);
            Console.WriteLine("| (    )|| (    )|| (    \\/");
            System.Threading.Thread.Sleep(printDelay);
            Console.WriteLine("| (____)|| (____)|| |");
            System.Threading.Thread.Sleep(printDelay);
            Console.WriteLine("|     __)|  _____)| | ____ ");
            System.Threading.Thread.Sleep(printDelay);
            Console.WriteLine("| (\\ (   | (      | | \\_  )");
            System.Threading.Thread.Sleep(printDelay);
            Console.WriteLine("| ) \\ \\__| )      | (___) |");
            System.Threading.Thread.Sleep(printDelay);
            Console.WriteLine("|/   \\__/|/       (_______)");
            System.Threading.Thread.Sleep(printDelay);
            Console.WriteLine("");


        }

        private static void options()
        {
            Console.Clear();
            UI classMenu = new UI();
            classMenu.addLine("Options", ConsoleColor.DarkBlue, ConsoleColor.Green);
            Console.WriteLine("");
            UI.textColour("yellow");
            UI.bgColour("black");  
            Console.WriteLine("What drawing style do you wish to have?");

            UI.textColour("white");
            Console.Write("[");
            UI.textColour("yellow");
            Console.Write("L");
            UI.textColour("white");
            Console.Write("]egacy: ");
            UI.textColour("green");
            Console.WriteLine("Smaller drawings, hand crafted by Matthew");

            UI.textColour("white");
            Console.Write("[");
            UI.textColour("yellow");
            Console.Write("N");
            UI.textColour("white");
            Console.Write("]ew Age: ");
            UI.textColour("green");
            Console.WriteLine("Larger drawings, carefully drawn by Liam");

            if (Console.ReadKey(true).Key == ConsoleKey.L)
            {
                drawType = "l";
                Console.WriteLine("Thank you for choosing Legacy. Press enter to contnue");
                Console.ReadLine();
            }

            if (Console.ReadKey(true).Key == ConsoleKey.N)
            {
                drawType = "n";
                Console.WriteLine("Thank you for choosing New Age. Press enter to contnue");
                Console.ReadLine();
            }
        }
    }
}
