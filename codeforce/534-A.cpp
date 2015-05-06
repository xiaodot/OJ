#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    freopen("../in.txt", "r", stdin);
    int n;
    cin >> n;
    if(n==1 || n==2) {
        cout << 1 << endl << 1 << endl;
        return 0;
    }
    if(n==3){
        cout << 2 << endl;
        cout << 1 << " " << 3 << endl;
        return 0;
    }
    if(n==4) {
        cout << 4 << endl;
        cout << "2 4 1 3" << endl;
        return 0;
    }
//    int odd = n%2 ? n : n-1;
//    if(abs(odd-2) == 1) {
//        cout << n - 1 << endl;
//    }
//    else cout << n << endl;
    cout << n << endl;
    for(int i=1; i<=n; i+=2){
        cout << i << " ";
    }
//    if(n>=2 && abs(odd-2) != 1) cout << 2 << " ";
    for(int i=2; i<=n; i+=2){
        cout << i << " ";
    }
    return 0;
}
