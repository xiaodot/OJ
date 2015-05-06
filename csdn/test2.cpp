#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

struct edge{
    int to;
    int cost;
//    bool operator() (edge e1, edge e2){return e1.cost > e2.cost;}
};

bool operator<(const edge &x, const edge &y)
{
    return x.cost > y.cost;
}


priority_queue <edge, vector<edge> > que;

vector <edge> G[500];

typedef long long LL;

bool dfs(int i, int d, int m){

    if(m-1 <= 0 && d>=0) return true;
    if(m-1 >= 0 && d<0) return false;

    for(int j=0; j<G[i].size(); j++){
        edge e = G[i][j];
        que.push(e);
    }
    if(que.empty()) return false;
    else{
        edge e = que.top();
        que.pop();
        return dfs(e.to, d-2*e.cost, m-1);
    }

}


int main(){
    freopen("../in.txt", "r", stdin);
    int n, q, d;
    cin >> n;
    while(n != 0){
        cin >> q >> d;
        for(int i=0; i<n-1; i++){
            int from, to, cost;
            edge e;
            cin >> from >> to >> cost;
            e.to = to;
            e.cost = cost;
            G[from].push_back(e);
        }
        for(int i=0; i<q; i++){
            int t, m;
            cin >> t >> m;
            while(!que.empty()) que.pop();
            if(dfs(0, t-2*d, m)) cout << "I love you";
            else cout << "Go to the hell";
            if(i!=q-1) cout << endl;
        }
        cin >> n;
    }
    return 0;
}
