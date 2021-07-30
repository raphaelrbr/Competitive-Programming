#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5;
int tree[4*maxn+1];
int lazy[4*maxn+1];

//Adição em segmento, query pelo máximo

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
    t[node*2] += lazy[node];
    lazy[node*2] += lazy[node];
    t[node*2+1] += lazy[node];
    lazy[node*2+1] += lazy[node];
    lazy[node] = 0;
}

void update(int node, int tl, int tr, int l, int r, int val) {
    // Nó completamente fora da query
    if(r < tl or tr < l) {
        return;
    // Nó completamente dentro da query
    if (l <= tl && tr <= r) {
        tree[node] += val;
        lazy[node] += val;
    } else {
        push(node);
        int tm = (tl + tr) / 2;
        update(node*2, tl, tm, l, r, val);
        update(node*2+1, tm+1, tr, l, r, val);
        tree[node] = max(tree[node*2], tree[node*2+1]);
    }
}

int query(int node, int tl, int tr, int pos)
{
    // Nó completamente fora da query
    if(r < tl or tr < l) {
        return;
    // Nó completamente dentro da query
    if(l <= tl && tr <= r) {
       return t[v];
    }
    push(node);
    int tm = (tl + tr) / 2;
    return max(query(2*node, tl, tm, l, r),
                query(2*node+1, tm+1, tr, l, r));
}
