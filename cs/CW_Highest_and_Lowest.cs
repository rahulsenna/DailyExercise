using System;
using System.Linq;

var res = Kata.HighAndLow("1 2 3 4 5");
Console.Error.WriteLine($"res: {res}"); 

public static class Kata
{
  public static string HighAndLow(string numbers)
  {
    var nums = numbers.Split().Select(int.Parse).Order();
    return nums.Last() + " " + nums.First();
  }
}
