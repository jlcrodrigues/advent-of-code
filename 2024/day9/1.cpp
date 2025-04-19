#include <bits/stdc++.h>

using namespace std;

int main() {
    long int sum = 0;
    string line;

    getline(cin, line);

    long int cur = 0;
    long int last_size = line[line.size() - 1] - '0';
    long int last_idx = line.size() - 1;
    for (long int i = 0; i < line.size(); i+=2) {
        if (last_idx == i) {
            long int size = last_size;
            for (long int j = 0; j < size; j++) {
                sum += cur * (last_idx / 2);
                cur++;
                last_size--;
            }
            break;
        }
        // count current file
        long int size = line[i] - '0';
        for (long int j = 0; j < size; j++) {
            sum += cur * (i / 2);
            cur++;
        }

        // allocate last file
        long int space_available = line[i + 1] - '0';
        for (long int j = 0; j < space_available; j++) {
            if (last_size == 0) {
                last_idx -= 2;
                last_size = line[last_idx] - '0';
                if (last_idx <= i) {
                    break;
                }
            }
            last_size--;
            sum += cur * (last_idx / 2);
            cur++;
        }
    }


    cout << sum << endl;
    return 0;
}