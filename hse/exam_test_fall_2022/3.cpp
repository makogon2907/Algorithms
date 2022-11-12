#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
#include <map>

using namespace std;

using ll = long long;

int main() {
    ll n;
    cin >> n;

    int ans = 0;
    while (n > 0) {
        if (n & 1) {
            ans++;
            n--;
        } else {
            ans++;
            n /= 2;
        }
    }
    cout << ans << endl;
    return 0;
}