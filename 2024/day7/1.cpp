#include <bits/stdc++.h>

using namespace std;

bool is_valid(long int result, vector<long int> &operands) {
    if (operands.empty()) {
        return false;
    }
    if (operands.size() == 1) {
        return operands[0] == result;
    }

    vector<long int> nextFirstElements = {
        operands[0] + operands[1],
        operands[0] - operands[1],
        operands[0] * operands[1]
    };
    if (operands[1] != 0) {
        nextFirstElements.push_back(operands[0] / operands[1]);
    }

    for (long int i = 0; i < nextFirstElements.size(); i++) {
        vector<long int> nextOperands;
        nextOperands.push_back(nextFirstElements[i]);
        for (long int j = 2; j < operands.size(); j++) {
            nextOperands.push_back(operands[j]);
        }

        if (is_valid(result, nextOperands)) {
            return true;
        }
    }
    return false;
}


int main() {
    long long int sum = 0;

    string line;
    while (getline(cin, line)) {
        if (line.empty()) break;
        istringstream iss(line);
        long int result, n;
        vector<long int> operands;
        char c;

        iss >> result;
        iss >> c;

        while (iss >> n) {
            operands.push_back(n);
        }

        if (is_valid(result, operands)) {
            sum += result;
        }
    }

    cout << sum << endl;
    return 0;
}