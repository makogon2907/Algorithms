#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

const int fsize = 8;

bool is_pal(int h, int m) {
    return h == (((m % 10) * 10) + (m / 10));
}

pair<int, int> get_next(int h, int m, int inter) {
    return {(h + (m + inter) / 60) % 24, (m + inter) % 60};
}

int main() {
    int test;
    cin >> test;

    while (test--) {
        int n, s;
        cin >> n >> s;
        vector<int> ar(n);
        int sum = 0;
        for (auto& el : ar) {
            cin >> el;
            sum += el;
        }
        if (s > sum) {
            cout << -1 << "\n";
            continue;
        }
        int l = 0;
        int r = n;
        int todel = sum - s;
        while (todel > 0) {
            todel -= (ar[l++] == 1);
        }
        int ans = l;
        while (l > 0) {
            todel += (ar[--l] == 1);
            while (todel > 0) {
                todel -= (ar[--r] == 1);
            }
            ans = min(ans, l + n - r);
        }
        cout << ans << "\n";
    }
    return 0;
}