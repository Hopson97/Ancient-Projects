using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Hopson_Realm
{
    class Player
    {
        private static int exitX;
        private static int exitY;

        public static string displayWeapon;
        public static string styleType;

        public static int damage;

        #region Players Variables Definitions
        #region personalisation
        public static string name;
        public static string colour;
        #endregion 
        //Name, colour

        #region Positional Variables
        public static int X;
        public static int Y;
        public static int shownY;
        public static int shownX;
        #endregion
        //Players X and Y positon, including "fake" positions

        #region Health Variables
        public static int health;
        public static int maxHealth;
        #endregion
        //Health and maximum health

        #region Average + Total Levels / exps
        public static double averageLevel;
        public static int totalXP;
        public static int totalLevel;
        #endregion
        //Total level, total Exp and average level

        #region skills
        #region Melee exp
        public static int currMeleeXP;
        public static int nextMeleeXP;
        public static int meleeLevel;
        public static int totalMeleeExp;
        #endregion 
        // Melee levels and exp

        #region Range exp
        public static int currRangeXP;
        public static int nextRangeXP;
        public static int rangeLevel;
        public static int totalRangeExp;
        #endregion
        //Range levels and exp

        #region Magic exp
        public static int currMagicXP;
        public static int nextMagicXP;
        public static int magicLevel;
        public static int totalMagicExp;
        #endregion
        //Range levels and exp
        #endregion
        //where melee, range and magic are declared

        #region weapons
        public static int bow;
        public static int staff;
        public static int sword;
        public static int style;
        #endregion
        #endregion




        public static void init()
        {
            totalXP = 0;
            

            #region Posistional Init
            X = 6;
            Y = 5;
            shownY = 0;
            shownX = 0;
            #endregion

            #region Melee Init
            meleeLevel = 1;
            currMeleeXP = 0;
            nextMeleeXP = 10;
            totalMeleeExp = 0;
            #endregion 

            #region Ranged Init
            rangeLevel = 1;
            currRangeXP = 0;
            nextRangeXP = 10;
            totalRangeExp = 0;
            #endregion

            #region Magic Init
            magicLevel = 1;
            currMagicXP = 0;
            nextMagicXP = 10;
            totalMagicExp = 0;
            #endregion

            #region Average Level Init
            averageLevel = 0.0;

            averageLevel = ((meleeLevel + rangeLevel + magicLevel) / 3);
            #endregion

            totalLevel = magicLevel + meleeLevel + rangeLevel;

            #region Health Init
            maxHealth = (int)averageLevel * 8;
            health = maxHealth;
            #endregion

            #region weapons
            bow = 1;
            staff = 1;
            sword = 1;
            style = 1;
            #endregion

            if (style == 1)
            {
                damage = ((sword+1) * meleeLevel);
            }
            if (style == 2)
            {
                damage = ((bow + 1) * rangeLevel);
            }
            if (style == 3)
            {
                damage = ((staff + 1) * magicLevel);
            }
            
        }

        public static void Input()
        {




            #region Y++ (Moving upwards)
            if (Console.ReadKey(true).Key == ConsoleKey.UpArrow)
            {
               
               if (Map.mapArray[Y-1, X] == ".")
               {
                   Map.mapArray[Y, X] = ".";
                   Y--;
               }
               else if (Map.mapArray[Y - 1, X] == ",")
               {
                   Map.mapArray[Y, X] = ",";
                   Y--;
                   Encounter.EncounterChance(Map.whichMapX, Map.whichMapY, (int)Player.averageLevel);
               }
               else if (Map.mapArray[Y-1, X] == "^")
               {
                   Map.whichMapX++;
                   Y += 7;

               }
               else if (Map.mapArray[Y - 1, X] == "1")
               {

                   exitX = X;
                   exitY = Y;
                   
                   Map.outside = false;
                   //WhereToStand();
                   Y = 7;
                   X = 7;
               }
               else
               {
                   Console.WriteLine("That direction is blocked");
               }
            }
            #endregion
            #region Y-- (Moving downwards)
            if (Console.ReadKey(true).Key == ConsoleKey.DownArrow)
            {
                if (Map.mapArray[Y + 1, X] == ".")
                   {
                       Map.mapArray[Y, X] = ".";
                       Y++;
                   }
                else if (Map.mapArray[Y + 1, X] == ",")
                {
                    Map.mapArray[Y, X] = ",";
                    Y++;
                    Encounter.EncounterChance(Map.whichMapX, Map.whichMapY, (int)Player.averageLevel);
                }
                else if (Map.mapArray[Y + 1, X] == "v")
                {
                    Map.whichMapX++;
                    Y -= 7;

                }
                else if (Map.mapArray[Y + 1, X] == "1")
                {
                    whichDoor();
                }
                else
                {
                    Console.WriteLine("That direction is blocked");
                }
                   

            }
            #endregion    
            #region X++ (Moving right)
            if (Console.ReadKey(true).Key == ConsoleKey.RightArrow)
            {
                if (Map.mapArray[Y, X+1] == ".")
                {
                    Map.mapArray[Y, X] = ".";
                    X++;
                }
                else if (Map.mapArray[Y, X + 1] == ",")
                {
                    Map.mapArray[Y, X] = ",";
                    X++;
                    Encounter.EncounterChance(Map.whichMapX, Map.whichMapY, (int)Player.averageLevel);
                }
                else if (Map.mapArray[Y, X + 1] == ">")
                {
                    Map.whichMapX++;
                    X -= 7;

                }
                else
                {
                    Console.WriteLine("That direction is blocked");
                }

            }
            #endregion    
            #region X-- (Moving left)
            if (Console.ReadKey(true).Key == ConsoleKey.LeftArrow)
            {
                if (Map.mapArray[Y, X - 1] == ".")
                {
                    Map.mapArray[Y, X] = ".";
                    X--;
                }
                else if (Map.mapArray[Y, X - 1] == ",")
                {
                    Map.mapArray[Y, X] = ",";
                    X--;
                    Encounter.EncounterChance(Map.whichMapX, Map.whichMapY, (int)Player.averageLevel);
                }
                else if (Map.mapArray[Y, X - 1] == "<")
                {
                    Map.whichMapX--;
                    X += 7;
                }
                
                else
                {
                    Console.WriteLine("That direction is blocked");
                }

            }
            #endregion                  
            #region switching the Style of attack
            if (Console.ReadKey(true).Key == ConsoleKey.S)
            {
                SwitchWeapon();
            }
            #endregion

        }

        public static void whichDoor()
        {
            #region if inside
            if (!Map.outside)
            {
                X = exitX;
                Y = exitY;
                Map.outside = true;
            }
            #endregion 


        }

        public static void WhereToStand()
        {
            int rowLength = Map.mapArray.GetLength(0);
            int colLength = Map.mapArray.GetLength(1);

            for (int i = 0; i < rowLength; i++)
            {
                for (int j = 0; j < colLength; j++)
                {
                    if (Map.mapArray[i, j] == "1")
                    {
                        X = i;
                        Y = j;
                    }
                }
            }
        }

        public static void whichWeapon()
        {
            Sword.Swords();
            Bow.Bows();
            Staves.Staffs();
        }

        public static void SwitchWeapon()
        {
            if (style != 3)
            {
                style++;
            }
            else
            {
                style = 1;
            }
        }

        public static void statHandler() //Level ups, deaths and shit
        {
            #region level up melee
            if (currMeleeXP >= nextMeleeXP)
            {
                meleeLevel++;
                currMeleeXP = 0;
                nextMeleeXP = nextMeleeXP + (meleeLevel * 2);

            }
            #endregion
            #region level up range
            if (currRangeXP >= nextRangeXP)
            {
                rangeLevel++;
                currRangeXP = 0;
                nextRangeXP = nextRangeXP + (rangeLevel * 2);

            }
            #endregion
            #region level up Magic
            if (currMagicXP >= nextMagicXP)
            {
                magicLevel++;
                currMagicXP = 0;
                nextMagicXP = nextMagicXP + (magicLevel * 2);

            }
            #endregion

            averageLevel = ((meleeLevel + rangeLevel + magicLevel) / 3);
            maxHealth = (int)averageLevel * 8;

            #region damage
            if (style == 1)
            {
                damage = ((sword + 1) * meleeLevel);
            }
            if (style == 2)
            {
                damage = ((bow + 1) * rangeLevel);
            }
            if (style == 3)
            {
                damage = ((staff + 1) * magicLevel);
            }
            #endregion

            if (health <= 0)
            {
                death();
            }
        }

        public static void death()
        {
            Console.Clear();
            GUI.HUDs();
            Console.WriteLine("");
            GUI.TextColour("red");
            Console.WriteLine("You died, fam");
            Console.WriteLine("Press enter to exit");
            Console.ReadLine();
            Environment.Exit(0);

        }
    

    }
}
