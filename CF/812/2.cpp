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
        int a;
        cin >> a;
        bool was_down = false;
        bool answer = true;
        for (int i = 0; i < n - 1; i++) {
            int next;
            cin >> next;
            if (was_down && next > a) {
                answer = false;
            }
            was_down = was_down || (next < a);
            a = next;
        }
        if (answer) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}