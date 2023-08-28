#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
int ca, cb, n;
map<pii, vector<int>> path;
string rst[] = {"", "fill A", "fill B", "empty A", "empty B", "pour A B", "pour B A"};

/*
 * fill A: 1
 * fill B: 2
 * empty A: 3
 * empty B: 4
 * pour A B: 5
 * pour B A: 6
 */
int main() {
    cin >> ca >> cb >> n;
    queue<pii> q;
    q.emplace(0, 0);
    while (!q.empty()) {
        int a = q.front().first, b = q.front().second;
        q.pop();
        if (b == n) {
            for (int i: path[make_pair(a, b)]) {
                cout << rst[i] << endl;
            }
            cout << "empty A" << endl;
            cout << "success" << endl;
            break;
        }
        if (!path.count(make_pair(ca, b))) {
            path[make_pair(ca, b)] = path[make_pair(a, b)];
            path[make_pair(ca, b)].push_back(1);
            q.emplace(ca, b);
        }
        if (!path.count(make_pair(a, cb))) {
            path[make_pair(a, cb)] = path[make_pair(a, b)];
            path[make_pair(a, cb)].push_back(2);
            q.emplace(a, cb);
        }
        if (!path.count(make_pair(0, b))) {
            path[make_pair(0, b)] = path[make_pair(a, b)];
            path[make_pair(0, b)].push_back(3);
            q.emplace(0, b);
        }
        if (!path.count(make_pair(a, 0))) {
            path[make_pair(a, 0)] = path[make_pair(a, b)];
            path[make_pair(a, 0)].push_back(4);
            q.emplace(a, 0);
        }
        int na = a, nb = b;
        if (nb + a > cb) {
            na = nb + a - cb;
            nb = cb;
        } else {
            nb = nb + a;
            na = 0;
        }
        if (!path.count(make_pair(na, nb))) {
            path[make_pair(na, nb)] = path[make_pair(a, b)];
            path[make_pair(na, nb)].push_back(5);
            q.emplace(na, nb);
        }
        na = a, nb = b;
        if (na + b > ca) {
            nb = na + b - ca;
            na = ca;
        } else {
            na = na + b;
            nb = 0;
        }
        if (!path.count(make_pair(na, nb))) {
            path[make_pair(na, nb)] = path[make_pair(a, b)];
            path[make_pair(na, nb)].push_back(6);
            q.emplace(na, nb);
        }
    }
    return 0;
}
/*
 * fill A: 1
 * fill B: 2
 * empty A: 3
 * empty B: 4
 * pour A B: 5
 * pour B A: 6
 */
