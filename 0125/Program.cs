using System;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            string line1 = Console.ReadLine();
            string line2 = Console.ReadLine();

            int[] numbers1 = Array.ConvertAll(line1.Split(' '), int.Parse);
            int[] numbers2 = Array.ConvertAll(line2.Split(' '), int.Parse);

            int h1 = numbers1[0];
            int m1 = numbers1[1];
            int s1 = numbers1[2];

            int h2 = numbers2[0];
            int m2 = numbers2[1];
            int s2 = numbers2[2];

            int seconds1 = h1 * 3600 + m1 * 60 + s1;
            int seconds2 = h2 * 3600 + m2 * 60 + s2;

            int dif = seconds2 - seconds1;

            int h = dif / 3600;
            dif = dif % 3600;
            int m = dif / 60;
            dif = dif % 60;
            int s = dif;

            Console.WriteLine("{0} {1} {2}", h, m, s);


            Console.ReadKey();
        }
    }
}
