#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int W, H, x1, y1, x2, y2;
        int wneed, hneed;
        cin >> W >> H >> x1 >> y1 >> x2 >> y2;
        cin >> wneed >> hneed;

        const int inf = 1e9;

        int right = (H >= hneed) && (W - x2 >= wneed - x1) ? wneed - x1 : inf;
        int left = (H >= hneed) && (x1 >= wneed - (W - x2)) ? wneed - (W - x2) : inf;
        int up = (W >= wneed) && (H - y2 >= hneed - y1) ? hneed - y1 : inf;
        int down = (W >= wneed) && (y1 >= hneed - (H - y2)) ? hneed - (H - y2) : inf;

        int ans = min({right, left, up, down});

        cout << (ans == inf ? -1 : max(ans, 0)) << "\n";
    }
}