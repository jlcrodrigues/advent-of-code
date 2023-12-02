#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// A X Rock
// B Y Paper
// C Z Scissors

int play(char p1, char p2) {
    if (p1 - ('X' - 'A') == p2) return 3;
    if (p1 == 'X' && p2 == 'C') return 6;
    if (p1 == 'Y' && p2 == 'A') return 6;
    if (p1 == 'Z' && p2 == 'B') return 6;
    return 0;
}

int main() {
    unordered_map<char, char> lose = {{'A', 'Z'}, {'B', 'X'}, {'C', 'Y'}};
    unordered_map<char, char> draw = {{'A', 'X'}, {'B', 'Y'}, {'C', 'Z'}};
    unordered_map<char, char> win = {{'A', 'Y'}, {'B', 'Z'}, {'C', 'X'}};
    vector<unordered_map<char, char> > p = {lose, draw, win};
    int score = 0;
    string line;
    while (getline(cin, line)) {
        char next = p[line[2] - 'X'][line[0]];
        score += (int)(next - 'X' + 1);
        score += play(next, line[0]);
    }
    cout << score;
    return 0;
}