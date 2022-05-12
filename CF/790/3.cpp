#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

using ll = long long;

const ll inf = (1LL << 60);

int main() {
    int test;
    cin >> test;
    while (test--) {
        int n, m;
        cin >> n >> m;
        vector<string> a(n);
        for (auto &el : a) {
            cin >> el;
        }
        ll ans = inf;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                ll cur = 0;
                for (int k = 0; k < a[i].size(); k++) {
                    cur += abs(a[i][k] - a[j][k]);
                }
                // cerr << "cur: " << cur << endl;
                ans = min(ans, cur);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}