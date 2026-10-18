using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Hopson_Realm
{
    class Encounter
    {

        public static bool encounterHappening = false;
        public static int foo;

        public static void EncounterChance(int X,int Y, int Level)
        {

            int difficulty = X + Y + (Level / 2);


            Random enc = new Random();
            int encounterHappening = enc.Next(1, 10);

            foo = encounterHappening;

            if (encounterHappening > 8)
            {
                encounterHappening = 0;
                Monster(difficulty);
            }
        }

        //TO CREATE A NEW MONSTER:
        //1 Add a if statement to PUBLIC STATIC VOID MONSTER(int dif){}
        //2 Create a drawing in Draw.cs
        //3 Copy > Paste an enemy method
        //4 Change anything with "change" next to it.
        



        public static void Monster(int dif)
        {
            Draw.encounterAnimation();
            Random whichMonster = new Random();
            int monster = whichMonster.Next(1,dif+1);
            if (monster == 1)
            {
                Rat(dif);
            }
        }

        #region MONSTERS BE HERE
        public static void Rat(int difficulty)
        {

            Draw.Rat(); //Change this for a new monster
            string name = "Rat"; //Change this for a new monster
            Console.WriteLine("");
            Console.WriteLine("{0} has appeared! Press enter to begin fighting it!", name);
            Console.ReadLine();

            int customDifficulty = 1; //Change this if you want enemy to be harder
            int level = levelInit(difficulty, customDifficulty);
            int health = healthInit(level, difficulty);
            int maxHealth = health;

            encounterHappening = true;

            while (encounterHappening)
            {
                GUI.EncounterHUD();
                printEnemyStats(name, level, health, maxHealth);
                Draw.Rat();  //######################################Change this     
                Console.WriteLine("");
                string option = encounterOptions();
                
                #region Attack Chosen (A)
                if (option == "A")
                {
                    Console.Clear();
                    int hit = PlayerAttack1(Player.damage);
                    System.Threading.Thread.Sleep(1000);
                    if (hit == 0)
                    {
                        Console.Clear();
                        Draw.drawType = 1;
                        Draw.Rat(); //##############################Change this
                        Console.WriteLine("...and miss.");
                        System.Threading.Thread.Sleep(1000);
                    }
                    if (hit >= 1)
                    {
                        Console.Clear();
                        Draw.drawType = 2;
                        Draw.Rat();     //##############################Change this
                        System.Threading.Thread.Sleep(200);
                        Console.Clear();
                        Draw.Rat();     //######################################Change this                  
                        Console.WriteLine("and you hit, dealing {0} damage and gaining exp in {1}!", hit, Player.styleType);
                        health -= hit;
                        System.Threading.Thread.Sleep(1250);

                    }
                }
                #endregion 
                 //##########################3 things to change in Attack chosen
                #region Switch Chosen (S)
                else if (option == "S")
                {
                    Console.Clear();
                    Console.WriteLine("You switch weapons!");
                    Player.SwitchWeapon();
                    System.Threading.Thread.Sleep(1000);
                }
                #endregion
                #region Run Chosen (R)
                else if (option == "R")
                {
                    escape();
                }
                #endregion 
                #region else
                else
                {
                    Console.Clear();
                    Console.WriteLine("That is not an option. (Please type 'A', 'S' or 'R')");
                    System.Threading.Thread.Sleep(500);

                }
                #endregion
                Console.Clear();
                enemyDeathCheck(health, name);
                Console.Clear();
                #region Enemy Attack
                int damageEn = enemyAttack(level, name);
                if (damageEn == 0) //miss
                {
                    Console.Clear();
                    Draw.drawType = 1;
                    Draw.Rat(); //##############################Change this
                    Console.WriteLine("And misses.");
                    System.Threading.Thread.Sleep(950);
                }
                if (damageEn > 0) //hit
                {
                    Console.Clear();
                    Draw.drawType = 3;
                    Draw.Rat();     //##############################Change this
                    System.Threading.Thread.Sleep(200);
                    Console.Clear();
                    Draw.Rat();     //######################################Change this  
                    Console.WriteLine("And hits, dealing {0} damage to you!", damageEn);
                    Player.health -= damageEn;
                    System.Threading.Thread.Sleep(950);
                }
                #endregion
                //##########################3 things to change in Attack chosen
                enemyDeathCheck(health, name);
            }


        }
        #endregion 

        #region Encounter Methods
        public static int levelInit(int difficulty, int customDifficulty)
        {
            Random hard = new Random();
            int hardness = hard.Next(difficulty,difficulty*customDifficulty);

            int level = hardness;

            return level;
        }

        public static int healthInit(int level, int x)
        {
            Random healthMod = new Random();
            int healthModValue = healthMod.Next(1, x);
            int health = level * 4 * healthModValue;
            

            return health;
        }

        public static void printEnemyStats(string name, int level, int health, int maxHealth)
        {
            Console.WriteLine("");
            Console.BackgroundColor = ConsoleColor.DarkRed;
            GUI.TextColour("darkGreen");
            Console.Write("ENEMY: {0}",name);
            GUI.TextColour("blue");
            Console.Write("  Level: {0}", level);
            GUI.TextColour("green");
            Console.Write("  {0}/{1} Health", health, maxHealth);

            Console.Write(new String(' ', Console.BufferWidth - Console.CursorLeft));

            Console.BackgroundColor = ConsoleColor.Black;
            GUI.TextColour("white");
            Console.WriteLine("");
        }
        
        public static int PlayerAttack1(int damage)
        {        
            Random hit = new Random();
            int didHeMiss = hit.Next(0, damage+1);

            int gains = didHeMiss * 3;

            #region Style: Melee
            if (Player.style == 1)
            {
                Console.WriteLine("You swing your {0}...", Player.displayWeapon);
                Player.currMeleeXP += gains;
                Player.totalMeleeExp += gains;
            }
            #endregion
            #region Style: Range
            else if (Player.style == 2)
            {
                Console.WriteLine("You fire your {0}...", Player.displayWeapon);
                Player.currRangeXP += gains;
                Player.totalRangeExp += gains;
                
            }
            #endregion
            #region Style: Magic
            else if (Player.style == 3)
            {
                Console.WriteLine("You cast a spell from your {0}...", Player.displayWeapon);
                Player.currMagicXP += gains;
                Player.totalMagicExp += gains;
                
            }
            #endregion 

            return didHeMiss;
            
        }

        public static string encounterOptions()
        {
            Console.Write("What will you do? ");
            GUI.TextColour("red");
            Console.Write("[A]");
            GUI.TextColour("darkRed");
            Console.Write("ttack");
            GUI.TextColour("white");
            Console.Write(", ");
            GUI.TextColour("blue");
            Console.Write("[S]");
            GUI.TextColour("darkBlue");
            Console.Write("itch");
            GUI.TextColour("white");
            Console.Write(", or ");
            GUI.TextColour("green");
            Console.Write("[R]");
            GUI.TextColour("darkGreen");
            Console.Write("un");
            GUI.TextColour("white");
            Console.Write("?");

            string option = Console.ReadLine();

            return option;
        }

        public static int enemyAttack(int level, string name)
        {
            Random damagee = new Random();
            int hit = damagee.Next(0, (level * 2));

            Console.WriteLine("The {0} attacks!", name);
            System.Threading.Thread.Sleep(950);

            return hit;
            
        }

        public static void enemyDeathCheck(int health, string name)        
        {
            if (health <= 0)
            {
                Console.Clear();
                Console.WriteLine("You killed the {0}.", name);
                System.Threading.Thread.Sleep(1000);
                Console.Clear();
                encounterHappening = false;
                GameLoop.TheLoop();
            }
        }

        public static void escape()
        {
            Console.Clear();
            Random escape = new Random();
            Console.WriteLine("You attempt to escape...");

            int escaped = escape.Next(1, 10);
            if (escaped > 5)
            {
                System.Threading.Thread.Sleep(1000);
                Console.WriteLine("You escape!");
                System.Threading.Thread.Sleep(1000);
                Console.Clear();
                encounterHappening = false;
                GameLoop.TheLoop();

            }
            else
            {
                System.Threading.Thread.Sleep(1000);
                Console.WriteLine("You fail to escape!");
                System.Threading.Thread.Sleep(1000);
                Console.Clear();

            }
        }
        #endregion
    }
}
