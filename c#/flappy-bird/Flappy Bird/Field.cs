using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Flappy_Bird
{
    class Field
    {
        Bird bird = new Bird();
        Random blank = new Random();
        private const int yHeight = 20;
        private const int xHeight = 15;

        public string[,] map;

        public void SetMap()
        {
            map = new string[yHeight,xHeight] 
            {
                {blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot()},
                {blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot()},
                {blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot()},
                {blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot()},
                {blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot()},
                {blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot()},
                {blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot()},
                {blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot()},
                {blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot()},
                {blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot()},
                {blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot()},
                {blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot()},
                {blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot()},
                {blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot()},
                {blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot()},
                {blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot()},
                {blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot()},
                {blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot()},
                {blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot()},
                {blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot(), blankSpot()},
            };        
        }
        private void DrawMap()
        {
            

            map[bird.y, bird.x] = "@";

            string temp = map[bird.y, bird.x + 1];
            

            for (int i = 0; i < yHeight; i++)
            {
                for (int j = 0; j < xHeight; j++)
                {
                    
                    map[bird.y, bird.x - 1] = temp;
                    
                    Console.Write("{0} ", map[i,j]);
                    
                    
                }
                Console.WriteLine();
            }
            
            Console.WriteLine(temp);
            
        }


        private string blankSpot()
        {           
            int what = blank.Next(0, 5);

            switch (what)
            {
                case 0:
                    return " ";
                    
                case 1:
                    return ".";
                    
                case 2:
                    return ",";
                case 3:
                    return "'";
                case 4:
                    return "^";
                default:
                    return " ";
            }

        }

        private void ContinousDraw()
        {
            
            for (int i = 0; i < xHeight - 1; i++)
            {
                for (int j = 0; j < yHeight; j++)
                {
                    map[j, i] = map[j, i + 1];
                }
            }
                   
        }
        private void newBackground()
        {
            for (int i = 0; i < yHeight; i++)
            {
                map[i, 14] = blankSpot();
            }
        }

        public void updateBackground()
        {
            ContinousDraw();
            newBackground();
            DrawMap();            
        }

    }
}
