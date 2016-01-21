using System;

namespace Lab8
{
    class MyBall
    {
        public int LastX { get; set; }
        public int LastY { get; set; }

        public int PosX { get; set; }

        public int PosY { get; set; }

        public int VelX { get; set; }
        public int VelY { get; set; }

        public int ClientWidth { get; set; }

        public int ClientHeight { get; set; }

        public void MoveBall()
        {
            LastX = PosX;
            LastY = PosY;
            PosX = PosX + VelX;
            PosY = PosY + VelY;
            if (PosX >= ClientWidth -2)
            {
                VelX = -VelX;
            }

            if (PosX <= 1)
            {
                VelX= -VelX;
            }

            if (PosY >= ClientHeight -2)
            {
                VelY= -VelY;
            }

            if (PosY <= 1)
            {
                VelY = -VelY;
            }
        }

        public void DrowBall()
        {
            var lastColor = Console.ForegroundColor;
            
            Console.ForegroundColor = ConsoleColor.Red;

            Console.SetCursorPosition(LastX, LastY);
            Console.Write(" ");
            Console.SetCursorPosition(PosX, PosY);
            Console.Write("b");

            Console.ForegroundColor = lastColor;
        }
    }
}