using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Hopson_Realm
{
    class GameLoop
    {
        private static bool init = false;

        public static void TheLoop()
        {
            if (!init)
            {
                Map.mapInit();
                init = true;
            }
            

            while (true)
            {
                Player.whichWeapon();
                Player.statHandler();
                GUI.HUDs();
                Map.maps();
                Map.printArray();
                GUI.mapInstruction();
                GUI.OtherActions();
                GUI.Debug();
                Player.Input(); //Pause, for player movement. MUST BE AT BOTTOM.

               
            }
        }


    }
}
