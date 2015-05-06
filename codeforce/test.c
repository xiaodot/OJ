#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>

using namespace std;

int main(){
    freopen("../in.txt", "r", stdin);
    int n, k, x;
    cin >> n >> k >> x;
    int color[100];
    int cnt[100];
    memset(cnt, 0, sizeof(cnt));
    int index = 0;
    int temp;
    cin >> temp;
    color[index] = temp;
    cnt[index]++;
    for(int i=1; i<n; i++){
        cin >> temp;
        if(temp == color[index]) cnt[index]++;
        else {
            color[index+1] = temp;
            cnt[++index]++;
        }
    }
    int ans=0;
    for(int i=0; i<=index; i++){
        int res = 0;
        if(color[i] == x && cnt[i] >= 2){
           res += cnt[i];
           for(int j=1; j<=index; j++){
                int l = i-j;
                int r = i+j;
                int sum = 0;
                if(l>=0) sum += cnt[l];
                if(r<=index) sum += cnt[r];
                if(sum >= 3){
                    res += sum;
                }
                else break;

           }
           ans = max(ans, res);
        }
    }
    cout << ans << endl;
}
