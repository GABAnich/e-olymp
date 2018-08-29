using System;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = Convert.ToInt16(Console.ReadLine());
            int count = 0;

            for (int i = 0; i < 1000000; i++)
            {
                if (((i % 10) / 1 + (i % 100) / 10 + (i % 1000) / 100) == n &&
                    ((i % 10000) / 1000 + (i % 100000) / 10000 + (i % 1000000) / 100000) == n)
                {
                    count++;
                }
            }

            Console.WriteLine("{0}", count);

            Console.ReadKey();
        }
    }
}
