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
    for (int i = 0; i < grid.size() - 2; i++) {
        for (int j = 0; j < grid[i].size() - 2; j++) {
            if (
                (
                    (grid[i][j] == 'M' && grid[i+1][j+1] == 'A' && grid[i+2][j+2] == 'S')  // \ is MAS
                    || 
                    (grid[i][j] == 'S' && grid[i+1][j+1] == 'A' && grid[i+2][j+2] == 'M')  // \ is SAM
                )
                &&
                (
                    (grid[i][j+2] == 'M' && grid[i+1][j+1] == 'A' && grid[i+2][j] == 'S')  // / is MAS
                    || 
                    (grid[i][j+2] == 'S' && grid[i+1][j+1] == 'A' && grid[i+2][j] == 'M')  // / is SAM
                )
            ) {
                sum++;
            }
        }
    }
    cout << sum << endl;
    return 0;
}