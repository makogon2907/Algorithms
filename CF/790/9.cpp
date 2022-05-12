#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

using ll = long long;

int blocksize = 500;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int test;
    cin >> test;
    while (test--) {
        int n;
        cin >> n;
        vector<int> cnt(n + 2);
        vector<int> blocksum(n + 2);
        vector<int> a(n);

        for (auto& el : a) {
            cin >> el;
        }
        ll ans = 0;

        for (int i = n - 1; i >= 0; i--) {
            ll cur = 0;
            int last_block = 0;
            while ((last_block + 1) * blocksize <= a[i]) {
                cur += blocksum[last_block];
                last_block++;
            }
            for (int k = last_block * blocksize; k <= a[i]; k++) {
                cur += cnt[k];
            }

            ans += cur;
            cnt[a[i]]++;
            blocksum[a[i] / blocksize]++;
        }
        cout << ans << "\n";
    }
    return 0;
}