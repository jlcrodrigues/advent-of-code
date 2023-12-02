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

    char c;
    int id, n;
    int sum = 0;
    string line;
    while (getline(cin, line)) {
        m = {{'r', 0}, {'g', 0}, {'b', 0}};
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
                m[c] = max(m[c], n);
            }
        }
        sum += m['r'] * m['g'] * m['b'];
    }
    cout << sum << endl;
    return 0;
}