#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

int main(){
    freopen("in.txt", "r", stdin);
    double input;
    while(cin >> input){
        if(input == 0) break;
        double current = 0;
        int i = 1;
        while(current < input){
            current += (double)1/(i+1);
            i++;
        }
        cout << i-1 << " card(s)" << endl;
    }
    return 0;
}
