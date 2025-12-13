using System;
using System.Collections.Generic;
using System.Numerics;

static int[] SortByBit(int[] array)
{
    array.Sort((a, b) =>
        {
            var ac = BitOperations.PopCount((uint)a);
            var bc = BitOperations.PopCount((uint)b);
            return (ac-bc) == 0? a-b: ac-bc ;
        });
    return array;
}

int[] input = [3, 8, 3, 6, 5, 7, 9, 1];



SortByBit(input);

foreach (var e in input)
{
	Console.Error.Write($" {e}"); 
}
