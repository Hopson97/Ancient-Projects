using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Hopson_Realm
{
    class Sword
    {
        public static void Swords()
        {
            if (Player.style == 1)
            {
                Player.styleType = "Melee";

                if (Player.sword == 1)
                {
                    
                    Player.displayWeapon = "Wooden Sword";
                }
            }
        }
    }
}
