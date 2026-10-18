using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Hopson_Realm
{
    class Bow
    {
        

        public static void Bows()
        {
            if (Player.style == 2)
            {
                Player.styleType = "Range";

                if (Player.bow == 1)
                {
                    
                    Player.displayWeapon = "Wooden Bow";
                }
            }
        }
    }
}
