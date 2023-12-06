#include <bits/stdc++.h>

using namespace std;

void ignoreChars(istream &ss)
{
    char c;
    while (ss >> c)
    {
        if (isdigit(c))
        {
            ss.putback(c);
            break;
        }
    }
}

int main()
{
    vector<long> times, records;
    string line;
    getline(cin, line);
    stringstream ss(line);
    ignoreChars(ss);
    long n;
    while ((ss >> n)) {
        times.push_back(n);
    }
    getline(cin, line);
    ss = stringstream(line);
    ignoreChars(ss);
    while ((ss >> n)) {
        records.push_back(n);
    }

    long res = 1;
    for (long t = 0; t < times.size(); t++) {
        long nWays = 0;
        long time = times[t], record = records[t];
        for (long i = 0; i < time; i++) {
            if ((i* (time - i)) > record) nWays++;
        }
        res *= nWays;
    }
    cout << res << endl;
    return 0;
}