#include <iostream>

using namespace std;

// A X Rock
// B Y Paper
// C Z Scissors

int play(string line) {
    char p1 = line[2], p2 = line[0];
    if (p1 - ('X' - 'A') == p2) return 3;
    if (p1 == 'X' && p2 == 'C') return 6;
    if (p1 == 'Y' && p2 == 'A') return 6;
    if (p1 == 'Z' && p2 == 'B') return 6;
    return 0;
}

int main() {
    int score = 0;
    string line;
    while (getline(cin, line)) {
        score += (int)(line[2] - 'X' + 1);
        score += play(line);
    }
    cout << score;
    return 0;
}