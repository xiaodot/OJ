

//3n+1
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <limits.h>

using namespace std;

typedef long long LL;

int main(){
    //freopen("../in.txt", "r", stdin);
    int n;
    while(cin >> n){
        int res = 0;
        while(n != 1){
            if((n&1)== 0) n = n>>1;
            else n = (3*n + 1)>>1;
            res++;
        }
        cout << res << endl;
    }
    return 0;
}

//黑白球
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <limits.h>

using namespace std;

typedef long long LL;

int main(){
    //freopen("../in.txt", "r", stdin);
    int n, m;
    while(cin >> n >> m){
        if((m&1) == 0)  cout << "WHITE" << endl;
        else cout << "BLACK" << endl;
    }
    return 0;
}

//进制转换
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <limits.h>
#include <map>
#include <math.h>
#include <vector>

using namespace std;

typedef long long LL;

int pow(int i, int j){
    int res = 1;
    for(int k=1; k<=j; k++){
        res = res*i;
    }
    return res;
}

int main(){
   // freopen("../in.txt", "r", stdin);
    int T;
    cin >> T;
    for(int test = 1; test <= T; test++){
        string str, str1, str2;
        map <char, int> map1, map2;
        vector <char> res;
        cin >> str >> str1 >> str2;
        int len, len1, len2;
        len = str.length();
        len1 = str1.length();
        len2 = str2.length();
        for(int i=0; i<len1; i++){
            map1[str1[i]] = i;
        }

        int n = 0;
        for(int i=0; i<len; i++){
            n += map1[str[i]]*pow(len1, len-1-i);
        }
        cout << "Case #" << test << ": ";
        while(n > 0){
            int temp = n%len2;
            res.push_back(str2[temp]);
            n = n/len2;
        }
        for(int i=res.size()-1; i>=0; i--){
            cout << res[i];
        }

        cout << endl;
    }

    return 0;
}

//高斯公式
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <limits.h>
#include <map>
#include <math.h>
#include <vector>

using namespace std;

typedef long long LL;


int main(){
    //freopen("../in.txt", "r", stdin);
    long long  n;
    while(cin >> n){
        long long x, y, res = 0;
        for(y=1; y<sqrt((double)2*n); y++){
            long long temp = 2*n - y*y;
            if(temp%y == 0){
                temp = temp/y + 1;
                if(temp >=2 && temp%2 == 0) res++;
            }
        }
        cout << res;
        cout << endl;
    }
    return 0;
}

//末三位数
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <limits.h>
#include <map>
#include <math.h>
#include <vector>

using namespace std;

typedef vector<int> vec;
typedef vector<vec> mat;
typedef long long LL;

const int MOD = 1000;

