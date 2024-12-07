#include <bits/stdc++.h>

using namespace std;

int main() {
    // just brute forcing this one
    int sum = 0;

    pair<int, int> startPos;
    vector<vector<char>> ogMap;
    vector<vector<set<pair<int,int>>>> ogVisited;

    string line;
    while(getline(cin, line)) {
        if (line.empty()) break;
        vector<char> row;

        istringstream iss(line);
        char c;
        while (iss >> c) {
            row.push_back(c);
            if (c == '^') {
                startPos = {ogMap.size(), row.size() - 1};
            }
        }
        ogMap.push_back(row);
        ogVisited.push_back(vector<set<pair<int,int>>>(row.size()));
    }

    // iterate map
    for (int i = 0; i < ogMap.size(); i++) {
        // print percentage
        cout << i << " / " << ogMap.size() << endl;
        for (int j = 0; j < ogMap[i].size(); j++) {
            pair<int, int> pos;
            pair<int, int> dir = {0, -1};

            vector<vector<char>> map(ogMap.size());
            std::copy(ogMap.begin(), ogMap.end(), map.begin());

            vector<vector<set<pair<int,int>>>> visited(ogVisited.size());
            std::copy(ogVisited.begin(), ogVisited.end(), visited.begin());

            pos = startPos;

            if ((i == startPos.first && j == startPos.second) || map[i][j] == '#') {
                continue;
            }
            map[i][j] = '#';

            while (true) {
                if (visited[pos.first][pos.second].count(dir)) {
                    sum++;
                    break;
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

        }
    }


    cout << sum << endl;
    return 0;
}