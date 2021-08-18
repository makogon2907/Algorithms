#include <algorithm>
#include <iostream>

using namespace std;

using ll = long long;

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;

        ll curmin = n + 1000;

        for (int a = 0; a < 5; a++) {
            for (int b = 0; b < 5; b++) {
                ll cur = a * 6 + b * 8;
                ll rest = max(0LL, n - cur);
                ll to_take = rest % 10 == 0 ? rest : rest - rest % 10 + 10;
                to_take += cur;
                if (to_take >= n && to_take <= curmin) {
                    curmin = to_take;
                }
            }
        }
        cout << curmin * 5 / 2 << "\n";
    }

    return 0;
}