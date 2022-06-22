#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

const int fsize = 8;

bool is_pal(int h, int m) {
    return h == (((m % 10) * 10) + (m / 10));
}

pair<int, int> get_next(int h, int m, int inter) {
    return {(h + (m + inter) / 60) % 24, (m + inter) % 60};
}

int main() {
    int test;
    cin >> test;

    while (test--) {
        int sh, sm, inter, h, m;
        scanf("%d:%d %d", &sh, &sm, &inter);
        auto res = get_next(sh, sm, inter);
        h = res.first;
        m = res.second;

        int ans = is_pal(sh, sm);
        while (h != sh || m != sm) {
            ans += is_pal(h, m);
            auto res = get_next(h, m, inter);
            h = res.first;
            m = res.second;
        }
        cout << ans << endl;
    }
    return 0;
}