
#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()

using namespace std;

const int right_columns = 3;
const int matrix_per_line = 3;

vector<int>& operator*=(vector<int>& foo, int k) {
    for (auto& el : foo)
        el *= k;
    return foo;
}

vector<int> operator*(const vector<int>& foo, int k) {
    vector<int> ans = foo;
    for (auto& el : ans)
        el *= k;
    return ans;
}

vector<int>& operator/=(vector<int>& foo, int k) {
    for (auto& el : foo)
        el /= k;
    return foo;
}

vector<int> operator+(const vector<int>& v1, const vector<int>& v2) {
    vector<int> ans = v1;
    for (size_t i = 0; i < v1.size(); i++)
        ans[i] += v2[i];
    return ans;
}

vector<int>& operator+=(vector<int>& v1, const vector<int>& v2) {
    for (size_t i = 0; i < v1.size(); i++) {
        v1[i] += v2[i];
    }
    return v1;
}

int gcd(int a, int b) {
    if (a == 0)
        return b;
    if (b == 0)
        return a;

    a = abs(a);
    b = abs(b);
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int gcd_row(const vector<int>& foo) {
    int cur_gcd = 0;
    for (auto el : foo)
        cur_gcd = gcd(cur_gcd, el);
    return cur_gcd;
}

string int_to_str(int x) {
    if (x == 0)
        return "0";
    bool flag = (x < 0);
    x = abs(x);
    string ans = "";
    while (x > 0) {
        ans += '0' + (x % 10);
        x /= 10;
    }
    if (flag)
        ans += '-';
    reverse(all(ans));
    return ans;
}

class Matrix {
public:
    vector<vector<int>> data;
    Matrix(const vector<vector<int>>& data) : data(data) {}

    void to_reduce_row(int row_num) {
        int g = gcd_row(data[row_num]);
        if (g == 0)
            return;
        auto& row = data[row_num];

        for (size_t i = 0; i < row.size(); i++) {
            if (row[i] == 0)
                continue;
            if (row[i] / g < 0)
                g *= -1;
            break;
        }

        row /= g;
    }

    void to_reduce() {
        for (size_t i = 0; i < data.size(); i++) {
            to_reduce_row(i);
        }
    }

    bool first_transform(int main_row, int row) {  // main_row remains constant
        if (row == main_row)
            return false;
        size_t first_elem = 0;
        while (first_elem < data[main_row].size() && data[main_row][first_elem] == 0)
            first_elem++;
        if (first_elem == data[main_row].size())
            return false;
        if (data[row][first_elem] == 0)
            return false;

        int main_elem = data[main_row][first_elem];
        int sub_elem = data[row][first_elem];

        data[row] *= main_elem;
        data[row] += (data[main_row] * (sub_elem * -1));

        to_reduce_row(row);
        to_reduce_row(main_row);

        return true;
    }

    bool second_transform(int main_row, int row) {
        if (main_row == row)
            return false;
        swap(data[main_row], data[row]);
        return true;
    }

    int calc_begin_zeros(int row) {
        int zeros = 0;
        for (auto el : data[row])
            if (el != 0)
                break;
            else
                zeros++;
        return zeros;
    }
    int find_main_row(int start_row) {
        int zeros = calc_begin_zeros(start_row);
        int ans = start_row;
        for (size_t i = start_row + 1; i < data.size(); i++) {
            if (calc_begin_zeros(i) < zeros) {
                zeros = calc_begin_zeros(i);
                ans = i;
            }
        }
        return ans;
    }

    void print_matrix() {
        for (size_t i = 0; i < data.size(); i++) {
            for (size_t j = 0; j < data[i].size(); j++) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    vector<Matrix> toStepView() {
        vector<Matrix> ans;
        Matrix cur = *this;
        ans.push_back(cur);
        ans.push_back(cur);

        for (size_t i = 0; i < data.size(); i++) {
            int main_row = ans.back().find_main_row(i);

            if (ans.back().second_transform(main_row, i))
                ans.push_back(ans.back());

            for (size_t j = i; j < data.size(); j++) {
                if (ans.back().first_transform(i, j))
                    ans.push_back(ans.back());
            }
        }

        for (size_t i = 1; i < data.size(); i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (ans.back().first_transform(i, j))
                    ans.push_back(ans.back());
            }
        }
        ans.pop_back();
        return ans;
    }

    string convert_to_latex() {
        string mod = "[";
        for (size_t i = 0; i < data[0].size() - right_columns; i++)
            mod += 'r';
        if (right_columns > 0)
            mod += '|';
        for (int i = 0; i < right_columns; i++)
            mod += 'r';
        mod += ']';

        string ans = "";
        ans += "\\begin{pmatrix}";
        ans += mod;
        ans += "\n";
        for (size_t i = 0; i < data.size(); i++) {
            ans += int_to_str(data[i][0]);
            for (size_t j = 1; j < data[i].size(); j++) {
                ans += " & ";
                ans += int_to_str(data[i][j]);
            }
            if (i != data.size() - 1) {
                ans += '\\';
                ans += '\\';
            }
            ans += "\n";
        }
        ans += "\\end{pmatrix}\n";
        return ans;
    }
};

void to_latex(vector<Matrix> foo) {
    cout << foo[0].convert_to_latex();
    for (size_t i = 1; i < foo.size(); i++) {
        cout << "\\to\n";
        cout << foo[i].convert_to_latex();
        if (i % matrix_per_line == matrix_per_line - 1) {
            cout << "\\to\n\\\\\\\\\n";
        }
    }
}

/*
Инструкция по использованию:
Сначала вводятся 2 числа раздельно:
1) количество строк в матрице
2) количество столбцов

Затем, собственно, сама матрица построчно, элементы внутри одной строки 
разделяются пробелом.

Вначале кода есть 2 константы:
1)right_columns -- через сколько столбцов, считая справа 
нужно поставить черту в матрице, чтобы это выглядело осмысленно
2)matrix_per_line -- сколько матриц будет в одной строке перед переходом на новую

Эти константы влияют только на генерирование кода в LaTeX.

Программа выводит код, который можно прямо вставлять в TeX -- пошаговое применение 
элементарных преобразований строк


!!
Чтобы скомпилировалась в LaTeXе такая модификация окружения pmatrix
(чтобы можно было черту ставить посередине), нужно в преамбулу добавить 
такой код:

\makeatletter
\renewcommand*\env@matrix[1][*\c@MaxMatrixCols c]{%
    \hskip -\arraycolsep
    \let\@ifnextchar\new@ifnextchar
    \array{#1}}
\makeatother
*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> foo(n, vector<int>(m));
    for (auto& row : foo)
        for (auto& el : row)
            cin >> el;

    Matrix Mat(foo);

    vector<Matrix> ans = Mat.toStepView();

    to_latex(ans);

    return 0;
}