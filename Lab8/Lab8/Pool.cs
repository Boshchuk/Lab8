using System;

namespace Lab8
{
    public class Pool
    {
        public int SizeX { get; set; }
        public int SizeY { get; set; }

        //const string LeftBorder = "╚";
        //const string 

        public void Draw()
        {
            Console.Clear();

            for (int i = 0; i < SizeX; i++)
            {
                Console.Write("*");
            }
            Console.WriteLine();


            for (int i = 0; i < SizeY-2; i++)
            {
                Console.Write("*");
                for (int j = 0; j < SizeX-2; j++)
                {
                    Console.Write(" ");
                }
                Console.WriteLine("*");

            }

            for (int i = 0; i < SizeX; i++)
            {
                Console.Write("*");
            }


            //drow border



        }
    }
}