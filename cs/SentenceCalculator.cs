

static int LettersToNumbers(string s)
{
    int res = 0;
    foreach (char chr in s)
    {
        if (char.IsDigit(chr))
            res += chr - '0';
        else if (char.IsLower(chr))
            res += chr - 'a' +1;
        else if (char.IsUpper(chr))
            res += (chr - 'A' +1) * 2;
    }
    return res;
}



var input = "I Love You";

var res = LettersToNumbers(input);

Console.Error.WriteLine($"res: {res}"); 
