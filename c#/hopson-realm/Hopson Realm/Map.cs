using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Hopson_Realm
{
    class Map
    {

        public static bool outside;

        public static string[,] mapArray;

        public static int whichMapX;
        public static int whichMapY;

        public static void MapColour(int i, int j)
        {
            #region floor/walls
            if (mapArray[i,j] == "#")
            {
                GUI.TextColour("darkRed");
            }
            if (mapArray[i, j] == "~")
            {
                GUI.TextColour("blue");
            }
            if (mapArray[i, j] == ".")
            {
                if (outside)
                {
                    GUI.TextColour("green");
                }
                if (!outside)
                {
                    GUI.TextColour("white");
                }

            }
            if (mapArray[i, j] == ",")
            {
                GUI.TextColour("darkGreen");
            }
            #endregion

            #region buildings
            if (mapArray[i, j] == "|")
            {
                GUI.TextColour("white");
            }
            if (mapArray[i, j] == "_")
            {
                GUI.TextColour("white");
            }
            if (mapArray[i, j] == "\\")
            {
                GUI.TextColour("white");
            }
            if (mapArray[i, j] == "/")
            {
                GUI.TextColour("white");
            }
            if (mapArray[i, j] == "o")
            {
                GUI.TextColour("cyan");
            }
            #endregion

            #region portals/doors
            if (mapArray[i, j] == ">")
            {
                GUI.TextColour("red");
            }
            if (mapArray[i, j] == "<")
            {
                GUI.TextColour("red");
            }
            if (mapArray[i, j] == "v")
            {
                GUI.TextColour("red");
            }
            if (mapArray[i, j] == "^")
            {
                GUI.TextColour("red");
            }
            if (mapArray[i, j] == ">")
            {
                GUI.TextColour("red");
            }
            if (mapArray[i, j] == "1")
            {
                GUI.TextColour("red");
            }
            #endregion
        }

        public static void printArray()
        {
            Console.Write(Environment.NewLine);

            GUI.TextColour("green");
            maps();
            int rowLength = mapArray.GetLength(0);
            int colLength = mapArray.GetLength(1);

            for (int i = 0; i < rowLength; i++)
            {
                for (int j = 0; j < colLength; j++)
                {
                    PlayerLocationCheck(i, j);
                    MapColour(i, j);
                    Console.Write(string.Format("{0} ", mapArray[i, j]));
                }
                Console.Write(Environment.NewLine);
            }
        }

        public static void PlayerLocationCheck(int i, int j)
        {
            GUI.TextColour(Player.colour);
            mapArray[Player.Y, Player.X] = "@";
            
        }

        public static void mapInit()
        {
            outside = true;
            whichMapY = 0; //temp
            whichMapX = 0; //temp
        }


        public static void maps()
        {
            #region Outside Maps
            if (outside)
            {
                #region Y=0;
                if (whichMapY == 0)
                {

                    #region Y:0, X:0
                    if (whichMapX == 0) //Y: 0, X: 0 , outside
                    {
                        mapArray = new string[10, 10]
                        {
                            {"#","#","#","#","#","#","#","#","#","#"},
                            {"#",".","_","_",".","~","~","~","~","#"},
                            {"#","/","_","_","\\",".",".","~","~","#"},
                            {"#","|","o","o","|",".",".","~","~","#"},
                            {"#","|","_","1","|",".",".",".",".","#"},
                            {"#",".",".",".",".",".",".",".",".",">"},
                            {"#",".",".",".",".",".",".",".",".","#"},
                            {"#",".",".",".",".",".",".",".",".","#"},
                            {"#",".",".",".",".",".",".",".",".","#"},
                            {"#","#","#","#","#","#","#","#","#","#"},

                        };
                    }
                    #endregion

                    #region Y:0, X:1
                    if (whichMapX == 1) //Y: 0, X: 1 , outside
                    {
                        mapArray = new string[10, 10]
                        {
                            {"#","#","#","#","#","#","#","#","#","#"},
                            {"#",",",",",",",",",".",".",".",".","#"},
                            {"#",",",",",",",",",".",".",".",".","#"},
                            {"#",",",",",",",",",".",".",".",".","#"},
                            {"#",".",".",".",".",".",".",".",".","#"},
                            {"<",".",".",".",".",".",".",".",".","#"},
                            {"#",".",".",".",".",".",".",".",".","#"},
                            {"#",".",".",".",".",".",".",".",".","#"},
                            {"#",".",".",".",".",".",".",".",".","#"},
                            {"#","#","#","#","#","#","#","#","#","#"},

                        };
                    }
                    #endregion
                }
                #endregion

            }
            #endregion
            #region Inside Maps
            if (!outside)
            {
                #region Y=0
                if (whichMapY == 0)
                {
                    #region Y:0 X:0
                    if (whichMapX == 0)
                    {
                        mapArray = new string[10, 10]
                        {
                            {"#","#","#","#","#","#","#","#","#","#"},
                            {"#",".",".",".",".",".",".",".",".","#"},
                            {"#",".",".",".",".",".",".",".",".","#"},
                            {"#",".",".",".",".",".",".",".",".","#"},
                            {"#",".",".",".",".",".",".",".",".","#"},
                            {"#",".",".",".",".",".",".",".",".","#"},
                            {"#",".",".",".",".",".",".",".",".","#"},
                            {"#",".",".",".",".",".",".",".",".","#"},
                            {"#",".",".",".",".",".",".",".",".","#"},
                            {"#","#","#","#","#","#","#","1","#","#"},

                        };
                    }
                    #endregion
                }
                #endregion
            }
            #endregion
        }
    }
}
