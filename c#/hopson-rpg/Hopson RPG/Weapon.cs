using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Hopson_RPG
{
    class Weapon
    {

        //Weapon Management Class

        public string type;
        public int damage;
        public string enchantment;
        public int missChance;
        public string[] name1 = {"Wooden","Iron", "Cookie", "Electric","Sharp","Orange","Resonant", "Shadow"};
        public string[] name2 = { "Shortsword", "Mace", "Longsword", "Dagger", "Claymore", "Flail"};

        

        public static Weapon gen = new Weapon();
                               

        public int dealDamage(int maxDamage)
        {
            Random dmg = new Random();
            int damage = dmg.Next(1, maxDamage + 1);

            Random missed = new Random();
            int miss = missed.Next(0, missChance);

            if (miss > 0)
            {
                return 0;
            }
            else
            {
                return damage;
            }
        }

        public static string genName()
        {
            Random name = new Random();
            Weapon sys = new Weapon();

            int partone = name.Next(0, sys.name1.Length);
            int parttwo = name.Next(0, sys.name2.Length);

            string fullName = (sys.name1[partone] + " " + sys.name2[parttwo]);

            return fullName;

        }

        public static void generateWeapon()
        {
            
                Random genDamage = new Random();
                gen.damage = genDamage.Next(1, Player.level * 3);
                gen.type = Weapon.genName();
            
        }

    }
}
