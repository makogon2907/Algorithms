#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

using ll = long long;

// const ll inf = (1LL << 60);

int global_cnt = 0;

pair<int, int> dfs(int v, vector<vector<int>>& g, string& s) {
    int sum = 1;
    int white = (s[v] == 'W');
    for (auto next : g[v]) {
        auto [ts, w] = dfs(next, g, s);
        sum += ts;
        white += w;
    }
    if (2 * white == sum) {
        global_cnt++;
    }
    return {sum, white};
}

int main() {
    int test;
    cin >> test;
    while (test--) {
        int n;
        cin >> n;
        vector<vector<int>> g(n);
        for (int i = 1; i < n; i++) {
            int x;
            cin >> x;
            g[x - 1].push_back(i);
        }
        string s;
        cin >> s;
        global_cnt = 0;
        dfs(0, g, s);
        cout << global_cnt << "\n";
    }
    return 0;
}