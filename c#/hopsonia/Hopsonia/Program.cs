using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Hopsonia
{
    class Program
    {
        static void Main(string[] args)
        {            
            UI ui = new UI();
            ui.textColor("blue");
            ui.drawLogo();
            GameLoop();

            Console.WriteLine("Press enter to exit");
            Console.ReadLine();

        }
        public static void GameLoop()
        {
            bool playing = true;
            UI ui = new UI();
            Map map = new Map();
            Player player = new Player();

            ui.textColor("white");
            player.name = player.askName();
            Console.WriteLine("Hi, {0}... Press enter to play", player.name);
            Console.ReadLine();
            Console.Clear();

            int mapDirection = 0;

            while (playing)
            {

                ui.InfoBar(player.name);
                map.mapLayout();
                map.draw(player.x, player.y, map.map);

                ui.debug(map.x, mapDirection);

                mapDirection = player.input(map.map);
                switch(mapDirection) //1left, 2up, 3right,4down
                {
                    case 1:
                        player.x = 8;
                        map.x--;
                        break;
                    case 2:
                        player.y = 8;
                        map.y++;
                        break;
                    case 3:
                        player.x = 1;
                        map.x++;
                        break;
                    case 4:
                        player.y = 1;
                        map.x--;
                        break;
                        
                }
                Console.Clear();
            }
        }
    }
}
