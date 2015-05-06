#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stack>
#include <sstream>
#include <map>
#include <algorithm>
#include <queue>
#include <limits.h>

using namespace std;
typedef pair<int, int> point;
int dis[1000][1000];
int dp[1000];
int main(){
     freopen("./input.txt", "r", stdin);
    int N;
    cin >> N;
    vector<point> data;
    for(int i=0; i<N; i++){
        int x, y;
        cin >> x >>y;
        data.push_back(point(x, y));
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            dis[i][j] = min(abs(data[i].first - data[j].first), abs(data[i].second - data[j].second));
        }
    }

    for(int i=0; i<N; i++){
        dp[i] = INT_MAX;
    }
    dp[0] = 0;

    for(int i=0; i<N; i++){
        for(int j=0; j<i; j++){
            dp[i] = min(dp[i], dp[j] + dis[j][i]);
        }
    }
    cout << dp[N-1] << endl;
    return 0;
}
