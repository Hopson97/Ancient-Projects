using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Hopson_RPG
{
    class Draw
    {
        public static void animate()
        {
            
        }

        //MONSTERS:
        private void templateGeneric()
        {
           
            Console.WriteLine(" ____________________");
            Console.WriteLine("|                    |");
            Console.WriteLine("|                    |");
            Console.WriteLine("|                    |");
            Console.WriteLine("|                    |");
            Console.WriteLine("|                    |");
            Console.WriteLine("|                    |");
            Console.WriteLine("|____________________|");
            Console.WriteLine("");
        }

        private void templateBoss()
        {
            Console.WriteLine(" __________________________");
            Console.WriteLine("|                          |");
            Console.WriteLine("|                          |");
            Console.WriteLine("|                          |");
            Console.WriteLine("|                          |");
            Console.WriteLine("|                          |");
            Console.WriteLine("|                          |");
            Console.WriteLine("|                          |");
            Console.WriteLine("|                          |");
            Console.WriteLine("|                          |");
            Console.WriteLine("|__________________________|");
            Console.WriteLine("");
        }
        
        //generic monsters
        public static void bat()
        {
            if (Program.drawType == "n")
            {
                Console.WriteLine("                                    ....");
                Console.WriteLine("                                 ..`!!!..");
                Console.WriteLine("                               ..!!! `!!!..");
                Console.WriteLine("                             .!!!     `,!!.");
                Console.WriteLine("     ,!..                    ``!        ;!!.");
                Console.WriteLine("     ;!`!..            ....  ;!!.       ;!!.    ,!.             ..,!.");
                Console.WriteLine("     ;!; ``..       ,.!  `!. ,!!        ;!!.  ,,!`!!.        ,.!!!!!;");
                Console.WriteLine("     ;!;   ``.. ..,        `!,!!;       ;!!..,!    `!..   ,.!!    !!;");
                Console.WriteLine("     ;!;     `,             `,!!;       ;!!.!!      `!!,.!!       !!;");
                Console.WriteLine("     ;!;        `.           `!          ``!          `!|         !!");
                Console.WriteLine("     ;!;                        p.        ,.           ,         ;!!");
                Console.WriteLine("     ,!                        |  ..   _,  |                     ;!!");
                Console.WriteLine("     ,!            _           |___:> |.  ,|                     ;!!");
                Console.WriteLine("     ,!          ,                      -                        ;!!");
                Console.WriteLine("     ,!         ,              ...        ...            .       ;!!");
                Console.WriteLine("     ,!      ,.` .           ,!!!!       ,`!.                    ;!!");
                Console.WriteLine("     ,!   ..!    `!.        ,! `!!;     ,!!`!.            . .    ;!!");
                Console.WriteLine("     ,! ,,         `!.    ,,   ,!!;     ,!! `!.         ,.!! .   ;!!");
                Console.WriteLine("     `.!            ``.. ,!    ;!!.    ,!!!  `!.      ,,!   `!!  ,!");
                Console.WriteLine("                      ``,      ;!!.    ,!!    `!.   ,,!      `!!.,!.");
                Console.WriteLine("                                .!..  ,!!!     `!.,,!          `!.!.");
                Console.WriteLine("                                `!!!..``!       `!.             `!..");
                Console.WriteLine("                                 ...,!.          `               `!");
                Console.WriteLine("                               ,.!!  `!!.");
                Console.WriteLine("                               `!!.   ....");
                Console.WriteLine("                                 `!.,,!!");
                Console.WriteLine("                                  ` `");
            }
            if (Program.drawType == "l")
            {
                Console.WriteLine(" ____________________");
                Console.WriteLine("|     |'|____|'|     |");
                Console.WriteLine("| ,--_| (o)(o) |_--, |");
                Console.WriteLine("| |__ |  ____  | __| |");
                Console.WriteLine("|   \\_|   v-v  |_/   |");
                Console.WriteLine("|      \\      /      |");
                Console.WriteLine("|       \\ __ /       |");
                Console.WriteLine("|____________________|");
                Console.WriteLine("");
            }
        }

        public static void slime()
        {
            if (Program.drawType == "n")
            {
                Console.WriteLine("                            00000000.");
                Console.WriteLine("                    ,0XXPPPPPPXXXXXX80.");
                Console.WriteLine("               , XXP                  ` XX8.");
                Console.WriteLine("           ,XXP                            9XX.");
                Console.WriteLine("          XP                                 `XX");
                Console.WriteLine("         XP       ,0XX         X80            `XX");
                Console.WriteLine("        XXP     , XXXX.     ,XXP9X8            `XX.");
                Console.WriteLine("       ,XX      XX  9X8     XX   X8             9X8");
                Console.WriteLine("       XXP   , XP    XX    XX    X8              XX8");
                Console.WriteLine("       XP     XP     XX    XX    X8              9XX");
                Console.WriteLine("      XP     XXP     XX    XX    X8               XX");
                Console.WriteLine("    ,XX      XX      XP    XX   XXP               9X8");
                Console.WriteLine("     XP      9X8000XXP    9XX800XX                 X8");
                Console.WriteLine("    XX        9PPPPP        `9XXX                  X8");
                Console.WriteLine("  XX                                              X8");
                Console.WriteLine("  XX                                               XX");
                Console.WriteLine("  X8          9XXXXX000                            XX");
                Console.WriteLine(",XX           XXP  ` PXX.                          XX");
                Console.WriteLine("XXP         XXF       `XX.                         XP");
                Console.WriteLine("XX          XX80       XX                          X8");
                Console.WriteLine(",XX            `PXXXX0XXXXP                        ,XX");
                Console.WriteLine(",XX                 `                                XP");
                Console.WriteLine("0XXXXXXXXXX000000XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXP");
                Console.WriteLine("`PP       `                         `");
            }
            if (Program.drawType == "l")
            {
                Console.WriteLine(" ____________________");
                Console.WriteLine("|       __    /  . , |");
                Console.WriteLine("|      /  \\_/  '     |");
                Console.WriteLine("|     /_  _\\  , '    |");
                Console.WriteLine("| 3--|       |---E  /|");
                Console.WriteLine("|   /   --    \\,  / |");
                Console.WriteLine("|  |,_,_,_,_,_,_\\/   |");
                Console.WriteLine("|____________________|");
                Console.WriteLine("");
            }

        }

        public static void ghoul()
        {
            Console.WriteLine(" ____________________");
            Console.WriteLine("|      _/v\\ _        |");
            Console.WriteLine("|     | o o  |       |");
            Console.WriteLine("|     \\  ;   /      |");
            Console.WriteLine("|   .    _        .  |");
            Console.WriteLine("|        \\  |        |");
            Console.WriteLine("|  .   '    ,     .  |");
            Console.WriteLine("|_______\\__\\_\\_______|");
            Console.WriteLine("");
        }

        //boss monsters
        public static void bossOne() //"The neck"
        {
            if (Program.drawType == "l")
            {
                Console.WriteLine(" __________________________");
                Console.WriteLine("|            /  v |        |");
                Console.WriteLine("|            | * */        |");
                Console.WriteLine("|      ______/ O_/         |");
                Console.WriteLine("|     / _______/           |");
                Console.WriteLine("|    / /    ____           |");
                Console.WriteLine("|    | |   /  _ \\          |");
                Console.WriteLine("|    | |  /  / \\ \\         |");
                Console.WriteLine("|    \\ \\_/  /__/  |        |");
                Console.WriteLine("|     \\__|  |____ /        |");
                Console.WriteLine("|________|__|______________|");
                Console.WriteLine("");
            }
        }

        public static void bossTwo() //"Crystal"
        {
            if (Program.drawType == "l")
            {
                Console.WriteLine(" __________________________");
                Console.WriteLine("|      _   ______   _      |");
                Console.WriteLine("|     /O\\ / \\  / \\/ O\\     |");
                Console.WriteLine("|     \\  /   \\/   \\  /     |");
                Console.WriteLine("|      \\/--__/\\__--\\/      |");
                Console.WriteLine("|       \\  /\\--/\\  /       |");
                Console.WriteLine("|        \\/  \\/  \\/        |");
                Console.WriteLine("|         \\  /\\  /         |");
                Console.WriteLine("|          \\/  \\/          |");
                Console.WriteLine("|           \\  /           |");
                Console.WriteLine("|____________\\/____________|");
                Console.WriteLine("");
            }
            
        }
    }
}

