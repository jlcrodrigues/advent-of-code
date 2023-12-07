#include <bits/stdc++.h>

using namespace std;

enum htype
{
    HIGH,
    OPAIR,
    TPAIR,
    THREE,
    FULL,
    FOUR,
    FIVE
};

htype getHandType(string hand)
{
    unordered_map<char, int> cnt;
    for (char c : hand)
        cnt[c]++;
    bool pFound, tFound;
    for (auto p : cnt)
    {
        if (p.second == 5)
            return FIVE;
        if (p.second == 4)
            return FOUR;
        if (p.second == 3)
        {
            tFound = true;
        };
        if (p.second == 2)
        {
            if (pFound)
                return TPAIR;
            pFound = true;
        }
    }
    if (tFound && pFound)
        return FULL;
    if (tFound)
        return THREE;
    if (pFound)
        return OPAIR;
    return HIGH;
}

unordered_map<char, int> v = {{'A', 14}, {'K', 13}, {'Q', 12}, {'J', 11}, {'T', 10}};

bool cS(string a, string b) {
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == b[i]) continue;
        int ai = isdigit(a[i]) ? a[i] - '0' : v[a[i]];
        int bi = isdigit(b[i]) ? b[i] - '0' : v[b[i]];
        return ai < bi;
    }
    return false;
}

int main()
{
    unordered_map<string, pair<htype, int>> m;
    vector<string> hands;

    string s;
    while (getline(cin, s))
    {
        stringstream ss(s);
        string hand;
        ss >> hand;
        int bid;
        ss >> bid;

        m[hand] = {getHandType(hand), bid};
        hands.push_back(hand);
    }
    sort(hands.begin(), hands.end(), [&](string a, string b)
         {
            if (m[a].first == m[b].first)
                return cS(a, b);
            return m[a].first < m[b].first; });

    int sum = 0;
    for (int i = 0; i < hands.size(); i++)
    {
        sum += (i + 1) * m[hands[i]].second;
    }
    cout << sum << endl;
    return 0;
}
