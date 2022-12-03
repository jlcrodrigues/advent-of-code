#include <iostream>
#include <unordered_map>

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
        unordered_map<char, bool> first;
        unordered_map<char, bool> second;
        unordered_map<char, bool> seen;
        for (size_t i = 0; i < line.size(); i++) {
            if (i < line.size() / 2) {
                first[line[i]] = true;
                if (second.find(line[i]) != second.end() && seen.find(line[i]) == seen.end()) {
                   count += priority(line[i]); 
                   seen[line[i]] = true;
                }
            }
            else {
                second[line[i]] = true;
                if (first.find(line[i]) != first.end() && seen.find(line[i]) == seen.end()) {
                  count += priority(line[i]);
                   seen[line[i]] = true;
                }
            }
        }
    }
    cout << count << endl;
    return 0;
}