#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5;

vector<int> tree[4*maxn+1]; // Indexando de 1
void build(int node, int tl, int tr) {
    if (tl == tr) {
        tree[v] = vector<int>(1, a[tl]);
    } else { 
        int tm = (tl + tr) / 2;
        build(2*node, tl, tm);
        build(2*node+1, tm+1, tr);
        merge(t[node*2].begin(), tree[node*2].end(), tree[node*2+1].begin(), tree[node*2+1].end(),
              back_inserter(tree[v]));
    }
}

int query(int node, int tl, int tr, int l, int r, int x) {
    if(tl > tr or tl > r or tr < l)
        return INF;
    if(l <= tl and tr <= r) {
        vector<int>::iterator pos = lower_bound(tree[node].begin(), tree[node].end(), x);
        if (pos != tree[node].end())
            return *pos;
        return INF;
    }
    int tm = (tl + tr) / 2;
    return min(query(2*node, tl, tm, l, r, x), 
               query(2*node+1, tm+1, tr, l, r, x));
}