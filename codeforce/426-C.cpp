#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <cmath>
using namespace std;
int n,t,a[300];
priority_queue <int> q;
priority_queue <int, vector<int>, greater<int> > Q;
int main(){
    //freopen("test.in","r",stdin);
    cin >>n>>t;
    for (int i=0;i<n;i++) cin>>a[i];
    int res = -1000000000;
    for (int i=0;i<n;i++)
        for (int j=i;j<n;j++){
            while (!Q.empty()) Q.pop();
            while (!q.empty()) q.pop();
            int tres = 0;
            for (int k=i;k<=j;k++){
                tres += a[k];
                Q.push(a[k]);
            }
            for (int k=0;k<i;k++) q.push(a[k]);
            for (int k=j+1;k<n;k++) q.push(a[k]);
            for (int k=0;k<t;k++){
                int x = -1,y = -1;
                x = Q.top();
                if (!q.empty()){
                    y = q.top();
                    if (y > x){
                        tres = tres - x + y;
                        Q.pop();
                        Q.push(y);
                        q.pop();
                        q.push(x);
                    }
                }
            }
            res = max(res, tres);
        }
    cout<<res<<endl;
    return 0;
}
