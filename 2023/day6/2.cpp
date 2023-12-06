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

// warning : spaghetti below
int main()
{
    char c;
    long s, r;
    string line;
    queue<pair<long, long>> seeds;

    getline(cin, line);
    stringstream ss(line);
    ignoreChars(ss);
    while ((ss >> s)) {
        ss >> r;
        seeds.push({s, r});
    }
    getline(cin, line);

    while (getline(cin, line)) // discard first line
    {
        map<long, pair<long, long>> m;
        queue<pair<long, long>> newSeeds;
        while (getline(cin, line))
        {
            if (line == "") break;
            long dest, source, range;
            stringstream ss(line);
            ss >> dest >> source >> range;
            m.insert({source, {dest, range}});
        }
        while (!seeds.empty()) {
            auto seed = seeds.front();
            seeds.pop();
            long seedStart = seed.first, seedEnd = seed.first + seed.second;
            auto it = m.lower_bound(seed.first);
            if (it == m.begin() && seedStart < it->first) {
                if (seedEnd <= it->first) {
                    newSeeds.push(seed);
                    continue;
                }
                long rangeStart = it->first, rangeEnd = it->first + it->second.second;
                newSeeds.push({seedStart, rangeStart - seedStart});
                seeds.push({rangeStart, seedEnd - rangeStart});
                continue;
            }
            if (it->first != seed.first) it--;
            long rangeStart = it->first, rangeEnd = it->first + it->second.second;
            if (seedStart >= rangeStart && seedStart < rangeEnd) {
                newSeeds.push({seedStart - it->first + it->second.first, min(rangeEnd, seedEnd) - seedStart});
                if (seedEnd >= rangeEnd) {
                    seeds.push({rangeEnd, seedEnd - rangeEnd});
                }
            }
            else if (seedStart >= rangeEnd) {
                it++;
                if (it == m.end()) {
                    newSeeds.push(seed);
                    continue;
                }
                long nextStart = it->first;
                newSeeds.push({seedStart + it->second.first - it->first, nextStart - seedStart});
                seeds.push({nextStart, seedEnd - nextStart});
            }
            else {
                newSeeds.push(seed);
            }
        }
        seeds = newSeeds;
    }
    long res = seeds.front().first;
    while (!seeds.empty()) {
        res = min(res, seeds.front().first);
        seeds.pop();
    }
    cout << res << endl;
    return 0;
}