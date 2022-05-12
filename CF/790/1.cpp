#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int getnumber(string s, int start) {
    return (s[start] - '0') + (s[start + 1] - '0') + (s[start + 2] - '0');
}

int main() {
    int test;
    cin >> test;
    while (test--) {
        string x;
        cin >> x;
        if (getnumber(x, 0) == getnumber(x, 3)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}