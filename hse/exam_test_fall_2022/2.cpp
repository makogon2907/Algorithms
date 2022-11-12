#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
#include <map>

using namespace std;

using ll = long long;
const ll inf = 1e18;

struct given_edge {
    int a;
    int b;
    ll price;
    int host;
};
vector<given_edge> edges;
vector<ll> city_cost;

struct edge {
    int to;
    ll price;
    int num;
};

int main() {
    int n, m;
    cin >> n >> m;

    int start = 0;
    int finish = 2 * (n - 1) + 1;

    vector<vector<edge>> g(2 * n);
    vector<ll> dist(2 * n, inf);
    vector<pair<int, int>> parent(2 * n);  // {vert, edge_num}
    set<pair<int, int>> h;

    for (int i = 0; i < n; i++) {
        int r;
        cin >> r;
        g[2 * i].push_back({2 * i + 1, r, -1});
        city_cost.push_back(r);
    }

    for (int i = 0; i < m; i++) {
        int a, b, p, c;
        cin >> a >> b >> p >> c;
        a--;
        b--;
        p--;
        edges.push_back({a, b, c, p});

        g[2 * a + 1].push_back({2 * b, c, i});
        g[2 * b + 1].push_back({2 * a, c, i});
    }

    h.insert({0, start});
    dist[start] = 0;

    while (!h.empty()) {
        auto [dst, v] = *h.begin();
        h.erase(h.begin());
        for (auto& e : g[v]) {
            // cerr << v << " " << e.to << " " << e.num << endl;
            if (dist[e.to] > dist[v] + e.price) {
                h.erase({dist[e.to], e.to});
                dist[e.to] = dist[v] + e.price;
                parent[e.to] = {v, e.num};
                h.insert({dist[e.to], e.to});
            }
        }
    }

    // for (auto el : dist) {
    //     cout << el << " ";
    // }
    // cout << endl;

    if (dist[finish] == inf) {
        cout << -1 << endl;
        return 0;
    }

    int cur_v = finish;
    set<int> way_edges;
    ll total_price = 0;

    vector<int> answer_way = {cur_v / 2};

    while (cur_v != start) {
        auto [par_v, edge_num] = parent[cur_v];
        if (edge_num != -1) {
            // cerr << edge_num << endl;
            way_edges.insert(edge_num);
            total_price += edges[edge_num].price;
            answer_way.push_back(par_v / 2);
        } else {
            total_price += city_cost[par_v / 2];
        }
        cur_v = par_v;
    }
    reverse(answer_way.begin(), answer_way.end());

    set<int> own_edges;
    ll own_price = 0;

    for (int i = 0; i < m; i++) {
        if (edges[i].host == 0) {
            // cerr << i << endl;
            own_edges.insert(i);
            own_price += edges[i].price;
        }
    }

    if (own_price < total_price) {
        cout << -1 << endl;
        return 0;
    }

    set<int> intersection;

    for (auto el : own_edges) {
        if (way_edges.count(el)) {
            intersection.insert(el);
        }
    }

    for (auto el : intersection) {
        way_edges.erase(el);
        own_edges.erase(el);
    }

    cout << own_edges.size() << " ";
    for (auto el : own_edges) {
        cout << el + 1 << " ";
    }
    cout << endl;
    cout << way_edges.size() << " ";
    for (auto el : way_edges) {
        cout << el + 1 << " ";
    }
    cout << endl;

    for (auto el : answer_way) {
        cout << el + 1 << " ";
    }
    cout << endl;
    return 0;
}