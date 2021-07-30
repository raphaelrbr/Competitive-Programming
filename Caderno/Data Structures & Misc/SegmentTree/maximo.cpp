#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5;

// Segtree de máximo e o número de vezes que aparece
pair<int, int> tree[4*maxn+1]; // Indexando de 1

pair<int, int> combine(pair<int, int> a, pair<int, int> b) {
    if (a.first > b.first) 
        return a;
    if (b.first > a.first)
        return b;
    return make_pair(a.first, a.second + b.second);
}

void build(int node, int tl, int tr) {
    if(tl == tr)
    {
        // Nó folha
        tree[node] = make_pair(a[tl], 1);
    } 
    else 
    {
        int tm = (tl + tr) / 2;
        // Recursão filho esquerdo
        build(2*node, tl, tm);
        // Recursão filho direito
        build(2*node+1, tm+1, tr);
        // Combina os dois filhos
        t[node] = combine(t[node*2], t[node*2+1]);
    }
}

pair<int, int> int query(int node, int tl, int tr, int l, int r)
{
    if(r < tl or tr < l)
    {
        // Range representada pelo nó completamente fora da range da query
        make_pair(-INF, 0);
    }
    if(l <= tl and tr <= r)
    {
        // Range representada pelo nó completamente dentro do range da query
        return tree[node];
    }
    // range represented by a node is partially inside and partially outside the given range
    int tm = (tl + tr) / 2;
    pair<int,int> p1 = query(2*node, tl, tm, l, r);
    pair<int,int> p2 = query(2*node+1, tm+1, tr, l, r);
    return combine(p1,p2);
}