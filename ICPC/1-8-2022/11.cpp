#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <unordered_set>
#include <sstream>

#define all(x) x.begin(), x.end()

using namespace std;

using ll = long long;
const ll mod = 100;

ll dummy_mul[100];

void calc_dummy_mul() {
    ll ans = 1;
    for (ll i = 0; i < 100; i++) {
        if (i % 2 == 0 || i % 5 == 0) {
            dummy_mul[i] = -1;
            continue;
        }
        ans *= i;
        ans %= mod;
        dummy_mul[i] = ans;
    }
    dummy_mul[0] = 1;
}

ll bin_pow(ll a, ll p, ll module) {
    ll res = 1;
    while (p) {
        if (p & 1) {
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        p >>= 1;
    }
    return res;
}

ll get_dummy_mul(ll finish) {
    // ll periods = finish / mod;
    //  ll ans = /*bin_pow(dummy_mul[99], periods, mod)*/ 1;
    ll ans = 1;
    finish %= mod;
    while (dummy_mul[finish] == -1) {
        finish--;
    }

    ans *= dummy_mul[finish];
    ans %= mod;
    return ans;
}

ll get_mul_odd(ll finish) {
    if (finish == 0) {
        return 1;
    }
    if (finish <= 3) {
        return (finish & 1) ? finish : finish - 1;
    }
    return (get_dummy_mul(finish) * get_mul_odd(finish / 5)) % mod;
}

ll get_mul(ll finish) {
    if (finish == 1) {
        return 1;
    }
    return (get_mul_odd(finish) * get_mul(finish / 2)) % mod;
}

ll num_ks(ll n, ll k) {
    ll r = k;
    ll ans = 0;
    while (r <= n) {
        ans += n / r;
        r *= k;
    }
    return ans;
}

ll fact(ll n) {
    ll res = 1;
    for (ll i = 1; i <= n; i++) {
        res *= i;
    }
    return res;
}

string get_ans(ll n) {
    stringstream out;
    if (n < 10 && fact(n) < 10) {
        out << fact(n);
        return out.str();
    }

    ll num2 = num_ks(n, 2);
    ll num5 = num_ks(n, 5);

    num2 -= num5;

    ll ans = bin_pow(2, num2, mod) * get_mul(n);
    ans %= mod;

    if (ans < 10) {
        out << 0;
    }
    out << ans;
    return out.str();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    calc_dummy_mul();

    ll n;
    cin >> n;
    cout << get_ans(n) << endl;

    return 0;
}