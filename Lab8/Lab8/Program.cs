using System;
using System.Threading;

namespace Lab8
{
    class Program
    {
        
        static void Main(string[] args)
        {
            var random = new Random();
            var sizeX = random.Next(5, 30);
            var sizeY = random.Next(5, 30);

            var xDir = 0;
            var yDir = 0;

            while (xDir == 0 || yDir == 0)
            {
                xDir = random.Next(-1, 1);
                yDir = random.Next(-1, 1);
            }

            var pool = new Pool
            {
                SizeX = sizeX,
                SizeY = sizeY
            };
            var ball = new MyBall
            {
                ClientHeight = sizeY,
                ClientWidth = sizeX,
                PosX = 2,
                PosY = 2,
                VelX = xDir,
                VelY = yDir
            };

            pool.Draw();
            while (true)
            {
               ball.MoveBall();
               ball.DrowBall();
               Thread.Sleep(250);
            }
        }
    }
}
