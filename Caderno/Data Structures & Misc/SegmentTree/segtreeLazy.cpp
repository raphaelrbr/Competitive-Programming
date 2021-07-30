#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5;
int tree[4*maxn];

//Assignment em segmento, query por ponto

void build(int node, int tl, int tr) {
    if(tl == tr) {
        // Nó-folha: representa um elemento do array (range unitário)
        tree[node] = A[tl];
    }
    else {
        int tm = (tl + tr) / 2;
        // Recursão no filho da esquerda
        build(2*node, tl, tm);
        // Recursão no filho da direita
        build(2*node+1, tm+1, tr);
        // Inicializamos com zero nós intermediários
        tree[node] = 0
    }
}

void push(int node) {
    if (marked[node]) {
        tree[node*2] = tree[node*2+1] = tree[node];
        marked[node*2] = marked[node*2+1] = true;
        marked[node] = false;
    }
}

void update(int node, int tl, int tr, int l, int r, int new_val) {
    // Nó completamente fora da query
    if(r < tl or tr < l) {
        return;
    // Nó completamente dentro da query
    if (l <= start and end <= r) {
        tree[node] = new_val;
        marked[node] = true;
    } else {
        push(node);
        int tm = (tl + tr) / 2;
        update(node*2, tl, tm, l, r, new_val);
        update(node*2+1, tm+1, tr, l, r, new_val);
    }
}

int query(int node, int tl, int tr, int pos)
{
    // Folha
    if(tl == tr) {
       return t[node];
    }
    push(node);
    int tm = (tl + tr) / 2;
    if (pos <= tm) return query(2*node, tl, tm, l, r);
    else return query(2*node+1, tm+1, tr, l, r);
}
