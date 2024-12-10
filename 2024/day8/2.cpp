#include <bits/stdc++.h>

using namespace std;

int main() {
    int sum = 0;

    vector<vector<char>> map;
    vector<vector<bool>> visited;
    unordered_map<char, vector<pair<int, int>>> antennas;

    string line;
    while(getline(cin, line)) {
        if (line.empty()) break;
        vector<char> row;

        istringstream iss(line);
        char c;
        while (iss >> c) {
            row.push_back(c);
            if (c != '.') {
                antennas[c].push_back({map.size(), row.size()-1});
            }
        }
        map.push_back(row);
        visited.push_back(vector<bool>(row.size(), false));
    }

    for (auto& [antenna, positions] : antennas) {
        for (int i = 0; i < positions.size(); i++) {
            for (int j = i + 1; j < positions.size(); j++) {
                // minimum step
                pair<int, int> dist = {positions[j].first - positions[i].first, positions[j].second - positions[i].second};
                while (dist.first % 2 == 0 && dist.second % 2 == 0) {
                    dist.first /= 2;
                    dist.second /= 2;
                }

                pair<int, int> node = {positions[i].first, positions[i].second};
                // go back until out of borders
                while (node.first >= 0 && node.first < map.size() && node.second >= 0 && node.second < map[0].size()) {
                    if (!visited[node.first][node.second]) {
                        sum++;
                    }
                    visited[node.first][node.second] = true;
                    node.first += dist.first;
                    node.second += dist.second;
                }
                node = {positions[i].first - dist.first, positions[i].second - dist.second};
                // go front until out of borders
                while (node.first >= 0 && node.first < map.size() && node.second >= 0 && node.second < map[0].size()) {
                    if (!visited[node.first][node.second]) {
                        sum++;
                    }
                    visited[node.first][node.second] = true;
                    node.first -= dist.first;
                    node.second -= dist.second;
                }
            }
        }
    }

    // print map with visited as #
    for (int i = 0; i < map.size(); i++) {
        for (int j = 0; j < map[0].size(); j++) {
            if (map[i][j] == 'T') {
                cout << "T";
            }
            else if (visited[i][j]) {
                cout << "#";
            } else {
                cout << map[i][j];
            }
        }
        cout << endl;
    }


    cout << sum << endl;
    return 0;
}