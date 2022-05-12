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
        int n, q;
        cin >> n >> q;
        vector<ll> a(n);
        for (auto& el : a) {
            cin >> el;
        }
        sort(a.begin(), a.end());
        reverse(a.begin(), a.end());

        vector<ll> prefix(a.size() + 1);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + a[i];
        }

        while (q--) {
            ll x;
            cin >> x;
            if (x > prefix[n]) {
                cout << -1 << "\n";
                continue;
            }
            cout << lower_bound(prefix.begin(), prefix.end(), x) - prefix.begin() << "\n";
        }
    }
    return 0;
}