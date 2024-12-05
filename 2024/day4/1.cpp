#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<vector<char>> grid;

    string line;
    while (getline(cin, line)) {
        if (line.empty()) continue;
        grid.emplace_back(line.begin(), line.end());
    }

    // look for XMAS
    int sum = 0;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            if (grid[i][j] == 'X') {
                // horizontal
                if (j - 3 >= 0 && grid[i][j - 1] == 'M' && grid[i][j - 2] == 'A' && grid[i][j - 3] == 'S') {
                    sum++;
                }
                if (j + 3 < grid[i].size() && grid[i][j + 1] == 'M' && grid[i][j + 2] == 'A' && grid[i][j + 3] == 'S') {
                    sum++;
                }
                // vertical
                if (i - 3 >= 0 && grid[i - 1][j] == 'M' && grid[i - 2][j] == 'A' && grid[i - 3][j] == 'S') {
                    sum++;
                }
                if (i + 3 < grid.size() && grid[i + 1][j] == 'M' && grid[i + 2][j] == 'A' && grid[i + 3][j] == 'S') {
                    sum++;
                }
                // diagonal
                if (i - 3 >= 0 && j - 3 >= 0 && grid[i - 1][j - 1] == 'M' && grid[i - 2][j - 2] == 'A' && grid[i - 3][j - 3] == 'S') {
                    sum++;
                }
                if (i + 3 < grid.size() && j + 3 < grid[i].size() && grid[i + 1][j + 1] == 'M' && grid[i + 2][j + 2] == 'A' && grid[i + 3][j + 3] == 'S') {
                    sum++;
                }
                if (i - 3 >= 0 && j + 3 < grid[i].size() && grid[i - 1][j + 1] == 'M' && grid[i - 2][j + 2] == 'A' && grid[i - 3][j + 3] == 'S') {
                    sum++;
                }
                if (i + 3 < grid.size() && j - 3 >= 0 && grid[i + 1][j - 1] == 'M' && grid[i + 2][j - 2] == 'A' && grid[i + 3][j - 3] == 'S') {
                    sum++;
                }
            }
        }
    }
    cout << sum << endl;
    return 0;
}