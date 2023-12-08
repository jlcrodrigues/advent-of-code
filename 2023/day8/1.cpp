#include <bits/stdc++.h>

using namespace std;


int main()
{
    string s;
    char c;
    getline(cin, s);
    vector<int> path;
    stringstream ss(s);
    while ((ss >> c)) {
        path.push_back((c == 'L') ? 0 : 1);
    }

    unordered_map<string, vector<string>> m;

    getline(cin, s); // blank line
    while (getline(cin, s))
    {
        stringstream ss(s);
        string src, l, r;
        ss >> src;
        ss >> c >> c; // = (
        ss >> l;
        ss >> r;
        l = l.substr(0, l.size() - 1);
        r = r.substr(0, r.size() - 1);

        m[src] = {l, r};
    }

    string node = "AAA";
    int count = 0;
    while (node != "ZZZ") {
        for (int i = 0; i < path.size(); i++) {
            node = m[node][path[i]];
            count++;
        }
    }
    cout << count << endl;
    return 0;
}
