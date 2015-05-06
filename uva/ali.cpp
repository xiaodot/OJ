#include <set>
#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
    freopen("./input.txt", "r", stdin);
    int data;
    int start = 1;
    set<int> myset;
    set<int> :: iterator ite;
    while(cin >> data){
        if(data == start){
            cout << data;
            start++;
            while(!myset.empty()){
                ite = myset.begin();
                if(*ite == start){
                    cout << " " << *ite;
                    start++;
                    myset.erase(ite);
                }
                else{
                    break;
                }
            }
            cout << endl;

        }
        else{
            myset.insert(data);
        }
    }
    return 0;
}
