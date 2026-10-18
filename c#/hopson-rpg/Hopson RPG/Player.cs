using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Hopson_RPG
{
    class Player
    {
        public static string playerName; //The name the player

        public static int playerX; // Position of the player 
        public static int playerY; // in the current dungeon

        public static int expNow; //Current Exp
        public static int expNext; //The exp needed to level up
        public static int level; //What level the player is.

        public static int health; // Current health of the player
        public static int maxHealth; //The maximum potential health the player can be

        public static int weapon = 1; //which weapon the player is using.
        public static int armour; //which armour the player is wearing.

        public static string RealWeapon; //The NAME of the weapon.
        public static string RealArmour; //The NAME of the armour.

        public static void statHandler()
        {
            maxHealth = level * 10;
            if (expNow >= expNext)
            {
                level++;
                expNext = (level * 2) + (expNext) + (3);
            }
            if (health <= 0)
            {
                death();
            }

            
                
            //WEAPON TYPES
            




        } //Loop to handle the stats of the player

        public static void currentStats()
        {
            UI HUD = new UI();
            HUD.initUI(health, playerName, level, playerX, playerY);
            HUD.updateUI();
            
        }

        public static void death()
        {
            UI.textColour("red");
            Console.Clear();
            currentStats();
            Console.WriteLine("You have died. Sad times.");
            
            UI.textColour("red");
            Console.WriteLine("Press enter to exit");
            Console.ReadLine();
            Environment.Exit(0);


        } //When the player dies, press 'F' to pay resepcts.
    }

}
