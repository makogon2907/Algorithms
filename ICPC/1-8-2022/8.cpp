#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

struct pt {
    int x;
    int y;

    bool operator<(const pt &other) const {
        return tie(x, y) < tie(other.x, other.y);
    }
};

void dfs(pt cur, const vector<pt> &coords, const set<pt> &exists, set<pt> &used) {
    used.insert(cur);
    vector<pt> neighbors;
    neighbors.push_back(pt{cur.x, cur.y + 1});
    neighbors.push_back(pt{cur.x, cur.y - 1});
    neighbors.push_back(pt{cur.x + 1, cur.y});
    neighbors.push_back(pt{cur.x - 1, cur.y});

    for (pt p : neighbors) {
        if (!exists.count(p)) {
            continue;
        }
        if (used.count(p)) {
            continue;
        }
        dfs(p, coords, exists, used);
    }
}

int main() {
    int n;
    cin >> n;
    vector<pt> coords(n);
    set<pt> exists;
    set<pt> used;
    for (int i = 0; i < n; ++i) {
        cin >> coords[i].x >> coords[i].y;
        exists.insert(coords[i]);
    }

    int n_components = 0;
    for (int i = 0; i < n; ++i) {
        if (used.count(coords[i])) {
            continue;
        }
        ++n_components;
        dfs(coords[i], coords, exists, used);
    }

    long long res = 1;
    for (int i = 0; i < n_components; ++i) {
        res *= 2;
        res %= 998244353;
    }
    cout << res << "\n";
}
