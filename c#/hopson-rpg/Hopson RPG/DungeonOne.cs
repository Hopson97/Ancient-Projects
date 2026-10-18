using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Hopson_RPG
{
    class DungeonOne
    {
       private static Maps map = new Maps();

        public static int weaponFind = 0;
        public static Weapon gen = new Weapon();

        public static void dungOneInit()
        {
            Console.Clear();
            ClassInt.setupStarterItems();

            while (Program.dungeon == 1)
            {

                UI.dungeonInstructions();
                map.movement();
                BossCheck();

                System.Threading.Thread.Sleep(50);
                if (Maps.hasMoved)
                {
                    Console.WriteLine("You find yourself in a new room");
                    Encounter enc = new Encounter();
                    enc.encounter(Program.dungeon + 1); //Change for difficulty of monsters in dungeon, higher number means more higher level monsters appear.
                    
                    

                    Maps.hasMoved = false;
                }
                
                

            }
            
        }
        public static void BossCheck()
        {
            if (Player.level > 3)
            {
                Random r = new Random();
                int bossChance = r.Next(1, 20);
                if (bossChance == 1)
                {
                    Encounter enc = new Encounter();
                    enc.bossOne(Program.dungeon); //Change the "bossNUMBER" ok
                }
            }
        }

        

    } //The start of the dungeon, and the map of dungeon one
}
