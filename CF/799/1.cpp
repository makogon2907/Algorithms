#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    int test;
    cin >> test;

    while (test--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << (b > a) + (c > a) + (d > a) << endl;
    }
    return 0;
}