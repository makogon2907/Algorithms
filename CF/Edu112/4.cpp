#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int inf = 1e9;

int main() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;

    vector<string> types = {"abc", "acb", "bac", "bca", "cab", "cba"};
    vector<vector<int>> diff(types.size(), vector<int>(n, 0));

    for (int t = 0; t < types.size(); t++) {
        for (int i = 0; i < n; i++) {
            diff[t][i] = (s[i] == types[t][i % 3] ? 0 : 1);
        }
    }
    vector<vector<int>> prefsum(types.size(), vector<int>(n + 1, 0));

    for (int t = 0; t < types.size(); t++) {
        for (int i = 0; i < n; i++) {
            prefsum[t][i + 1] = prefsum[t][i] + diff[t][i];
        }
    }

    while (m--) {
        int l, r;
        cin >> l >> r;
        int ans = inf;
        for (int t = 0; t < types.size(); t++) {
            ans = min(ans, prefsum[t][r] - prefsum[t][l - 1]);
        }
        cout << ans << "\n";
    }
    return 0;
}