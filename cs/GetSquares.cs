int[] GetSquares(int[] array)
{
    HashSet<int> res = [];
    foreach (var e in array)
    {
        int sq = (int)Math.Sqrt(e);
        if (sq * sq == e)
            res.Add(e);
    }
        int [] r = [.. res];
        Array.Sort(r);
        return r;
}


int [] input = [4, 1, 16, 1, 10, 35, 22 ];


var res = GetSquares(input);

foreach (var e in res)
{
	Console.Error.WriteLine(e); 
}