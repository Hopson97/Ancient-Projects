using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Hopson_RPG
{
    class DungeonThree
    {
        private static Maps map = new Maps();

        public static int weaponFind = 0;
        public static Weapon gen = new Weapon();

        public static void dungThreeInit() //Change this (Dung###Init();)
        {
            Console.Clear();
            Player.playerX = 4; //Change according to wherever the dugneon starts
            Player.playerY = 4; //Chnage according to wherever the dungeon starts
            while (Program.dungeon == 3) //Change this (Number)
            {
                UI.dungeonInstructions();
                map.movement();

                BossCheck();

                System.Threading.Thread.Sleep(50);
                if (Maps.hasMoved)
                {
                    Console.WriteLine("You find yourself in a new room");
                    Encounter enc = new Encounter();
                    enc.encounter(Program.dungeon + 2); //Change for difficulty of monsters in dungeon, higher number means more higher level monsters appear.
                    Maps.hasMoved = false;
                }

            }

        }
        public static void BossCheck()
        {
            if (Player.level > Program.dungeon * 4) //Change this, if you want the player to have to be a higher level when he finds the boss
            {
                Random r = new Random();
                int bossChance = r.Next(1, 20);
                if (bossChance == 1)
                {
                    Encounter enc = new Encounter();
                    enc.bossOne(Program.dungeon); //Change this (Encounter.boss###(Program.dungeon);)
                }
            }
        }
    }
}
