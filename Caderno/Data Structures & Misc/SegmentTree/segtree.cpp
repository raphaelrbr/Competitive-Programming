#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5;
int tree[4*maxn+1]; //indexando de 1

// Segtree básica de soma em range

void build(int node, int tl, int tr) {
    // Nó-folha: representa um elemento do array (range unitário)
    if(tl == tr) {
        tree[node] = A[tl];
    }
    else {
        int mid = (tl + tr) / 2;
        // Recursão no filho da esquerda
        build(2*node, tl, mid);
        // Recursão no filho da direita
        build(2*node+1, mid+1, end);
        // Nó guarda a soma dos dois filhos
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}

void update(int node, int tl, int tr, int idx, int val) {
    // Folha
    if(tl == tr) {
        A[idx] += val;
        tree[node] += val;
    }
    else {
        int mid = (tl + tr) / 2;
        if(tl <= idx and idx <= mid) {
            // Recursão filho da esquerda
            update(2*node, tl, mid, idx, val);
        }
        else {
            // Recursão filho da direita
            update(2*node+1, mid+1, tr, idx, val);
        }
        // Guarda soma dos dois filhos
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}

int query(int node, int tl, int tr, int l, int r)
{
    // Nó completamente fora da query
    if(r < tl or tr < l) {
        return 0;
    }
    // Nó completamente dentro
    if(l <= tl and tr <= r) {
        return tree[node];
    }
    // Nó parcialmente dentro
    int mid = (tl + tr) / 2;
    int p1 = query(2*node, tl, mid, l, r);
    int p2 = query(2*node+1, mid+1, tr, l, r);
    return (p1 + p2);
}