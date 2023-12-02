#include <bits/stdc++.h>

using namespace std;

int cs(string s, unordered_map<string, int> &digits)
{
    int first, last;
    bool firstSet = false;
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = i; j < s.size(); j++)
        {
            string sub = s.substr(i, j - i + 1);
            int d;
            if (digits.find(sub) != digits.end())
            {
                d = digits[sub];
            }
            else if (isdigit(sub[0]))
            {
                d = sub[0] - '0';
            }
            else
                continue;
            if (!firstSet)
            {
                first = d;
                firstSet = true;
            }
            last = d;
            break;
        }
    }
    return first * 10 + last;
}

int main()
{
    unordered_map<string, int> digits = {
        {"one", 1},
        {"two", 2},
        {"three", 3},
        {"four", 4},
        {"five", 5},
        {"six", 6},
        {"seven", 7},
        {"eight", 8},
        {"nine", 9},
    };

    int sum = 0;
    string s;
    while (getline(cin, s))
    {
        sum += cs(s, digits);
    }
    cout << sum << endl;
    return 0;
}