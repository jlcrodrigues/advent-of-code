#include <iostream>
#include <unordered_map>
#include <set>

using namespace std;

int priority(char c) {
    if (c >= 'a') {
        return (int)(c - 'a' + 1);
    }
    return (int)(c - 'A' + 27);
}

int main() {
    string line;
    int count = 0;

    while (getline(cin, line)) {
        unordered_map<char, int> seen;
        for (int e = 0; e < 3; e++) {
            set<char> read;
            for (size_t i = 0; i < line.size(); i++) {
                if (seen.find(line[i]) == seen.end()) {
                    seen[line[i]] = 1;
                    read.insert(line[i]);
                }
                else if (read.find(line[i]) == read.end()) {
                    seen[line[i]]++;
                    read.insert(line[i]);
                }
                if (e == 2) {
                    if (seen[line[i]] == 3) {
                        count += priority(line[i]);
                        break;
                    }
                }
            }
            if (e != 2)
                getline(cin, line);
        }
    }
    cout << count << endl;
    return 0;
}