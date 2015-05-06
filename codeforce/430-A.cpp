#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> P;

bool comp(P x, P y){
    return x.first<y.first;
}
int main(){
//    freopen("../in.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    vector <pair<int, int> > point;
    for(int i=0; i<n; i++){
        pair <int, int> P;
        cin >> P.first;
        P.second = i;
        point.push_back(P);
    }
    sort(point.begin(), point.end(), comp);
    int color[100];
    for(int i=0; i<n; i++){
        int index = point[i].second;
        color[index] = i%2;
    }
    for(int i=0; i<n; i++){
        cout << color[i] << " ";
    }
    return 0;
}
