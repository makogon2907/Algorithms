#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

using ll = long long;

// const ll inf = (1LL << 60);

int main() {
    int test;
    cin >> test;
    while (test--) {
        int n, k;
        cin >> n >> k;
        map<int, int> cnt;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            cnt[x]++;
        }
        int rans = -1;
        int ans = 0;
        int cur_stack = 0;
        int last = -1;

        for (auto &[key, value] : cnt) {
            if (value < k) {
                if (cur_stack > ans) {
                    ans = cur_stack;
                    rans = last;
                }
                cur_stack = 0;
                continue;
            }
            if (key > last + 1) {
                if (cur_stack > ans) {
                    ans = cur_stack;
                    rans = last;
                }
                cur_stack = 0;
            }
            last = key;
            cur_stack++;
        }
        if (cur_stack > ans) {
            ans = cur_stack;
            rans = last;
        }

        if (rans == -1) {
            cout << "-1\n";
        } else {
            cout << rans - ans + 1 << " " << rans << "\n";
        }
    }
    return 0;
}