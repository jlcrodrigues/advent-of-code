#include <bits/stdc++.h>

using namespace std;

int main() {
    char c;
    int first, last;
    bool firstSet = false;
    int sum = 0;
    while (true) {
        cin >> noskipws >> c;
        if (isdigit(c)) {
            if (!firstSet) {
                first = c - '0'; firstSet = true;
            }
            last = c - '0';
        }
        if (c == '\n') {
            if (!firstSet) break;
            firstSet = false;
            sum += first * 10 + last;
        }
    }
    cout << sum << endl;
    return 0;
}