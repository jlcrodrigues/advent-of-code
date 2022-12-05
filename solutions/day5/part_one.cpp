#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    string line;
    vector<string> lines;
    vector<stack<char> > stacks;

    while (getline(cin, line)) {
        if (isdigit(line[1])) break;
        lines.push_back(line);
    }

    for (int j = (int)lines.size() - 1; j >= 0; j--) {
        for (size_t i = 0; i < lines[j].size(); i += 4) {
            if (stacks.size() <= i / 4) {
                stacks.push_back({});
            }
            if (isalpha(lines[j][i + 1])) {
                stacks[i / 4].push(lines[j][i + 1]);
            }
        }
    }

    getline(cin, line);

    int amount, src, dest;
    while (cin.good()) {
        cin >> line >> amount >> line >> src >> line >> dest;

        stack<char> aux;
        for (int i = 0; i < amount; i++) {
            stacks[dest - 1].push(stacks[src - 1].top());
            stacks[src - 1].pop();
        }
        amount = 0;
    }

    for (size_t i = 0; i < stacks.size(); i++) {
        if (!stacks[i].empty()) {
            cout << stacks[i].top();
        }
    }
    cout << endl;
    return 0;
}
