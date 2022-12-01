#include <iostream>

using namespace std;

int main() {
    string food;
    int mx = 0, tmp = 0;
    while(getline(cin, food)) {
        if (food.size() == 0) {
            tmp = 0;
        }
        else {
            tmp += stoi(food);
            mx = max(tmp, mx);
        }
        if (cin.peek() == EOF) break;
    }
    cout << mx << endl;
    return 0;
}