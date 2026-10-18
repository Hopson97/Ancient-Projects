using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Hopson_RPG
{
    class Maps
    {
        public static bool canGoNorth; //Checks if the player can go in the directin this field specifies.
        public static bool canGoSouth; //Checks if the player can go in the directin this field specifies.
        public static bool canGoWest; //Checks if the player can go in the directin this field specifies.
        public static bool canGoEast; //Checks if the player can go in the directin this field specifies.

        public static bool hasMoved;

        public static bool blockedNorth;
        public static bool blockedSouth;
        public static bool blockedEast;
        public static bool blockedWest;

        public static void Start()
        {
            Player.health = Player.maxHealth;

            Console.WriteLine("####   ####");
            Console.WriteLine("####   ####");
            Console.WriteLine("##   X   ##");
            Console.WriteLine("###########");
            Console.WriteLine("###########");

            canGoNorth = true;
            canGoSouth = false;
            canGoWest = false;
            canGoEast = false;


        } // 1
        public static void westEast()
        {

            Console.WriteLine("###########");
            Console.WriteLine("####   ####");
            Console.WriteLine("     X     ");
            Console.WriteLine("####   ####");
            Console.WriteLine("###########");

            canGoNorth = false;
            canGoSouth = false;
            canGoWest = true;
            canGoEast = true;



        } //2
        public static void northSouth()
        {


            Console.WriteLine("##### #####");
            Console.WriteLine("####   ####");
            Console.WriteLine("#### X ####");
            Console.WriteLine("####   ####");
            Console.WriteLine("##### #####");

            canGoNorth = true;
            canGoSouth = true;
            canGoWest = false;
            canGoEast = false;



        } //3
        public static void northWest()
        {

            Console.WriteLine("####  ####");
            Console.WriteLine("##      ##");
            Console.WriteLine("      X  #");
            Console.WriteLine("##      ##");
            Console.WriteLine("##########");

            canGoNorth = true;
            canGoSouth = false;
            canGoWest = true;
            canGoEast = false;


        }//4
        public static void southEast()
        {
            //Map
            Console.WriteLine("##########");
            Console.WriteLine("##      ##");
            Console.WriteLine("#     X   ");
            Console.WriteLine("##      ##");
            Console.WriteLine("####  ####");

            //Direction bools
            canGoNorth = false;
            canGoSouth = true;
            canGoWest = false;
            canGoEast = true;


        }//5
        public static void northEast()
        {

            Console.WriteLine("####  ####");
            Console.WriteLine("##      ##");
            Console.WriteLine("#     X   ");
            Console.WriteLine("##      ##");
            Console.WriteLine("##########");

            canGoNorth = true;
            canGoSouth = false;
            canGoWest = false;
            canGoEast = true;


        }//6
        public static void southWest()
        {

            Console.WriteLine("##########");
            Console.WriteLine("##      ##");
            Console.WriteLine("      X  #");
            Console.WriteLine("##      ##");
            Console.WriteLine("####  ####");

            canGoNorth = false;
            canGoSouth = true;
            canGoWest = true;
            canGoEast = false;


        }//7
        public static void southEastWest()
        {

            Console.WriteLine("##########");
            Console.WriteLine("##      ##");
            Console.WriteLine("      X   ");
            Console.WriteLine("##      ##");
            Console.WriteLine("####  ####");

            canGoNorth = false;
            canGoSouth = true;
            canGoWest = true;
            canGoEast = true;


        }//8
        public static void northWestSouth()
        {

            Console.WriteLine("####  ####");
            Console.WriteLine("##      ##");
            Console.WriteLine("      X  #");
            Console.WriteLine("##      ##");
            Console.WriteLine("####  ####");

            canGoNorth = true;
            canGoSouth = true;
            canGoWest = true;
            canGoEast = false;


        }//9
        public static void northEastSouth()
        {

            Console.WriteLine("####  ####");
            Console.WriteLine("##      ##");
            Console.WriteLine("#     X   ");
            Console.WriteLine("##      ##");
            Console.WriteLine("####  ####");

            canGoNorth = true;
            canGoSouth = true;
            canGoWest = false;
            canGoEast = true;


        }//10
        public static void northEastWest()
        {

            Console.WriteLine("####  ####");
            Console.WriteLine("##      ##");
            Console.WriteLine("     X    ");
            Console.WriteLine("##########");
            Console.WriteLine("##########");

            canGoNorth = true;
            canGoSouth = false;
            canGoWest = true;
            canGoEast = true;


        }//11
        public static void northEastWestSouth()
        {

            Console.WriteLine("####  ####");
            Console.WriteLine("##      ##");
            Console.WriteLine("     X    ");
            Console.WriteLine("##      ##");
            Console.WriteLine("####  ####");

            canGoNorth = true;
            canGoSouth = true;
            canGoWest = true;
            canGoEast = true;


        }//12
        public static void northDeadEnd()
        {
            Console.WriteLine("###########");
            Console.WriteLine("####   ####");
            Console.WriteLine("#### X ####");
            Console.WriteLine("####   ####");

            canGoNorth = false;
            canGoSouth = true;
            canGoWest = false;
            canGoEast = false;
        }//13, come from south
        public static void westDeadEnd() //14, come from east
        {
            Console.WriteLine("###########");
            Console.WriteLine("###########");
            Console.WriteLine("#  X       ");
            Console.WriteLine("###########");

            canGoNorth = false;
            canGoSouth = false;
            canGoWest = false;
            canGoEast = true;
        }
        public static void eastDeadEnd() //15, come from west
        {
            Console.WriteLine("###########");
            Console.WriteLine("###########");
            Console.WriteLine("        X #");
            Console.WriteLine("###########");

            canGoNorth = false;
            canGoSouth = false;
            canGoWest = true;
            canGoEast = false;
        }
        public static void SouthDeadEnd()
        {
            Console.WriteLine("####   ####");
            Console.WriteLine("####   ####");
            Console.WriteLine("#### X ####");
            Console.WriteLine("###########");

            canGoNorth = true;
            canGoSouth = false;
            canGoWest = false;
            canGoEast = false;
        }//16, come from north

        public void movement()
        {
            ConsoleKeyInfo direction;
            direction = Console.ReadKey();
            
                if (direction.Key == ConsoleKey.UpArrow)
                {
                    if (Maps.canGoNorth == true)
                    {
                        blockedNorth = false;
                        Console.Clear();
                        Console.WriteLine("You go north.");
                        Player.playerY--;
                        hasMoved = true;
                    }
                    else
                    {
                        blockedNorth = true;
                    }
                }
                if (direction.Key == ConsoleKey.DownArrow)
                {
                    if (Maps.canGoSouth == true)
                    {
                        Console.Clear();
                        Console.WriteLine("You go south.");
                        Player.playerY++;
                        hasMoved = true;
                    }
                    else
                    {
                        blockedSouth = true;
                    }
                }
                if (direction.Key == ConsoleKey.LeftArrow)
                {
                    if (Maps.canGoWest == true)
                    {
                        Console.Clear();
                        Console.WriteLine("You go west.");
                        Player.playerX--;
                        hasMoved = true;
                    }
                    else
                    {
                        blockedWest = true;
                    }
                }
                if (direction.Key == ConsoleKey.RightArrow)
                {
                    if (Maps.canGoEast == true)
                    {
                        Console.Clear();
                        Console.WriteLine("You go east.");
                        Player.playerX++;
                        hasMoved = true;
                    }
                    else
                    {
                        blockedEast = true;
                    }
                }

                if (direction.Key == ConsoleKey.Enter)
                {
                    Console.Write("Input Command: ");
                    string command = Console.ReadLine();
                    string[] interpreter = command.Split(' ');
                    if (interpreter[0] == "givexp")
                    {
                        int xp = 0;
                        bool tryNumber = int.TryParse(interpreter[1], out xp);
                        if (tryNumber)
                        {
                            Player.expNow += xp;
                            UI.textColour("green");
                            Console.WriteLine("Given " + xp + " Experience.");
                            UI.textColour("white");
                            Console.WriteLine("Press any key to resume game.");
                            Console.ReadKey();
                        }
                        else
                        {
                            UI.textColour("red");
                            Console.WriteLine("The argument given is not a valid number.");
                            UI.textColour("white");
                            Console.WriteLine("Press any key to resume game.");
                            Console.ReadKey();
                        }
                    }
                    else if (interpreter[0] == "look")
                    {
                        try {
                            if (interpreter[1] == "weapon")
                            {
                                UI.textColour("yellow");
                                Console.WriteLine("This is a " + Weapon.gen.type + " which can deal up to " + Weapon.gen.damage + " damage in a single hit.");
                                UI.textColour("white");
                                Console.Write("Pick up Weapon? ");
                                ConsoleKeyInfo key = new ConsoleKeyInfo();
                                key = Console.ReadKey();
                                if (key.Key == ConsoleKey.Y)
                                {
                                    UI.textColour("green");
                                    Console.WriteLine("Picked up a " + Weapon.gen.type + "!");

                                    ClassInt.weap.damage = Weapon.gen.damage;
                                    ClassInt.weap.type = Weapon.gen.type;
                                    UI.textColour("white");
                                    Console.WriteLine("Press any key to resume game.");
                                    Console.ReadKey();


                                }
                            }
                            else
                            {
                                UI.textColour("red");
                                Console.WriteLine("I do not know what that is.");
                                UI.textColour("white");
                                Console.WriteLine("Press any key to resume game.");
                                Console.ReadKey();

                            }
                        }
                        catch(System.IndexOutOfRangeException ex)
                        {
                            UI.textColour("red");
                            Console.WriteLine("What do you want me to look at?");
                            UI.textColour("white");
                            Console.WriteLine("Press any key to resume game.");
                            Console.ReadKey();
                        }
                    }
                    else if (interpreter[0] == "grab" || interpreter[0] == "get")
                    {
                        try { 
                        if (interpreter[1] == "weapon")
                        {
                            UI.textColour("green");
                            Console.WriteLine("Picked up a " + Weapon.gen.type + "!");

                            ClassInt.weap.damage = Weapon.gen.damage;
                            ClassInt.weap.type = Weapon.gen.type;
                            UI.textColour("white");
                            Console.WriteLine("Press any key to resume game.");
                            Console.ReadKey();
                        } else {
                            UI.textColour("red");
                            Console.WriteLine("I do not know what that is.");
                            UI.textColour("white");
                            Console.WriteLine("Press any key to resume game.");
                            Console.ReadKey();
                        }
                    }
                        catch(System.IndexOutOfRangeException ex)
                        {
                            UI.textColour("red");
                            Console.WriteLine("What do you want me to pick up?");
                            UI.textColour("white");
                            Console.WriteLine("Press any key to resume game.");
                            Console.ReadKey();


                        }
                    }
                    else
                    {
                        UI.textColour("red");
                        Console.WriteLine("Unknown Command. Known commands are look and grab.");
                        UI.textColour("white");
                        Console.WriteLine("Press any key to resume game.");
                        Console.ReadKey();
                    }

                }
            
        }

        public static void whereAmID1()
        {
            
            DungeonMaps map = new DungeonMaps();
            map.maps();

            if (map.mapLayout[Player.playerY, Player.playerX] == 1)
            {

                Start();
            }
            if (map.mapLayout[Player.playerY, Player.playerX] == 2)
            {

                westEast();
            }
            if (map.mapLayout[Player.playerY, Player.playerX] == 3)
            {

                northSouth();
            }
            if (map.mapLayout[Player.playerY, Player.playerX] == 4)
            {

                northWest();
            }
            if (map.mapLayout[Player.playerY, Player.playerX] == 5)
            {

                southEast();
            }
            if (map.mapLayout[Player.playerY, Player.playerX] == 6)
            {

                northEast();
            }
            if (map.mapLayout[Player.playerY, Player.playerX] == 7)
            {

                southWest();
            }
            if (map.mapLayout[Player.playerY, Player.playerX] == 8)
            {

                southEastWest();
            }
            if (map.mapLayout[Player.playerY, Player.playerX] == 9)
            {

                northWestSouth();
            }
            if (map.mapLayout[Player.playerY, Player.playerX] == 10)
            {

                northEastSouth();
            }
            if (map.mapLayout[Player.playerY, Player.playerX] == 11)
            {

                northEastWest();
            }
            if (map.mapLayout[Player.playerY, Player.playerX] == 12)
            {

                northEastWestSouth();
            }
            if (map.mapLayout[Player.playerY, Player.playerX] == 13)
            {

                northDeadEnd();
            }
            if (map.mapLayout[Player.playerY, Player.playerX] == 14)
            {

                westDeadEnd();
            }
            if (map.mapLayout[Player.playerY, Player.playerX] == 15)
            {

                eastDeadEnd();
            }
            if (map.mapLayout[Player.playerY, Player.playerX] == 16)
            {

                SouthDeadEnd();
            }
            
            

        }

        public static void blockPrinter()
        {
            UI.bgColour("black");
            if (Maps.blockedNorth == true)
            {
                Console.WriteLine("North is blocked.");
                Maps.blockedNorth = false;
            }
            if (Maps.blockedSouth == true)
            {
                Console.WriteLine("South is blocked.");
                Maps.blockedSouth = false;
            }
            if (Maps.blockedEast == true)
            {
                Console.WriteLine("East is blocked.");
                Maps.blockedEast = false;
            }
            if (Maps.blockedWest == true)
            {
                Console.WriteLine("West is blocked.");
                Maps.blockedWest = false;
            }
        }
    }   
}
