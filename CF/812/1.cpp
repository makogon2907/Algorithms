#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    int test;
    cin >> test;
    while (test--) {
        int n;
        cin >> n;
        int minx = 0;
        int maxx = 0;
        int miny = 0;
        int maxy = 0;
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            if (x > 0) {
                maxx = max(x, maxx);
            } else {
                minx = max(minx, -x);
            }
            if (y > 0) {
                maxy = max(y, maxy);
            } else {
                miny = max(miny, -y);
            }
        }
        cout << 2 * (maxx + minx + maxy + miny) << endl;
    }
    return 0;
}