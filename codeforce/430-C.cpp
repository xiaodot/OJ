#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

vector <int> G[100001];
int initial[100001];
int dest[100001];
vector <int> flip;
bool used[100001];

void dfs(int v, int even, int odd, int level){
    used[v] = true;
    if((level&1) == 0) initial[v] = (even + initial[v])&1;
    else initial[v] = (odd + initial[v])&1;
    if(dest[v] != initial[v]) {
        initial[v] ^= 1;
        flip.push_back(v);
        for(int i=0; i<G[v].size(); i++){
            int u = G[v][i];
            if(!used[u]) dfs(u, even+((level+1)&1), odd+(level&1), level+1);
        }
    }
    else{
        for(int i=0; i<G[v].size(); i++){
            int u = G[v][i];
            if(!used[u]) dfs(u, even, odd, level+1);
        }
    }
}

int main(){
    freopen("../in.txt", "r", stdin);
    int n;
    cin >> n;
    for(int i=1; i<=n-1; i++){
        int from, to;
        cin >> from >> to;
        G[from].push_back(to);
        G[to].push_back(from);
    }
    for(int i=1; i<=n; i++){
        cin >> initial[i];
    }
    for(int i=1; i<=n; i++){
        cin >> dest[i];
    }
    fill(used, used+100001, false);
    dfs(1, 0, 0, 0);
    cout << flip.size() << endl;
    for(int i=0; i<flip.size(); i++){
        cout << flip[i] << endl;
    }
    return 0;
}
