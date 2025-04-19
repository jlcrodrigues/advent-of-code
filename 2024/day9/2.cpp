#include <bits/stdc++.h>

using namespace std;

int main() {
    long int sum = 0;
    string line;
    priority_queue<pair<long int, long int>> files; // id, size

    unordered_set<long int> used_files;

    getline(cin, line);

    for (long int i = line.size() - 1; i >= 0; i-=2) {
        files.push({i / 2, line[i] - '0'});
    }

    long int cur = 0;
    for (int i = 0; i < line.size(); i+=2) {
        if (used_files.find(i / 2) != used_files.end()) {
            cur += line[i] - '0';
        }
        else {
            long int size = line[i] - '0';
            for (long int j = 0; j < size; j++) {
                sum += cur * (i / 2);
                cur++;
            }
            used_files.insert(i / 2);
        }

        long int space_available = line[i + 1] - '0';
        long int next_cur = cur + space_available;
        priority_queue<pair<long int, long int>> files_copy = files;
        while (!files_copy.empty()) {
            pair<long int, long int> file = files_copy.top();
            files_copy.pop();
            if (file.first <= i / 2 || used_files.find(file.first) != used_files.end()) {
                continue;
            }
            if (file.second <= space_available) {
                for (long int j = 0; j < file.second; j++) {
                    sum += cur * file.first;
                    cur++;
                    space_available--;
                }
                used_files.insert(file.first);
            }
        }
        cur = next_cur;
    }

    cout << sum << endl;
    return 0;
}