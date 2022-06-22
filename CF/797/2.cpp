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
        vector<int> a(n);
        vector<int> b(n);
        for (auto& el : a) {
            cin >> el;
        }
        for (auto& el : b) {
            cin >> el;
        }
        int minpos = -1;
        for (size_t i = 0; i < b.size(); i++) {
            if (minpos == -1 && b[i] != 0) {
                minpos = i;
                continue;
            }
            if (minpos != -1 && b[i] < b[minpos] && b[i] != 0) {
                minpos = i;
            }
        }
        if (minpos == -1) {
            cout << "YES\n";
            continue;
        }
        if (a[minpos] < b[minpos]) {
            cout << "NO\n";
            continue;
        }

        bool success = true;
        for (size_t i = 0; i < a.size(); i++) {
            if (b[i] == 0 && a[i] > a[minpos] - b[minpos]) {
                success = false;
                break;
            } else if (b[i] != 0 && a[i] - a[minpos] != b[i] - b[minpos]) {
                success = false;
                break;
            }
        }

        if (success) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}