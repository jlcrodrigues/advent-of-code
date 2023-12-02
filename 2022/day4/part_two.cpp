#include <iostream>

using namespace std;

// 2-4,6-8

int main() {
    char c;
    pair<int, int> left;
    pair<int, int> right;
    int count = 0;
    while (cin >> left.first) {
        cin >> c >> left.second;
        cin >> c >> right.first;
        cin >> c >> right.second;

        if (left.second - left.first > right.second - right.first) {
            swap(left, right);
        }

        if ((left.first >= right.first && left.first <= right.second) ||
            (left.second >= right.first && left.second <= right.second))
            count++; 
    }
    cout << count << endl;
    return 0;
}