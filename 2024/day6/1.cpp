#include <bits/stdc++.h>

using namespace std;

int main() {
    int sum = 0;

    vector<vector<char>> map;
    vector<vector<set<pair<int,int>>>> visited;
    pair<int, int> pos;
    pair<int, int> dir = {0, -1};

    string line;
    while(getline(cin, line)) {
        if (line.empty()) break;
        vector<char> row;

        istringstream iss(line);
        char c;
        while (iss >> c) {
            row.push_back(c);
            if (c == '^') {
                pos = {map.size(), row.size() - 1};
            }
        }
        map.push_back(row);
        visited.push_back(vector<set<pair<int,int>>>(row.size()));
    }


    while (true) {
        if (visited[pos.first][pos.second].count(dir)) {
            break;
        }
        else if (visited[pos.first][pos.second].size() == 0) {
            sum++;
        }
        visited[pos.first][pos.second].insert(dir);

        pair<int, int> nextPos = {pos.first + dir.second, pos.second + dir.first};
        if (nextPos.first < 0 || nextPos.first >= map.size() || nextPos.second < 0 || nextPos.second >= map[nextPos.first].size()) {
            break;
        }
        while (map[nextPos.first][nextPos.second] == '#') {
            // turn right
            dir = {-dir.second, dir.first};
            nextPos = {pos.first + dir.second, pos.second + dir.first};
        }

        pos.first += dir.second;
        pos.second += dir.first;
    }

    cout << sum << endl;
    return 0;
}