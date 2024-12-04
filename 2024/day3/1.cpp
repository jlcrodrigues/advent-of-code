#include <bits/stdc++.h>

using namespace std;

int main() {
    char c;
    int sum = 0;
    while (cin >> c) {
        if (c == 'm') {
            cin >> c;
            if (c != 'u') continue;
            cin >> c;
            if (c != 'l') continue;
            cin >> c;
            if (c != '(') continue;

            cin >> c;
            int n1 = 0, n2 = 0;
            while (isdigit(c)) {
                n1 = n1 * 10 + c - '0';
                cin >> c;
            }
            if (c != ',') continue;
            cin >> c;
            while (isdigit(c)) {
                n2 = n2 * 10 + c - '0';
                cin >> c;
            }
            if (c != ')') continue;
            sum += n1 * n2;
        }
    }
    cout << sum << endl;
    return 0;
}