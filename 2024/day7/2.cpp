#include <bits/stdc++.h>

using namespace std;

bool is_valid(long int result, vector<long int> &operands) {
    if (operands.empty()) {
        return false;
    }
    if (operands.size() == 1) {
        return operands[0] == result;
    }

    string str1 = to_string(operands[0]);


    long int concat = operands[0];
    long int op1 = operands[1];
    while (op1 != 0) {
        concat *= 10;
        op1 /= 10;
    }
    concat += operands[1];

    // Just realized - and / were not part of the problem :')
    vector<long int> nextFirstElements = {
        operands[0] + operands[1],
        operands[0] * operands[1],
        concat
    };

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
    int i = 0;
    while (getline(cin, line)) {
        if (line.empty()) break;
        istringstream iss(line);
        cout << i++ << endl;
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