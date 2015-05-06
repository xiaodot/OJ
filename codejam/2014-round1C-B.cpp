#include <functional>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <cctype>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <limits.h>

using namespace std;

#define PB push_back
#define MP make_pair

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef pair<int,int> PII;
typedef long long LL;
typedef unsigned long long ULL;

template <typename T> string to_string(T x){
    ostringstream oss;
    oss << x;
    oss.flush();
    return oss.str();
}



int main(){
    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    int T;
    cin >> T;
    vector <char> str[100];
    int res = 0;
    for(int test=1; test<=T; test++){
        vector <int> pos;
        for(int i=0; i<100; i++){
            str[i].clear();
        }
        int n;
        cin >> n;
        getchar();
        for(int i=0; i<n; i++){
            char c_pre = getchar();
            str[i].push_back(c_pre);
            char c = getchar();
            while((c != ' ') && (c != '\n')){
                if(c == c_pre) {
                    c = getchar();
                }
                else{
                    str[i].push_back(c);
                    c_pre = c;
                    c = getchar();
                }
            }
        }
        pos.push_back(0);
        for(int i=1; i<n; i++){
            pos[i] = i;
        }

    }
}
