#include <bits/stdc++.h>

using namespace std;

bool is_safe(vector<int> numbers) {
    int n, last;
    if (numbers.size() == 0) return false;
    last = numbers[0];
    int diff = 0;
    bool safe = true;

    for (int i = 1; i < numbers.size(); i++) {
        n = numbers[i];
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
    return safe;
}

int main() {
    int sum = 0;
    string line;
    while (getline(cin, line)) {
        istringstream iss(line);
        vector<int> numbers;
        int n;
        while (iss >> n) {
            numbers.push_back(n);
        }

        if (is_safe(numbers)) {
            sum++;
        }
        else { // brute force dampeneres :/
            for (int i = 0; i < numbers.size(); i++) {
                vector<int> new_numbers = numbers;
                new_numbers.erase(new_numbers.begin() + i);
                if (is_safe(new_numbers)) {
                    sum++;
                    break;
                }
            }
        }
    }
    cout << sum << endl;
    return 0;
}