#include <bits/stdc++.h>

using namespace std;

int main() {
    int sum = 0;
    string line;
    while (getline(cin, line)) {
        istringstream iss(line);
        int n, last;
        iss >> n; 
        last = n;
        int diff = 0;
        bool safe = true;

        while (iss >> n) {
            int new_diff = n - last;
            if (abs(new_diff) < 1 || abs(new_diff) > 3) {
                safe = false;
                break;
            }
            if ((diff < 0 && new_diff > 0) || (diff > 0 && new_diff < 0)) {
                safe = false;
                break;
            }
            diff = new_diff;
            last = n;
        }
        if (safe && line != "") {
            sum++;
        }
    }
    cout << sum << endl;
    return 0;
}