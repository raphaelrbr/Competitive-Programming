/*
Os vértices de A são numerados de 0 à n - 1.
 Os vértices de B são numerados de 0 à m - 1.
 O vetor matchA[] será usado para guardar o vértice
em B que está emparelhado com o respectivo vértice
de A (no início devemos ter -1).
 O vetor matchB[] será usado para guardar o vértice
em A que está emparelhado com o respectivo vértice
de B (no início devemos ter -1).
 O vetor marcB[] será usado para marcar os vértices de
B que já foram visitados pela DFS.
 O vetor de vectors grafoA[][] será usado para guardar
a lista de adjacências dos vértices de A (contendo os
vértices de B).
*/


void fastkun() {
    bool aux = true;
    int resp = 0;
        while(aux) {
        for(int j = 0; j<m; j++) marcB[j] = 0;
        aux = false;
        for(int i = 0; i <n; i++) {
            if(matchA[i] != -1) continue;
            if(dfs(i)) {
                resp++;
                aux = true;
            }
        }
    }
}

bool dfs(int v){
    for(int i =0; i < grafoA[v].size(); i++) {
        int viz = grafoA[v][i];
        if(marcB[viz] == 1) continue;
        marcB[viz] = 1;

        if(matchB[viz] == -1 || dfs(matchB[viz])) {
            matchB[viz] = v;
            matchA[v] = viz;
            return true;
        }
    }
    return false;
}