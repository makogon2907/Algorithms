#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int m;
        cin >> m;
        vector<int> top(m);
        vector<int> bot(m);
        for (auto& el : top) {
            cin >> el;
        }
        for (auto& el : bot) {
            cin >> el;
        }

        ll sumup = 0;
        for (int i = 1; i < m; i++) {
            sumup += top[i];
        }

        ll sumdown = 0;
        ll ans = max(sumup, sumdown);

        for (int i = 1; i < m; i++) {
            sumup -= top[i];
            sumdown += bot[i - 1];
            ans = min(ans, max(sumup, sumdown));
        }
        cout << ans << "\n";
    }
    return 0;
}