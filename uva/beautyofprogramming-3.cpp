#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <stdio.h>

using namespace std;

typedef pair<int, int> P;
struct Edge{
    int from, to, cost;
    Edge(int f, int t, int c):from(f), to(t), cost(c){}
};

int main(){
    freopen("../in.txt", "r", stdin);
    int T;
    cin >> T;

    for(int test=1; test<=T; test++){
        int N, M, Q;
        cin >> N >> M >> Q;
        vector<map<int, int> > users(N);
//        vector<Edge> edges;


        vector<int> genders(N);
        for(int i=0; i<N; i++){
            cin >> genders[i];
        }

        long long res = 0;
        vector<long long > ret;

        for(int i=0; i<M; i++){
            int from, to, cost;
            cin >> from >> to >> cost;
//            users[from].push_back(make_pair())
            from--;
            to--;
            users[from][to] = cost;
            users[to][from] = cost;

//            edges.push_back(Edge(from, to, cost));
            if(genders[from] != genders[to]) res += cost;
        }

        for(int i=0; i<Q; i++){
            int kind;
            cin >> kind;
            if(kind == 1){
                int id;
                cin >> id;
                id--;
                genders[id] = 1 - genders[id];
                for(map<int, int>::iterator it = users[id].begin(); it != users[id].end(); it++){
                    if(genders[it->first] == genders[id]){
//                        res -= users[id][it->first];
                        res -= it->second;
//                        it->second = 0;
//                        users[it->first][id] = 0;
                    }
                    else{
                        res += it->second;
                    }
                }
            }
            else if(kind == 2){
                int x, y, z;
                cin >> x >> y >> z;
                x--;
                y--;
                if(genders[x] != genders[y]){
                    res -= users[x][y] - z;
                }

                users[x][y] = z;
                users[y][x] = z;
            }
            else{
                ret.push_back(res);
            }
        }
        cout << "Case #" << test << ":" << endl;
        for(int i=0; i<ret.size(); i++){
            cout << ret[i] << endl;
        }
    }
    return 0;
}
