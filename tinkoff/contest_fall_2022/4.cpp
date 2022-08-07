#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string line;
    int depth = 0;

    map<int, map<string, int>> level_values;
    map<string, map<int, int>> var_values;

    while (cin >> line) {
        if (line == "{") {
            depth++;
        } else if (line == "}") {
            for (const auto& [varname, value] : level_values[depth]) {
                var_values[varname].erase(depth);
            }
            level_values.erase(depth);
            depth--;
        } else {
            int eq_index = line.find("=");
            string varname = line.substr(0, eq_index);
            string argument = line.substr(eq_index + 1, line.size());

            if ('a' <= argument[0] && argument[0] <= 'z') {
                if (var_values[argument].size() > 0) {
                    auto [l, v] = *var_values[argument].rbegin();
                    level_values[depth][varname] = v;
                    var_values[varname][depth] = v;
                } else {
                    level_values[depth][varname] = 0;
                    var_values[varname][depth] = 0;
                }
                cout << level_values[depth][varname] << "\n";
            } else {
                auto arg = stoi(argument);
                level_values[depth][varname] = arg;
                var_values[varname][depth] = arg;
            }
        }
    }

    return 0;
}