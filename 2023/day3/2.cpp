#include <bits/stdc++.h>

using namespace std;

int main() {
    map<pair<int, int>, int> nPos;
    vector<int> num;
    vector<pair<int, int>> sPos;

    char c;
    string line;
    int row = 0;
    while (getline(cin, line)) {
        int col = 0;
        stringstream ss(line);
        int curN = 0;
        while ((ss >> c)) {
            if (isdigit(c)) {
                nPos[{row, col}] = num.size();
                curN *= 10;
                curN += c - '0';
            }
            else {
                if (curN != 0)
                    num.push_back(curN);
                curN = 0;
                if (c == '*') 
                    sPos.push_back({row, col});
            }
            col++;
        }
        if (curN != 0) num.push_back(curN);
        row++;
    }
    int sum = 0;
    int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
    int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};

    for (auto & p: sPos) {
        int x = p.first;
        int y = p.second;
        set<int> visited;
        int ratios = 0, curS = 1;
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nPos.find({nx, ny}) != nPos.end()) {
                if (visited.find(nPos[{nx, ny}]) != visited.end()) continue;
                curS *= num[nPos[{nx, ny}]];
                ratios++;
                visited.insert(nPos[{nx, ny}]);
            }
        }
        if (ratios == 2) sum += curS;
    }
    cout << sum << endl;
    return 0;
}