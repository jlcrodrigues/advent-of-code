#include <bits/stdc++.h>

using namespace std;

int sort_line(vector<int> &lineNumbers, unordered_map<int, vector<int>> &precedence) {
    for (int i = 0; i < lineNumbers.size(); i++) {
        for (int j = i + 1; j < lineNumbers.size(); j++) {
            auto it = find(precedence[lineNumbers[i]].begin(), precedence[lineNumbers[i]].end(), lineNumbers[j]);
            if (it != precedence[lineNumbers[i]].end()) {
                swap(lineNumbers[i], lineNumbers[j]);
            }
        }
    }
    // print sorted line
    cout << "\n\nss-- ";
    for (int i : lineNumbers) {
        cout << i << " ";
    }
    cout << endl << endl;

    return lineNumbers[lineNumbers.size() / 2];
}

int main() {
    int sum = 0;

    unordered_map<int, vector<int>> precedence;

    string line;
    while (getline(cin, line)) {
        if (line.empty()) break;
        istringstream iss(line);
        int n1, n2;
        char c;
        iss >> n1 >> c >> n2;

        precedence[n2].push_back(n1);
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
            }
            for (int i : precedence[n]) {
                forbidden.insert(i);
            }
        }
        if (!correct) {
            sum += sort_line(lineNumbers, precedence);
        }
    }

    cout << sum << endl;
    return 0;
}