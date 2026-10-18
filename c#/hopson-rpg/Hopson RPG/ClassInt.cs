using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Hopson_RPG
{
    class ClassInt
    {

        public static Weapon weap = new Weapon();

        public static void setupStarterItems()
        {
            if (Program.playerClass == "warrior")
            {
                weap.damage = 4 * Player.level;
                weap.type = "Wooden Sword";
                weap.enchantment = "None";
                weap.missChance = 2;
            }

            if (Program.playerClass == "archer")
            {
                weap.damage = 2 * Player.level;
                weap.type = "Wooden Bow";
                weap.enchantment = "None";
                weap.missChance = 4;
            }
        }
    }
}
