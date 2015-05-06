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

long long gcd(long long a, long long b){
    if(a == 0) return b;
    if(b == 0) return a;
    return gcd(b, a%b);
}

int main(){
    freopen("A-large-practice.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int T;
    cin >> T;
    for(int test=1; test<=T; test++){
        long long P, Q;
        cin >> P;
        getchar();
        cin >> Q;
//        scanf("%lld\/%lld", &P, &Q);
        int p = 0, q =0;
        bool flag = true;
        long long factor = gcd(P, Q);
        P = P/factor;
        Q = Q/factor;
        while(Q>1){
            if((Q&1) == 0) {
                q++;
                Q = Q>>1;
            }
            else {
                flag = false;
                break;
            }

        }
        if(!flag)  printf("Case #%d: impossible\n", test);
        else{
            while(P!=0){
                P = P>>1;
                p++;
            }
            p = p-1;
            if(q-p > 40)  printf("Case #%d: impossible\n", test);
            else printf("Case #%d: %d\n", test, q-p);
        }

    }

}
