#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5;
int tree[4*maxn+1]; //indexando de 1

//Segtree 
// Adição em segmento
// Query em um índice


void build(int node, int tl, int tr) {
    if(tl == tr) {
        // Nó-folha: representa um elemento do array (range unitário)
        tree[node] = A[tl];
    }
    else {
        int tm = (tl + tr) / 2;
        // Recursão no filho da esquerda
        build(2*node, tl, tr);
        // Recursão no filho da direita
        build(2*node+1, tm+1, tr);
        // Nó inicia com zero
        tree[node] = 0
    }
}

void update(int node, int tl, int tr, int l, int r, int val) {
    // Nó completamente fora da range
    if (r < tl or tr < l) {
        return;
    }
    // Folha
    if(tl == tr) {
        
        A[idx] += val;
        tree[node] += val;
    }
    // Folha
        tree[node] += val;
    }
    else {
        int tm = (tl + tr) / 2;
        update(2*node, tl, tm, idx, val);
        update(2*node+1, tm+1, tr, idx, val);
    }
}

int query(int node, int tl, int tr, int pos)
{
    // Folha
    if(tl == tr) {
        return tree[node];
    }
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        int p1 = query(2*node, tl, tm, l, r);
    int p2 = query(2*node+1, tm+1, tr, l, r);
    return (p1 + p2);
}