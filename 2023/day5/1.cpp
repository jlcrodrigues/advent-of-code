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
    char c;
    long n;
    string line;
    vector<long> seeds;

    getline(cin, line);
    stringstream ss(line);
    ignoreChars(ss);
    while ((ss >> n)) {
        seeds.push_back(n);
    }
    getline(cin, line);

    while (getline(cin, line)) // discard first line
    {
        map<long, pair<long, long>> m;
        while (getline(cin, line))
        {
            if (line == "") break;
            long dest, source, range;
            stringstream ss(line);
            ss >> dest >> source >> range;
            m.insert({source, {dest, range}});
        }
        for (int i = 0; i < seeds.size(); i++) {
            if ((m.begin()->first > seeds[i])) continue;
            auto it = m.lower_bound(seeds[i]);
            if (it->first != seeds[i]) it--;
            if (it->first + it->second.second < seeds[i]) continue;
            seeds[i] = it->second.first + seeds[i] - it->first;
        }
    }
    long res = seeds[0];
    for (int i = 0; i < seeds.size(); i++) {
        res = min(res, seeds[i]);
    }
    cout << res << endl;
    return 0;
}