mat mul(mat &A, mat &B){
    mat C(A.size(), vec(B[0].size()));
    for(int i = 0; i < A.size(); i++){
        for(int k = 0; k < B.size(); k++){
            for(int j = 0; j<B[0].size(); j++){
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        }
    }
    return C;
}

mat pow(mat A, LL n){
    mat B(A.size(), vec(A.size()));
    for(int i = 0; i<A.size(); i++){
        B[i][i] = 1;
    }
    while(n > 0){
        if(n & 1)   B = mul(B, A);
        A = mul(A, A);
        n >>= 1;
    }
    return B;
}

int main(){
//    freopen("../in.txt", "r", stdin);
    LL n;
    while(cin >> n){
        mat A(2, vec(2, 0));
        A[0][0] = 3;
        A[0][1] = 5;
        A[1][0] = 1;
        A[1][1] = 3;
        A = pow(A, n);
        printf("%03d\n", (A[0][0]*2 + MOD - 1) % MOD);
    }
    return 0;
}

//最小向量乘积
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <limits.h>
#include <map>
#include <math.h>
#include <vector>

using namespace std;

typedef vector<int> vec;
typedef vector<vec> mat;
typedef long long LL;

const int MOD = 1000;

bool cmp(int i, int j){
    return i<j;
}

int main(){
    //freopen("../in.txt", "r", stdin);
    int n;
    int a[100000], b[100000];
    while(cin >> n){
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        for(int i=0; i<n; i++){
            cin >> b[i];
        }
        sort(a, a+n);
        sort(b, b+n, cmp);
        LL res = 0;
        for(int i = 0; i < n; i++){
            res += (LL)a[i]*b[n-i-1];
        }
        cout << res << endl;
    }
    return 0;
}



//做游戏
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <limits.h>
#include <map>
#include <math.h>
#include <vector>

using namespace std;

typedef vector<int> vec;
typedef vector<vec> mat;
typedef long long LL;

const int MOD = 1000;

bool cmp(int i, int j){
    return i<j;
}

int main(){
//    freopen("../in.txt", "r", stdin);
    int n;
//    int a[100000], sum[100010], opt[100010];
    int a[100000];
    LL sum, opt[4];
    while(cin >> n){
        memset(a, 0, sizeof(a));
//        memset(sum, 0, sizeof(sum));
//        memset(opt, 0, sizeof(opt));
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        sum = 0;
        opt[0] = opt[1] = opt[2] = opt[3] = 0;
        for(int i=n-1; i>=0; i--){
            sum += (LL)a[i];
            for(int j=1; j<=3; j++){
                opt[0] = max(opt[0], sum-opt[j]);
            }
            opt[3] = opt[2];
            opt[2] = opt[1];
            opt[1] = opt[0];
            opt[0] = 0;
        }
        cout << opt[1] << endl;
    }
    return 0;
}

//绝对值最小
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;


typedef long long LL;

int main(){
    //freopen("../in.txt", "r", stdin);
    int n;
    vector <int> a;
    vector <int> b;
    while(cin >> n){
        int res;
        for(int i=0; i<n; i++){
            int t;
            cin >> t;
            if(t < 0) a.push_back(t);
            else b.push_back(t);
        }
        int len1, len2;
        len1 = a.size(), len2 = b.size();
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        if(len1 == 0){
            res = 2*b[0];
        }
        else if(len2 == 0){
            res = -2*a[len1-1];
        }
        else{
            res = 2*min(b[0], -a[len1-1]);
            for(int i=len1-1, j=0; i>=0 && j<=len2-1; ){
                int sum = a[i] + b[j];
                if(sum == 0){
                    res = 0;
                    break;
                }
                else if(sum > 0){
                    res = min(res, sum);
                    i--;
                }
                else{
                    res = min(res, -sum);
                    j++;
                }
            }
        }
        cout << res << endl;
        a.clear();
        b.clear();
    }
    return 0;
}

//眼睛的颜色
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;


typedef long long LL;

int main(){
    //freopen("../in.txt", "r", stdin);
    int res[10010];
    int n;
    while(cin >> n){
        int cnt = 0;
        memset(res, -1, sizeof(res));
        for(int i=0; i<n; i++){
            int d;
            cin >> d;
            if(!d)  {
                cnt++;
                res[i] = 0;
            }
        }
        for(int i=0; i<n; i++){
            if(res[i] == 0) cout << cnt;
            else cout << -1;
            if(i!=n-1) cout << " ";
        }
        cout << endl;
    }
    return 0;
}

//2的补码
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <limits.h>
#include <map>
#include <math.h>
#include <vector>

using namespace std;


typedef long long ll;

ll getOneNum(ll a){
    if(a == 0) return 0;
    if(a < 0) {
        return 32*(-a) - getOneNum(-a-1);
    }
    ll ans = 0;
    int k, i, j;
    ll v, bit, lv;
    for(k = 0, v = a; v; v >>= 1){
        k++;
    }
    lv = 0;
    for(i = 0, bit=1, v=a>>1; i < k; i++, bit<<=1, v>>=1){
      if(a&bit){
        ans += v*(1<<i);
        ans += lv+1;
        lv |= bit;
      }
      else{
        ans += v*(1<<i);
      }
    }
    return ans;
}

int main(){
    //freopen("../in.txt", "r", stdin);
    ll a, b;
    while(cin >> a >> b){
        if(b < 0){
            cout << getOneNum(a) - getOneNum(b+1) << endl;
        }
        else if(a < 0){
            cout << getOneNum(a) + getOneNum(b) << endl;
        }
        else if(a != 0){
            cout << getOneNum(b) - getOneNum(a-1) << endl;
        }
        else{
            cout << getOneNum(b) << endl;
        }
    }

//    int k = 2;
//    cout << -k << endl;
//    for(int i=1; i<10; i++){
//        printf("%X %X\n", -i, ~(i-1));
//    }
    return 0;
}
