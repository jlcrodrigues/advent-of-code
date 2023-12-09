#include <bits/stdc++.h>

using namespace std;


int main()
{
    long count = 0;
    string s;
    while (getline(cin, s))
    {
        int n;
        vector<vector<int>> v;
        v.push_back({});
        stringstream ss(s);
        while ((ss >> n)) v[0].push_back(n);

        int isZero = false;
        while (!isZero) {
            isZero = true;
            v.push_back({});
            for (int i = 0; i < v[v.size() - 2].size() - 1; i++) {
                int next = v[v.size() - 2][i + 1] - v[v.size() - 2][i];
                if (next != 0) isZero = false;
                v.back().push_back(next);
            }
        }
        int cCount = 0;
        for (int i = v.size() - 1; i >= 0; i--) {
            cCount = -cCount + v[i][0];
        }
        count += cCount;
    }
    cout << count << endl;
    return 0;
}
