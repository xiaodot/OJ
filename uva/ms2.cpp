#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stack>
#include <sstream>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

int main(){
    freopen("./input.txt", "r", stdin);

    int T;
    cin >> T;

    for(int test=0; test<T; test++){
        int N, M;
        scanf("%d%d", &N, &M);
//        cin >> N >> M;
//        vector<int> sign;
        vector<int> modul_S;
        vector<vector<int> > modul_E;
        vector<long long> res;
        stack<int> tasks;

        for(int i=0; i<M; i++){
            int data;
            scanf("%d", &data);
//            cin >> data;
            tasks.push(data);
//            sign.push_back(data);
        }

        for(int i=0; i<N; i++){
            int S, data, num;
            scanf("%d%d", &S, &num);
//            cin >> S >> num;
            vector<int> elem;
            for(int i=0; i<num; i++){
//                cin >> data;
                scanf("%d", &data);
                elem.push_back(data);
            }
            modul_E.push_back(elem);
            modul_S.push_back(S);
            res.push_back(0);

        }



        map<int, vector<int> > mymap;
        for(int i=0; i<modul_S.size(); i++){
            if(mymap.count(modul_S[i])){
                mymap[modul_S[i]].push_back(i);
            }
            else{
                vector<int> elem;
                elem.push_back(i);
                mymap[modul_S[i]] = elem;
            }
        }
        while(!tasks.empty()){
            int sign_id = tasks.top();
            tasks.pop();
            if(mymap.count(sign_id)){
                vector<int> &find_result = mymap[sign_id];
                for(int i=0; i<find_result.size(); i++){
                    int index = find_result[i];
                    res[index]++;
                    for(int j=0; j<modul_E[index].size();j++) {
                        int sign = modul_E[index][j];
                        if(mymap.count(sign)){
                            tasks.push(sign);
                        }

                    }
                }
            }

//            for(int i=0; i<modul_S.size(); i++){
//                if(modul_S[i] == sign_id){
//                    res[i]++;
//                    for(int j=0; j<modul_E[i].size(); j++){
//                        tasks.push(modul_E[i][j]);
//                    }
//                }
//            }
        }
        for(int i=0; i<res.size(); i++){
            if(i!=res.size()-1) cout << res[i]%142857 << " ";
            else cout << res[i]%142857;
        }
        cout << endl;
    }
    return 0;
}
