#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

using ll = long long;

void dfs(int v, vector<vector<int>>& g, vector<bool>& used) {
    used[v] = true;
    for (auto next : g[v]) {
        if (!used[next]) {
            dfs(next, g, used);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n);
    vector<bool> used(n, false);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            cnt++;
            dfs(i, g, used);
        }
    }

    cout << cnt << endl;
    return 0;
}