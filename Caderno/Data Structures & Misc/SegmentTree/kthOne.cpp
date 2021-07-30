int find_kth(int v, int tl, int tr, int k) {
    if (k > tree[v])
        return -1;
    if (tl == tr)
        return tl;
    int tm = (tl + tr) / 2;
    if (tree[node*2] >= k)
        return find_kth(node*2, tl, tm, k);
    else 
        return find_kth(node*2+1, tm+1, tr, k - tree[node*2]);
}