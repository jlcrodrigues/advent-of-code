#include <bits/stdc++.h>

using namespace std;

int main() {
    char c;
    int sum = 0;
    bool enabled = true;
    while (cin >> c) {
        if (c == 'm' && enabled) {
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
        // check for do() and don't()
        if (c == 'd') {
            cin >> c;
            if (c != 'o') continue;
            cin >> c;
            if (c == '(') {
                cin >> c;
                if (c == ')') {
                    enabled = true;
                }
            } else if (c == 'n') {
                cin >> c;
                if (c != '\'') continue;
                cin >> c;
                if (c != 't') continue;
                cin >> c;
                if (c != '(') continue;
                cin >> c;
                if (c != ')') continue;
                enabled = false;
            }
        }
    }
    cout << sum << endl;
    return 0;
}