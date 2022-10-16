#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

using ll = unsigned long long;

int main() {
    ll m_min = 0;
    ll m_max = 2'000'000'000;

    while (m_max != m_min) {
        ll m_mid = (m_min + m_max) / 2;
        cout << "M " << m_mid << endl;
        string res;
        cin >> res;
        if (res == "out") {
            m_min = m_mid + 1;
        } else {
            m_max = m_mid;
        }
    }

    ll m = m_min;

    ll e_min = m;
    ll e_max = m * m;
    while (e_min != e_max) {
        ll e_mid = (e_min + e_max) / 2;
        cout << "E " << e_mid << endl;
        string res;
        cin >> res;
        if (res == "out") {
            e_min = e_mid + 1;
        } else {
            e_max = e_mid;
        }
    }

    ll e = e_min;

    ll d = 2 * e - m * m;
    d = sqrt(d);
    ll y = (m + d) / 2;
    ll x = m - y;
    cout << "! " << x << " " << y << endl;
}
