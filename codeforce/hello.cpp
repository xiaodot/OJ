#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <limits.h>
#include <map>
#include <math.h>
#include <vector>
#include <set>

using namespace std;

typedef vector<int> vec;
typedef vector<vec> mat;
typedef long long LL;

const int MOD = 1000;

bool cmp(int i, int j){
    return i<j;
}

int main(){
    freopen("../in.txt", "r", stdin);
    int n;
    map <int, int> mymap;
    vector <int> cur;
//    vector <int> :: iterator ite;
//    map <int, int> :: iterator ite2;
    while(cin >> n){
        int dat, start = 0;
        LL res = 0;
        for(int i=0; i<n; i++){
            cin >> dat;
            if(mymap.find(dat) != mymap.end()){
                int index = mymap[dat];
                for(int j=0; j<=index-start; j++){
                    mymap.erase(cur[j]);
                }
                cur.erase(cur.begin(), cur.begin()+index-start+1);
                cur.push_back(dat);
                mymap[dat] = i;
                res += (LL)cur.size();
                start = index + 1;
            }
            else{
                cur.push_back(dat);
                mymap[dat] = i;
                res += (LL)cur.size();
            }
        }
        cout << res << endl;
        mymap.clear();
        cur.clear();
    }
    return 0;
}


