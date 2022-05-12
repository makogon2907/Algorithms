#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

using ll = long long;

// const ll inf = (1LL << 60);

int main() {
    int test;
    cin >> test;
    while (test--) {
        int n, m;
        cin >> n >> m;
        vector<vector<ll>> a(n, vector<ll>(m));
        for (auto &row : a) {
            for (auto &el : row) {
                cin >> el;
            }
        }

        vector<ll> sumplus(n + m + 10);
        vector<ll> summinus(3 * (n + m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                sumplus[i + j] += a[i][j];
                summinus[i - j + n + m] += a[i][j];
            }
        }

        ll ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans = max(ans, summinus[i - j + n + m] + sumplus[i + j] - a[i][j]);
            }
        }

        cout << ans << "\n";
    }
    return 0;
}