#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <math.h>
#include <cstring>

using namespace std;

typedef pair<int, int> P;

int a[100001], primeNum[100001];
vector <P> b, c;

void prime(int n) {
    for(int i=2; i<=sqrt(n); i++){
        if(primeNum[i]){
            for(int j=i+i; j<n; j+=i){
                primeNum[j] = 0;
            }
        }
    }
}

bool comp(P x, P y){
    return x.first<y.first;
}


int main(){
    freopen("../in.txt", "r", stdin);
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        b.push_back(make_pair(a[i], i));
    }
    fill(primeNum, primeNum+n, 1);
    prime(n);
    sort(b.begin(), b.end());

    for(int i=1; i<=n; i++){
        if(a[i] != i){
            int s = i, t = b[i-1].second;
            int step = t - s;
            if(primeNum[step + 1]) {
                c.push_back(make_pair(a[s], a[t]));
                swap(a[s], a[t]);
                b[a[s]-1].second = t;
                b[a[t]-1].second = s;
            }
            else {
                if(step%2 == 1){
                    swap(a[s], a[s+1]);
                    c.push_back(make_pair(a[s], a[s+1]));
                    b[a[s]-1].second = s + 1;
                    b[a[s+1]-1].second = s;
                    s = s + 1;
                    step += 1;
                    for(int j=2; j<=step/2; j++){
                        if (primeNum[j]&&primeNum[step-j]) {
                            int m = j + s - 1;
                            c.push_back(make_pair(a[s], a[m]));
                            c.push_back(make_pair(a[s], a[t]));
                            c.push_back(make_pair(a[m], a[t]));
                            b[a[s]-1].second = t;
                            b[a[t]-1].second = s;
                            break;
                        }
                    }
                    c.push_back(make_pair(a[s-1], a[s]));
                    swap(a[s], a[s-1]);
                }
                else{
                    step += 2;
                    for (int j=2; j<=step/2; j++) {
                        if (primeNum[j]&&primeNum[step-j]) {
                            int m = j + s - 1;
                            c.push_back(make_pair(a[s], a[m]));
                            c.push_back(make_pair(a[s], a[t]));
                            c.push_back(make_pair(a[m], a[t]));
                            b[a[s]-1].second = t;
                            b[a[t]-1].second = s;
                            break;
                        }
                    }
                }
            }
        }
    }

    cout << c.size() << endl;
    for(int i=0; i<c.size(); i++){
        cout << c[i].first << " " << c[i].second << endl;
    }

    return 0;
}
