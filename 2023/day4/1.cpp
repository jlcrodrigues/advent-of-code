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
    char c;
    string line;
    int sum = 0;
    int num;

    while (getline(cin, line)) {
        stringstream ss(line);
        int curSum = 0;
        ignoreChars(ss);
        ss >> num; // card number
        ignoreChars(ss);
        set<int> win;
        while (ss.peek() != '|') {
            ss >> num;
            ss >> noskipws >> c >> skipws;
            win.insert(num);
        }

        ss >> c; // '|'
        ignoreChars(ss);

        while ((ss >> num)) {
            if (win.find(num) != win.end()) {
                curSum += 1;
            }
        }

        sum += pow(2, curSum - 1);
    }
    cout << sum << endl;
    return 0;
}