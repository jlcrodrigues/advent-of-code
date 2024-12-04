#include <bits/stdc++.h>

using namespace std;

int main() {
    priority_queue <int> left, right;
    int x, y;
    while (cin >> x >> y) {
        left.push(x);
        right.push(y);
    }
    int sum = 0;
    while (!left.empty() && !right.empty()) {
        sum += abs(left.top() - right.top());
        left.pop();
        right.pop();
    }
    cout << sum << endl;
    return 0;
}