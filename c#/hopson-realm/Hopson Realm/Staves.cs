using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Hopson_Realm
{
    class Staves
    {
        
        public static void Staffs()
        {
            if (Player.style == 3)
            {
                Player.styleType = "Magic";

                if (Player.staff == 1)
                {
                    
                    Player.displayWeapon = "Wooden Stick";
                }
            }
        }
    }
}
