#include <iostream>
#include <stdio.h>
#include <vector>
#include <stack>
#include <cstring>
#include <algorithm>

#define MAX_N 100000
#define INF 2000000000

using namespace std;

vector <int> G[MAX_N];
stack <int> s;
int DFN[MAX_N], Low[MAX_N];
//bool instack[MAX_N];
int cpn[MAX_N];
int index = 0, k = 0;

void tarjan(int v){
    s.push(v);
//    instack[v] = true;
    Low[v] = DFN[v] = ++index;
    for(int i=0; i<G[v].size(); i++){
        int u = G[v][i];
        if(!DFN[u]) {
            tarjan(u);
            Low[v] = min(Low[v], Low[u]);
        }
        else if(cpn[u] == -1){      //u is still in the stack s;
            Low[v] = min(Low[v], DFN[u]);
        }
    }
    if(Low[v] == DFN[v]){
        while(s.top() != v){
//            instack[s.top()] = false;
            cpn[s.top()] = k;
            s.pop();
        }
//        instack[s.top()] = false;
        cpn[s.top()] = k;
        s.pop();
        k++;
    }
}
int main(){
//    freopen("../in.txt", "r", stdin);
    int n, m;
    int cost[MAX_N];
    vector <int> scc[MAX_N];
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> cost[i];
    }
    cin >> m;
    for(int i=0; i<m; i++){
        int from, to;
        cin >> from >> to;
        G[from-1].push_back(to-1);
    }
//    fill(instack, instack+MAX_N, false);
    memset(DFN, 0, sizeof(DFN));
    memset(cpn, -1, sizeof(cpn));

    for(int i=0; i<n; i++){
        if(!DFN[i])  tarjan(i);
    }
    for(int i=0; i<n; i++){
        scc[cpn[i]].push_back(cost[i]);
    }
    long long res1 = 0, res2=1;
    for(int i=0; i<k; i++){
        sort(scc[i].begin(), scc[i].end());
        res1 += scc[i][0];
        int temp = 0;
        for(int j=0; j<scc[i].size(); j++){
            if(scc[i][j] == scc[i][0]) temp++;
        }
        res2 = res2*temp%1000000007;
    }
    cout << res1 << " " << res2<< endl;
    return 0;
}
