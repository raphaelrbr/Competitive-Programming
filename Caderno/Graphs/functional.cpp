#Functional Graph functions

/*
pai[v] - vértice vizinho de v que está mais próximo de um ciclo que v.
paiCiclo[v] - vértice mais próximo de v, que está num ciclo (primeiro vértice que v alcança que está
num ciclo)
ciclo[v] - Índice do ciclo que o v alcança (colocaremos um índice para cada ciclo para diferenciá-los)
noCiclo[v] - Guarda se v está num ciclo ou não (V/F ou 0/1)
idNoCiclo[v] - Índice de v no ciclo. Caso v não esteja no ciclo podemos colocar -1
prof[v] - Profundidade na árvore, ou quantas arestas até v chegar no paiCiclo[v]
sub[v] - Quantidade de vértices na subárvore de v
*/




void lenhadora(){
    queue<int> fila;
    for(int i = 1; i<=n; i++)
        if(ingrau[i] == 0) fila.push(i), marc[i] = 1;

    while(!fila.empty()){
        int cur = fila.front(); fila.pop();
        processados.push_back(cur);
        sub[cur]++;

        int paicur = pai[cur];
        ingrau[paicur]--;
        sub[paicur] += sub[cur];
        if(ingrau[paicur] == 0)
            fila.push(paicur), marc[paicur] = 1;
    }

    qtdCiclos = 0;
    for(int i = 1; i<=n; i++)
        if(marc[i] == 0) acheiCiclo(i);
    
    for(int i = processados.size() - 1; i>=0; i--)
        int vcur = processados[i];
        int paicur = pai[vcur];

        paiCiclo[vcur] = paiCiclo[paicur];
        ciclo[vcur] = ciclo[paicur];
        noCiclo[vcur] = 0;
        idNoCilo[vcur] = -1;
        prof[vcur] = prof[paicur] = 1;

    }
}

void acheiCiclo(int v) {
    int idCiclo = ++qtdCiclos;
    int curId = 0;
    ini[idCiclo] = v;
    tam[idCiclo] = 0;
    ciclos[idCiclo].clear();
    while(marc[v] == 0) {
        marc[v] = 1;
        paiCiclo[v] = 1;
        ciclo[v] = idCiclo;
        idNoCiclo[v] = curId;
        ciclos[idCiclo].push_back(v);
        tam[idCiclo]++;
        prof[v] = 0;
        sub[v]++;

        v = pai[v];
        curId++;
    }
}


//Lenhadora para grafos nao direcionados
void lenhadora() {
    queue<int> fila;
    for(int i = 1; i<=n; i++)
        if(grau[i] == 1) fila.push(i), marc[i] = 1;

    while(!fila.empty()) {
        int cur = fila.front(); fila.pop();
        processados.push_back(cur);
        sub[cur]++;

        int paicur = achaPai(cur);
        pai[cur] = paicur;
        grau[paicur]--;
        sub[paicur] += sub[cur];
        if(grau[paicur] == 1)
            fila.push(paicur), marc[paicur] = 1;

    }

    qtdCiclos = 0;
    for(int i =1; i<=n; i++)
        if(marc[i] == 0) acheiCiclo(i);

    for(int i = processados.size() - 1; i>=0; i--) {
        int vcur = processados[i];
        int paicur = pai[vcur];

        paiCiclo[vcur] = paiCiclo[vcur];
        ciclo[vcur] = ciclo[paicur];
        noCiclo[vcur] = 0;
        idNoCiclo[vcur] = -1;
        prof[vcur] = prof[paicur] + 1;
    }
}


int achaPai(int v) {
    for(int i = 0; i < adj[v].size(); i++) {
        int viz = adj[v][i];
        if(marc[viz] == 0) return viz;
    }
    return -1;
}
void acheiCiclo(int v) {
    int vini = v;
    int idCiclo = ++qtdCiclos;
    int curId = 0;
    ini[idCiclo] = v;
    tam[idCiclo] = 0;
    ciclos[idCiclo].clear();
    while(marc[v] == 0){
        marc[v] = 1;
        pai[v] = achaPai(v);
        if(pai[v] == -1) pai[v] = vini;
        paiCiclo[v] = v;
        ciclo[v] = idCiclo;
        noCiclo[v] = 1;
        idNoCiclo[v] = curId;
        ciclos[idCiclo].push_back(v);
        tam[idCiclo]++;
        prof[v] = 0;
        sub[v]++;

        v = pai[v];
        curId++;
    }
}