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
#include <sstream>

using namespace std;

using ll = long long;

const ll mod = 998244353;

struct event {
    int time;
    int team;
    int value;
};

event decode_ev(int encoded) {
    event e = {};
    if (encoded < 42) {
        e.time = encoded / 6;
        encoded %= 6;
        e.team = encoded / 3;
        encoded %= 3;
        e.value = encoded + 1;
    } else {
        encoded -= 42;
        e.time = encoded;
    }
    return e;
}

int encode_ev(event e) {
    if (e.value == 0) {
        return e.time + 42;
    }
    return e.time * 6 + e.team * 3 + (e.value - 1);
}

string convert(int ev_num) {
    event e = decode_ev(ev_num);
    stringstream s;
    s << "{time: " << e.time << " team: " << e.team << " value: " << e.value << "}";
    return s.str();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int a, b;
    cin >> a >> b;

    vector<vector<vector<ll>>> dp(a + 1, vector<vector<ll>>(b + 1, vector<ll>(49, -1)));

    for (int k = 0; k < 42; k++) {
        dp[0][0][k] = 0;
    }
    for (int k = 42; k < 48; ++k) {
        dp[0][0][k] = 1;
    }

    for (int k = 0; k < 49; ++k) {
        event e = decode_ev(k);
        if (e.time != 0) {
            continue;
        }
        if (e.value == 0) {
            dp[0][0][k] = 1;
            continue;
        }
        if (e.value > 0) {
            if (e.team == 0) {
                if (e.value > a) {
                    continue;
                }
                dp[e.value][0][k] = 1;
            } else {
                if (e.value > b) {
                    continue;
                }
                dp[0][e.value][k] = 1;
            }
        }
    }

    for (int i = 0; i <= a; ++i) {
        for (int j = 0; j <= b; ++j) {
            for (int k = 0; k < 49; ++k) {
                if (dp[i][j][k] != -1) {
                    continue;
                }
                dp[i][j][k] = 0;

                event e = decode_ev(k);
                if (e.value == 0) {  // end of time
                    if (e.time == 6 && i == j) {
                        dp[i][j][k] = 0;
                        continue;
                    }
                    for (int kk = 0; kk < 49; ++kk) {
                        event ee = decode_ev(kk);
                        if (ee.value > 0 && ee.time != e.time) {
                            continue;
                        }
                        if (ee.value == 0 && ee.time != e.time - 1) {
                            continue;
                        }
                        if (ee.value == 0 && ee.time >= 3 && i != j) {
                            continue;
                        }
                        dp[i][j][k] += dp[i][j][kk];
                        dp[i][j][k] %= mod;
                        // cerr << "adding: " << i << " " << j << " " << convert(k)
                        //      << " <= " << dp[i][j][kk] << " <= : " << i << " " << j << " "
                        //      << convert(kk) << endl;
                    }
                } else {
                    int old_i = i;
                    int old_j = j;
                    if (e.team == 0) {
                        old_i -= e.value;
                    } else {
                        old_j -= e.value;
                    }
                    if (old_i < 0 || old_j < 0) {
                        dp[i][j][k] = 0;
                        continue;
                    }

                    for (int kk = 0; kk < 49; ++kk) {
                        event ee = decode_ev(kk);
                        if (ee.value > 0 && ee.time != e.time) {
                            continue;
                        }
                        if (ee.value == 0 && ee.time != e.time - 1) {
                            continue;
                        }
                        if (ee.value == 0 && ee.time >= 3 && old_i != old_j) {
                            continue;
                        }
                        dp[i][j][k] += dp[old_i][old_j][kk];
                        dp[i][j][k] %= mod;
                        // cerr << "adding: " << i << " " << j << " " << convert(k)
                        //      << " <= " << dp[old_i][old_j][kk] << " <= : " << old_i << " " <<
                        //      old_j
                        //      << " " << convert(kk) << endl;
                    }
                }
            }
        }
    }

    ll ans = 0;

    for (int i = 3; i < 7; ++i) {
        ans += dp[a][b][42 + i];
        ans %= mod;
    }
    cout << ans << "\n";
}
