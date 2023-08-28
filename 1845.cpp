#include <bits/stdc++.h>

using namespace std;
vector<int> heap;
#define ot cout << heap[1] << endl
int n = 0;

void up(int k) {
    while (k > 1) {
        int i = k / 2;
        if (heap[i] > heap[k]) swap(heap[i], heap[k]);
        else break;
        k = i;
    }
}

void down(int k) {
    while (k + k <= n) {
        int i = k + k;
        if (i + 1 <= n && heap[i + 1] < heap[i]) i++;
        if (heap[i] < heap[k]) {
            swap(heap[i], heap[k]);
            k = i;
        } else break;
    }
}

void del(int pos) {
    swap(heap[pos], heap[n]);
    n--;
    up(pos);
    down(pos);
}

void ins(int val) {
    n++;
    if (heap.size() < n + 1) heap.resize(n + 2);
    heap[n] = val;
    up(n);
}

int main() {
    heap.push_back(-1);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int tmp;
        cin >> tmp;
        ins(tmp);
    }
    for (int i = 1; i < t; ++i) {
        del(1);
    }
    for (int i = 1; i <= t; ++i) {
        cout << heap[i] << endl;
    }
    return 0;
}

