#include <iostream>
#include <set>

using namespace std;

int main() {
    string food;
    int tmp = 0;
    set<int> mx;
    while(getline(cin, food)) {
        if (food.size() == 0) {
            if (mx.size() < 3) {
                mx.insert(tmp);
            }
            else if (*mx.begin() < tmp) {
                mx.erase(mx.begin());
                mx.insert(tmp);
            }
            tmp = 0;
        }
        else {
            tmp += stoi(food);
        }
        if (cin.peek() == EOF) break;
    }
    int total = 0;
    auto it = mx.begin();
    for (; it != mx.end(); it++) {
        total += *it;
    }
    cout << total << endl;
    return 0;
}