#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int sqr(int x) {
    return x * x;
}

int main() {
    pair<int, int> l1, r1, l2, r2;
    cin >> l1.first >> l1.second >> r1.first >> r1.second;
    cin >> l2.first >> l2.second >> r2.first >> r2.second;

    int minx = min(l1.first, l2.first);
    int maxx = max(r1.first, r2.first);

    int miny = min(l1.second, l2.second);
    int maxy = max(r1.second, r2.second);

    cout << sqr(max(maxx - minx, maxy - miny)) << endl;

    return 0;
}