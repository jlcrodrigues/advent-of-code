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

    // iterate over the map of antennas
    for (auto& [antenna, positions] : antennas) {
        for (int i = 0; i < positions.size(); i++) {
            for (int j = i + 1; j < positions.size(); j++) {
                pair<int, int> dist = {positions[j].first - positions[i].first, positions[j].second - positions[i].second};
                pair<int, int> node1 = {positions[i].first + dist.first * 2, positions[i].second + dist.second * 2}; 
                pair<int, int> node2 = {positions[i].first - dist.first, positions[i].second - dist.second};

                if (node1.first >= 0 && node1.first < map.size() && node1.second >= 0 && node1.second < map[0].size()) {
                    if (!visited[node1.first][node1.second]) {
                        sum++;
                    }
                    visited[node1.first][node1.second] = true;
                }
                if (node2.first >= 0 && node2.first < map.size() && node2.second >= 0 && node2.second < map[0].size()) {
                    if (!visited[node2.first][node2.second]) {
                        sum++;
                    }
                    visited[node2.first][node2.second] = true;
                }
            }
        }
    }

    // print map with visited as #
    for (int i = 0; i < map.size(); i++) {
        for (int j = 0; j < map[0].size(); j++) {
            if (visited[i][j]) {
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