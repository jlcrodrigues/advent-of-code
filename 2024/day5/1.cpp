#include <bits/stdc++.h>

using namespace std;

int main() {
    int sum = 0;

    unordered_map<int, vector<int>> precendence;

    string line;
    while (getline(cin, line)) {
        if (line.empty()) break;
        istringstream iss(line);
        int n1, n2;
        char c;
        iss >> n1 >> c >> n2;

        precendence[n2].push_back(n1);
    }

    int n;
    char c;
    while (getline(cin, line)) {
        if (line.empty()) break;
        istringstream iss(line);
        vector<int> lineNumbers;
        set<int> forbidden;
        bool correct = true;
        while (iss >> n) {
            iss >> c; // ,
            lineNumbers.push_back(n);
            if (forbidden.count(n)) {
                correct = false;
                break;
            }
            for (int i : precendence[n]) {
                forbidden.insert(i);
            }
        }
        if (correct) {
            sum += lineNumbers[lineNumbers.size() / 2];
        }
    }

    cout << sum << endl;
    return 0;
}