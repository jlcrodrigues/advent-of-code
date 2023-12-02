#include <bits/stdc++.h>

using namespace std;

void ignoreChars(istream &ss) {
    char c;
    while (ss >> c) {
        if (isdigit(c)) {
            ss.putback(c);
            break;
        }
    }
}

int main() {
    unordered_map<char, int> m;
    m = {{'r', 12}, {'g', 13}, {'b', 14}};

    char c;
    int id, n;
    int sum = 0;
    string line;
    while (getline(cin, line)) {
        stringstream ss(line);
        ignoreChars(ss);
        ss >> id;
        bool possible = true;
        while (ss.good()) {
            for (int i = 0; i < 3; i++) {
                ignoreChars(ss);
                ss >> n;
                if (!ss.good()) break;
                ss >> c;
                if ((n) > m[c]) {
                    possible = false; break;
                };
            }
        }
        if (possible) sum += id;
    }
    cout << sum << endl;
    return 0;
}