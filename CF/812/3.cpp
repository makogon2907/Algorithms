#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

const int maxn = 1e9;

int main() {
    int test;
    cin >> test;
    vector<int> squares;
    for (int i = 0; i * i < maxn; i++) {
        squares.push_back(i * i);
    }

    while (test--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int cur = n - 1;
        while (cur > 0) {
            int next_square = *lower_bound(squares.begin(), squares.end(), cur);
            int diff = next_square - cur;
            for (int i = diff; i <= cur; i++) {
                a[i] = next_square - i;
            }
            cur = diff - 1;
        }
        for (auto el : a) {
            cout << el << " ";
        }
        cout << "\n";
    }
    return 0;
}