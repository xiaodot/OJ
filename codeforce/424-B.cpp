#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;

typedef pair <double, int> P;

bool comp(P city1, P city2){
    return city1.first < city2.first;
}

int main(){
//    freopen("../in.txt", "r", stdin);
    int n, s;
    cin >> n >> s;
    int x, y, p;
    double dis, r;
    vector <P> cities;
    P city;
    for(int i=0; i<n; i++){
        cin >> x >> y >> p;
        dis  = sqrt((double)x*x + y*y);
        city.first = dis;
        city.second = p;
        cities.push_back(city);
    }
    sort(cities.begin(), cities.end(), comp);

    bool flag = false;
    for(vector <P> :: iterator ite = cities.begin(); ite<cities.end(); ite++){
        P temp = *ite;
        r = temp.first;
        s += temp.second;
        if(s>=1000000) {
            flag = true;
            break;
        }
    }
    if(flag)    printf("%.7f\n", r);
    else printf("-1\n");
    return 0;
}
