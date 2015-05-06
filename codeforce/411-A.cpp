#include <stdio.h>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main(){
    freopen("in.txt", "r", stdin);
    char a[200];
//    cin.getline(a, 200);
    gets(a);
    int i, len;
    i = len = 0;
    bool flag1, flag2, flag3;
    flag1 = flag2 = flag3 = false;
    while(true){
        if(a[i] == '\0') break;
        if('0'<=a[i] && a[i]<='9') flag1 = true;
        if('a'<=a[i] && a[i]<='z') flag2 = true;
        if('A'<=a[i] && a[i]<='Z') flag3 = true;
        len++;
        i++;
    }
    if(flag1 && flag2 && flag3 && len>=5){
        printf("Correct");
    }
    else{
        printf("Too weak");
    }
    return 0;
}
