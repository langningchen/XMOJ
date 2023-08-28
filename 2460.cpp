#include <bits/stdc++.h>

using namespace std;
int n, r;
vector<int> sq;

int main() {
    cin >> n >> r;
    for (int i = 1; i <= n; ++i) {
        sq.push_back(i);
    }
    bool fs = true;
    string prev;
    bool first = true;
    string ss;
    for (int i = 0; i < r; ++i) {
        if (!first) ss.push_back(' ');
        first = false;
        ss.append(to_string(sq[i]));
    }
    if (ss != prev) {
        prev = ss;
        printf("%s\n", prev.c_str());
    }
    while (next_permutation(sq.begin(), sq.end())) {
        fs = false;
        first = true;
        ss.clear();
        for (int i = 0; i < r; ++i) {
            if (!first) ss.push_back(' ');
            first = false;
            ss.append(to_string(sq[i]));
        }
        if (ss != prev) {
            prev = ss;
            printf("%s\n", prev.c_str());
        }
    }
    if (fs) {
        ss.clear();
        first = true;
        for (int i = 0; i < r; ++i) {
            if (!first) ss.push_back(' ');
            first = false;
            ss.append(to_string(sq[i]));
        }
        if (ss != prev) {
            prev = ss;
            printf("%s\n", prev.c_str());
        }
    }
    return 0;
}

