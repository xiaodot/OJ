#include <iostream>
#include <stdio.h>
#include <set>

using namespace std;

int main(){
//    freopen("../in.txt", "r", stdin);
    int n, m;
    set <int> chat, notLeader, uncertain;
    set <int> :: iterator ite;
    cin >> n >> m;
    getchar();
    char pre_c;
    int pre_d;
    for(int i=0; i<m; i++){
        char c;
        int d;
        c = getchar();
        cin >> d;
        getchar();
        if(c == '+') {
            if(i>0 && pre_c=='-' && pre_d!=d) {
                notLeader.insert(d);
                notLeader.insert(pre_d);
            }
            else if(!chat.empty()) notLeader.insert(d);
            else {
                uncertain.insert(d);
//                if(uncertain.size() + notLeader.size() == n){
//                    notLeader.insert(uncertain.begin(), uncertain.end());
//                    uncertain.clear();
//                }
            }
            chat.insert(d);
        }
        else {
            if(!chat.count(d)){
                notLeader.insert(uncertain.begin(), uncertain.end());
                uncertain.clear();
            }
            else {
                chat.erase(d);
            }
            if(!chat.empty()) notLeader.insert(d);
            else {
                uncertain.insert(d);
//                if(uncertain.size() + notLeader.size() == n){
//                    notLeader.insert(uncertain.begin(), uncertain.end());
//                    uncertain.clear();
//                }
            }
        }
        pre_c = c;
        pre_d = d;
    }
    cout << n-notLeader.size() << endl;
    for(int i=1; i<=n; i++){
        if(!notLeader.count(i)) cout << i << " ";
    }
    return 0;
}
