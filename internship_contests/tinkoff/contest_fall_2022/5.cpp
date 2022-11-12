#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

using ll = long long;

struct Node {
    map<char, Node*> children;
    string path;
    int cnt_subtree;
    int cnt_this;
    int index;
};

void add(Node* root, string& s, int idx, int curstrpos = 0) {
    if (curstrpos == s.size()) {
        root->cnt_subtree++;
        root->cnt_this++;
        root->index = idx;
        return;
    }
    if (!root->children.count(s[curstrpos])) {
        Node* next_node;
        root->children[s[curstrpos]] = (next_node = new Node{});
        root->cnt_subtree++;

        next_node->path = s.substr(curstrpos, s.size());
        next_node->cnt_subtree = 1;
        next_node->cnt_this = 1;
        next_node->index = idx;
        return;
    }
    Node* next = root->children[s[curstrpos]];
    for (int i = 0; curstrpos + i < s.size() && i < next->path.size(); i++) {
        if (s[curstrpos + i] != next->path[i]) {
            Node* new_node = new Node{};
            new_node->path = s.substr(curstrpos + i, s.size());
            new_node->cnt_subtree = 1;
            new_node->cnt_this = 1;
            new_node->index = idx;

            Node* middle = new Node{};
            middle->path = next->path.substr(0, i);
            middle->cnt_subtree = next->cnt_subtree + 1;
            middle->cnt_this = 0;
            middle->children[next->path[i]] = next;
            middle->children[s[curstrpos + i]] = new_node;

            root->children[s[curstrpos]] = middle;
            root->cnt_subtree++;
            next->path = next->path.substr(i, next->path.size());
            return;
        }
    }
    if (s.size() - curstrpos >= next->path.size()) {
        root->cnt_subtree++;
        add(next, s, idx, curstrpos + next->path.size());
        return;
    }
    int len = s.size() - curstrpos;
    Node* new_node = new Node{};
    new_node->path = next->path.substr(0, len);
    new_node->cnt_subtree = next->cnt_subtree + 1;
    new_node->cnt_this = 1;
    new_node->index = idx;

    next->path = next->path.substr(len, next->path.size());
    root->children[s[curstrpos]] = new_node;
    root->cnt_subtree++;

    new_node->children[next->path[0]] = next;

    return;
}

int find_kth_with_prefix(Node* root, string& s, int k, int curstrpos = 0) {
    if (curstrpos >= s.size()) {
        if (k < root->cnt_this) {
            return root->index;
        }
        k -= root->cnt_this;
        for (auto& [symbol, next] : root->children) {
            if (next->cnt_subtree > k) {
                return find_kth_with_prefix(next, s, k, curstrpos);
            }
            k -= next->cnt_subtree;
        }
        return -1;
    }

    if (!root->children.count(s[curstrpos]) || root->children[s[curstrpos]]->cnt_subtree < k) {
        return -1;
    }
    auto next = root->children[s[curstrpos]];
    for (int i = 0; i + curstrpos < s.size() && i < next->path.size(); i++) {
        if (s[curstrpos + i] != next->path[i]) {
            return -1;
        }
    }
    return find_kth_with_prefix(next, s, k, curstrpos + next->path.size());
}

void print(Node* root) {
    cerr << "path: " << root->path << endl;
    cerr << "cnt_subtree: " << root->cnt_subtree << endl;
    cerr << "cnt_this: " << root->cnt_this << endl;
    cerr << "index: " << root->index << endl;
    for (auto& [k, v] : root->children) {
        cerr << k << " : " << endl;
        print(v);
    }
    cerr << "-----" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    Node* root = new Node{};
    int n, q;
    cin >> n >> q;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        add(root, s, i);
    }

    print(root);

    while (q--) {
        int k;
        string s;
        cin >> k >> s;
        k--;
        cout << find_kth_with_prefix(root, s, k) + 1 << "\n";
    }

    return 0;
}