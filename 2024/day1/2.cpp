#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> left;
    unordered_map<int, int> right;
    int x, y;
    while (cin >> x >> y) {
        left.push_back(x);
        right[y]++;
    }
    int sum = 0;
    for (int i = 0; i < left.size(); i++) {
        sum += left[i] * right[left[i]];
    }
    cout << sum << endl;
    return 0;
}