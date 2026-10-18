using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Hopson_RPG
{
    class Encounter //To handle the encounters and different monster types.
    {

        public bool encounterHappening = false;


        public static void encounterAnimation()
        {
            Console.Clear();
            short delay = 30;
            Random animate = new Random();
            for (int i = 0; i < 23; i++)
            {
                int lineType = animate.Next(1, 6);
                if (lineType == 1)
                {
                    UI.bgColour("red");
                    Console.Write(new String(' ', Console.BufferWidth - Console.CursorLeft));
                    System.Threading.Thread.Sleep(delay);
                }
                if (lineType == 2)
                {
                    UI.bgColour("blue");
                    Console.Write(new String(' ', Console.BufferWidth - Console.CursorLeft));
                    System.Threading.Thread.Sleep(delay);
                }
                if (lineType == 3)
                {
                    UI.bgColour("green");
                    Console.Write(new String(' ', Console.BufferWidth - Console.CursorLeft));
                    System.Threading.Thread.Sleep(delay);
                }
                if (lineType == 4)
                {
                    UI.bgColour("yellow");
                    Console.Write(new String(' ', Console.BufferWidth - Console.CursorLeft));
                    System.Threading.Thread.Sleep(delay);
                }
                if (lineType == 5)
                {
                    UI.bgColour("white");
                    Console.Write(new String(' ', Console.BufferWidth - Console.CursorLeft));
                    System.Threading.Thread.Sleep(delay);
                }

            }
            System.Threading.Thread.Sleep(250);
            UI.bgColour("black");
            Console.Clear();
        }


        public void encounter(int x)
        {
            Random encounterChance = new Random();
            int encountered = encounterChance.Next(1, 4);

            if (encountered == 1)
            {
                encounterAnimation();
                Random monsr = new Random();
                int monsterType = monsr.Next(1, x+1);

                if (monsterType == 1)
                {
                    bat(x);
                }
                if (monsterType == 2)
                {
                    slime(x);
                }
                if (monsterType == 3)
                {
                    ghoul(x);
                }
            }

        }

       
        // Generic Monsters
        public void bat(int hard) //CHANGE THIS
        {

            Draw.bat(); //CHANGE THIS
            string name = "Bat"; //CHANGE THIS
            int myHardness = encounterInit("Bat", hard); //CHANGE THIS

            short Level = (short)myHardness;
            int Health = myHardness * 3; //CHANGE THIS
            int MaxHealth = Health;
            Random Loot = new Random();
            int Exp = Loot.Next(myHardness + 1, myHardness * 2);//CHANGE THIS

            encounterHappening = true;

            while (encounterHappening) 
            {
                Console.Clear();
                Player.statHandler();
                Player.currentStats();
                UI.bgColour("black");
                enemyStats(name, Level, Health, MaxHealth);
                Draw.bat(); //CHANGE THIS
                encounterHappening = enemyDeathCheck(Health, name, Exp);
                if (encounterHappening == false)
                {
                    Console.Clear();
                }

                string option = encounterOptions();
                if (option == "1")//attack
                {
                    int damage = attackChosen();
                    Health = Health - damage;
                    if (Health > 0)
                    {
                        int hitByEnemy = enemyAttack((short)myHardness, name);
                        Player.health = Player.health - hitByEnemy;
                    }
                }
                if (option == "2")//Run
                {
                    encounterHappening = false;
                    Console.Clear();
                }
                else
                {
                    Console.WriteLine("That is not an option");
                } 
            }
            Console.Clear();
        }

        public void slime(int hard) //CHANGE THIS
        {
            Draw.slime(); //CHANGE THIS
            string name = "Slime"; //CHANGE THIS
            int myHardness = encounterInit("Slime", hard);

            short Level = (short)myHardness;
            int Health = myHardness * 5; //CHANGE THIS
            int MaxHealth = Health;
            Random Loot = new Random();
            int Exp = Loot.Next(myHardness + 1, myHardness * 2); //CHANGE THIS

            encounterHappening = true;

            while (encounterHappening)
            {
                Console.Clear();
                Player.statHandler();
                Player.currentStats();
                UI.bgColour("black");
                enemyStats(name, Level, Health, MaxHealth);
                Draw.slime(); //CHANGE THIS
                encounterHappening = enemyDeathCheck(Health, name, Exp);
                if (encounterHappening == false)
                {
                    Console.Clear();
                }

                string option = encounterOptions();
                if (option == "1")//attack
                {
                    int damage = attackChosen();
                    Health = Health - damage;
                    if (Health > 0)
                    {
                        int hitByEnemy = enemyAttack((short)myHardness, name);
                        Player.health = Player.health - hitByEnemy;
                    }
                }
                if (option == "2")//Run
                {
                    encounterHappening = false;
                    Console.Clear();
                }
                else
                {
                    Console.WriteLine("That is not an option");
                }
            }
            Console.Clear();
        }

        public void ghoul(int hard) //CHANGE THIS
        {
            Draw.ghoul(); //CHANGE THIS
            string name = "Ghoul"; //CHANGE THIS
            int myHardness = encounterInit("Ghoul", hard);

            short Level = (short)myHardness;
            int Health = myHardness * 5; //CHANGE THIS
            int MaxHealth = Health;
            Random Loot = new Random();
            int Exp = Loot.Next(myHardness + 1, myHardness * 3); //CHANGE THIS

            encounterHappening = true;

            while (encounterHappening)
            {
                Console.Clear();
                Player.statHandler();
                Player.currentStats();
                UI.bgColour("black");
                enemyStats(name, Level, Health, MaxHealth);
                Draw.ghoul(); //CHANGE THIS
                encounterHappening = enemyDeathCheck(Health, name, Exp);
                if (encounterHappening == false)
                {
                    Console.Clear();
                }

                string option = encounterOptions();
                if (option == "1")//attack
                {
                    int damage = attackChosen();
                    Health = Health - damage;
                    if (Health > 0)
                    {
                        int hitByEnemy = enemyAttack((short)myHardness, name);
                        Player.health = Player.health - hitByEnemy;
                    }
                }
                if (option == "2")//Run
                {
                    encounterHappening = false;
                    Console.Clear();
                }
                else
                {
                    Console.WriteLine("That is not an option");
                }
            }
            Console.Clear();
        }

        //Boss Monsters
        public void bossOne(int hard) //CHANGE THIS
        {
            encounterAnimation();
            Draw.bossOne(); //CHANGE THIS
            string name = "The Neck"; //CHANGE THIS
            int myHardness = (encounterInit("Boss One; The Neck", hard))+2; //CHANGE THIS

            short Level = (short)myHardness;
            int Health = myHardness * 6; //CHANGE THIS
            int MaxHealth = Health;
            Random Loot = new Random();
            int Exp = Loot.Next(myHardness + 3, myHardness * 6); //CHANGE THIS

            encounterHappening = true;

            while (encounterHappening)
            {
                Console.Clear();
                Player.statHandler();
                Player.currentStats();
                UI.bgColour("black");
                enemyStats(name, Level, Health, MaxHealth);
                Draw.bossOne(); //CHANGE THIS
                encounterHappening = bossDeathCheck(Health, name, Exp);


                string option = encounterOptions();
                if (option == "1")//attack
                {
                    int damage = attackChosen();
                    Health = Health - damage;
                    if (Health > 0)
                    {
                        int hitByEnemy = enemyAttack((short)myHardness, name);
                        Player.health = Player.health - hitByEnemy;
                    }
                }
                if (option == "2")//Run
                {
                    Console.WriteLine("One can not run from a boss fight!");
                    Console.Clear();
                }
                else
                {
                    Console.WriteLine("That is not an option");
                }
            }
            Console.Clear();
        }

        public void bossTwo(int hard) //CHANGE THIS
        {
            encounterAnimation();
            Draw.bossTwo(); //CHANGE THIS
            string name = "The Crystal"; //CHANGE THIS
            int myHardness = (encounterInit("Boss Two; The Crystal", hard)) + 2; //CHANGE THIS

            short Level = (short)myHardness;
            int Health = myHardness * 6; //CHANGE THIS
            int MaxHealth = Health;
            Random Loot = new Random();
            int Exp = Loot.Next(myHardness + 3, myHardness * 6); //CHANGE THIS

            encounterHappening = true;

            while (encounterHappening)
            {
                Console.Clear();
                Player.statHandler();
                Player.currentStats();
                UI.bgColour("black");
                enemyStats(name, Level, Health, MaxHealth);
                Draw.bossTwo(); //CHANGE THIS
                encounterHappening = bossDeathCheck(Health, name, Exp);


                string option = encounterOptions();
                if (option == "1")//attack
                {
                    int damage = attackChosen();
                    Health = Health - damage;
                    if (Health > 0)
                    {
                        int hitByEnemy = enemyAttack((short)myHardness, name);
                        Player.health = Player.health - hitByEnemy;
                    }
                }
                if (option == "2")//Run
                {
                    Console.WriteLine("One can not run from a boss fight!");
                    Console.Clear();
                }
                else
                {
                    Console.WriteLine("That is not an option");
                }
            }
            Console.Clear();
        }



        //NO MORE MONSTERS BEHIND THESE CURTAINS 

        public int encounterInit(string name, int hard)
        {
           
            Console.WriteLine(name + " has appeared!");
            Console.WriteLine("Press enter to continue");
            Console.ReadLine();
            Console.Clear();
            

            Random hardDeterminer = new Random();
            int myHardness = hardDeterminer.Next(1, hard);

            return myHardness;
        }


        public string encounterOptions()
        {
            string enctrOption = "";
            
            if (encounterHappening)
            {
                Console.WriteLine("What will you do?");
                Console.WriteLine("1. Attack");
                Console.WriteLine("2. Run");
               enctrOption = Console.ReadLine();
            }
            else
            {
                enctrOption = "";
            }
            return enctrOption;

        }

        public int attackChosen()
        {


            int damage = ClassInt.weap.dealDamage(ClassInt.weap.damage * Player.level);

            if (Program.playerClass == "warrior")
            {
                if (damage == 0)
                {
                    UI.textColour("red");
                    Console.WriteLine("You swing your " + ClassInt.weap.type + " and miss!");
                    UI.textColour("white");
                }
                if (damage > 0)
                {
                    UI.textColour("green");
                    Console.WriteLine("You swing your " + ClassInt.weap.type + " and deal " + damage + " damage with your " + ClassInt.weap.type + "!");
                    UI.textColour("white");
                }
            }
            if (Program.playerClass == "archer")
            {
                if (damage == 0)
                {
                    UI.textColour("red");
                    Console.WriteLine("You fire your " + ClassInt.weap.type + " and miss!");
                    UI.textColour("white");
                }
                if (damage > 0)
                {
                    UI.textColour("green");
                    Console.WriteLine("You fire your " + ClassInt.weap.type + " and deal " + damage + " damage with your " + ClassInt.weap.type + "!");
                    UI.textColour("white");
                }
            }
            return damage;
        }

        public static int enemyAttack(int damage, string name)
        {
            Console.WriteLine("");
            Random attack = new Random();
           
            int enemyDamage = attack.Next(0, damage);
            if (damage == 0)
            {
                UI.textColour("red");
                Console.WriteLine(name + " tried to attack, and missed!");
                UI.textColour("white");
            }
            if (damage > 0)
            {
                UI.textColour("green");
                Console.WriteLine(name + " has a successful hit and deals " + damage + " damage!");
                UI.textColour("white");
            }
            Console.WriteLine("Press enter to continue");
            Console.ReadLine();
            return damage;
        }

        public static void enemyStats(string name, short level, int health, int maxHealth)
        {
            UI stats = new UI();
            stats.addLine("  " + name + "    Level " + level + "    HP : " + health + "/" + maxHealth, ConsoleColor.DarkCyan, ConsoleColor.Black);
            UI.bgColour("black");
            UI.textColour("white");
           
        }

        public bool enemyDeathCheck(int enemyHealth, string name, int exp)
        {
            bool living = true;

            if (enemyHealth <= 0)
            {
                Console.WriteLine(name + " has died! You gained " + (exp * 2) + " experience points!");
                Player.expNow = Player.expNow + (exp*2);
                Console.WriteLine("Press any key to continue.");
                Console.ReadKey();
                living = false;
                encounterHappening = false;   
            }
            return living;
        }

        public bool bossDeathCheck(int enemyHealth, string name, int exp)
        {
            bool living = true;

            if (enemyHealth <= 0)
            {
                Console.WriteLine(name + " has died! You gained " + (exp * 3) + " experience points!");
                Player.expNow = Player.expNow + (exp*3);
                Console.WriteLine("Press enter to enter the next dungeon");
                Console.ReadLine();
                Program.dungeon++;
                if (Program.dungeon == 2)
                {
                    DungeonTwo.dungTwoInit();
                }
                encounterHappening = false;
                living = false;
                

            }
            return living;
        }
    }
    
}
