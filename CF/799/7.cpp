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
        int n, k;
        cin >> n >> k;
        k++;
        vector<int> a(n);
        for (auto &el : a) {
            cin >> el;
        }
        vector<bool> cmp(n, false);
        for (int i = 1; i < n; i++) {
            cmp[i] = (2 * a[i] > a[i - 1]);
        }
        int cnt = 0;
        int ans = 0;
        for (int i = 0; i <= k - 2; i++) {
            cnt += cmp[i];
        }
        for (int l = 0; l + k - 1 < n; l++) {
            cnt += cmp[l + k - 1];
            cnt -= cmp[l];
            ans += (cnt == k - 1);
        }
        cout << ans << "\n";
    }
    return 0;
}