#include <iostream>
#include <stdio.h>
#include <cstring>
#include <stack>
#include <vector>

using namespace std;

#define MAX_N 100000

vector <int> G[MAX_N], scc[MAX_N];
int dfn[MAX_N], low[MAX_N], sccn[MAX_N], k = 0, index = 0;
stack <int> s;

void targan(int v){
    low[v] = dfn[v] = ++index;
    s.push(v);
    for(int i=0; i<G[v].size(); i++){
        int u = G[v][i];
        if(!dfn[u]){
            targan(u);
            low[v] = min(low[v], low[u]);
        }
        else if(sccn[v] == -1) low[v] = min(low[v], dfn[u]);
    }
    if(low[v] == dfn[v]){
        while(s.top() != v){
            sccn[s.top()] = k;
            s.pop();
        }
        sccn[s.top()] = k;
        s.pop();
        k++;
    }
}


int main(){
    freopen("../in.txt", "r", stdin);
    //input the graph
    int n, m;
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int from, to;
        cin >> from >> to;
        G[from].push_back(to); //the index of vertexes are starting from 1
    }
    //run the algorithm targan();
    memset(dfn, 0, sizeof(dfn));
    memset(sccn, -1, sizeof(sccn));
    for(int i=1; i<=n; i++){
        if(!dfn[i]) targan(i);
    }
    // get the components
    for(int i=1; i<=n; i++){
        scc[sccn[i]].push_back(i);
    }
    //verify the algorithm
    for(int i=0; i<n; i++){
        cout << sccn[i+1] << " " ;
    }
    cout << endl;
    return 0;
}
