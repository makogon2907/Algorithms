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
        int h = (n + 5) / 3;
        if (n == 2 * h - 1) {
            cout << h - 2 << ' ' << h << " " << 1 << "\n";
        } else {
            cout << h - 1 << ' ' << h << ' ' << n - 2 * h + 1 << "\n";
        }
    }
    return 0;
}