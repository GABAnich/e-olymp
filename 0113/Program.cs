using System;
using System.Linq;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] bools = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
            int n = Convert.ToInt32(Console.ReadLine());

            string[] arr = Console.ReadLine().Split(' ');

            foreach (string num in arr)
            {
                int index = Convert.ToInt32(num);
                bools[index]++;
            }

            Console.WriteLine(n - bools.Max());
            Console.ReadKey();
        }
    }
}
