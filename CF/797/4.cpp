#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {

    int test;
    cin >> test;
    while (test--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int cnt = 0;
        int ans = k;
        for (int i = 0; i < k - 1; i++) {
            cnt += (s[i] == 'B');
        }
        for (int l = 0; l + k - 1 < n; l++) {
            cnt += (s[l + k - 1] == 'B');
            ans = min(ans, k - cnt);
            cnt -= (s[l] == 'B');
        }
        cout << ans << "\n";
    }

    return 0;
}