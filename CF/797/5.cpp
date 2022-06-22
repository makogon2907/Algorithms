#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

using ll = long long;
int main() {

    int test;
    cin >> test;
    while (test--) {
        int n, k;
        cin >> n >> k;
        vector<ll> a(n);
        for (auto& el : a) {
            cin >> el;
        }
        sort(a.begin(), a.end(), [&k](int a, int b) { return a % k < b % k; });
        int r = a.size() - 1;
        int l;
        ll ans = 0;
        for (l = 0; l < r; l++) {
            if (a[l] % k + a[r] % k >= k) {
                ans += a[l] / k + a[r] / k + 1;
                r--;
            } else {
                ans += a[l] / k;
            }
        }
        if (r == l) {
            ans += a[l] / k;
        }
        cout << ans << "\n";
    }

    return 0;
}