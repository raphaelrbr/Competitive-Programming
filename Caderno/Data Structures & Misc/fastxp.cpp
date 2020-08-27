#include "bits/stdc++.h"
using namespace std;

int n;

struct Matrix{
    vector<vector<int>> a = vector<vector<int>>(n, vector<int>(n));
    
    Matrix operator *(const Matrix& other) {
        Matrix product;
        vector<vector<long long>> tmp(n, vector<long long>(n));
        
        for (int i = 0; i<n; i++) {
            for (int j = 0; j<n; j++) {
                for (int k = 0; k<n; k++) {
                    tmp[i][k] +=  a[i][j] *1LL* other.a[j][k];
                    if(tmp[i][k] >= 8LL * MOD * MOD)
                        tmp[i][k] -= 8LL * MOD * MOD;
                    
                }
            }
        }
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                product.a[i][j] = tmp[i][j] % MOD;
            }
        }
        return product;
    }
};

Matrix expo_power(Matrix a, int k){
    Matrix product;
    for(int i = 0; i<105; i++) product.a[i][i] = 1;
    while(k){
        if(k%2) product = product * a;
        a = a*a;
        k /= 2;
    }
    return product;
}
