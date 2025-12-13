using System;
using System.Linq;

public static class Kata
{
    public static bool ValidateRace(int[] moves)
    {
        if (moves.Sum() != 0)
            return false;

        // bool[] places = new bool[moves.Length];
        // Array.Fill(places, false);
        Span<bool> places = stackalloc bool[moves.Length];

        for (int i = 0; i < moves.Length; ++i)
        {
            int pos = i + moves[i];
            if (pos < 0 || places[pos])
                return false;
            places[pos] = true;
        }
        return true;

    }
}