#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>

using namespace std;

void getNext(char *p, int *next){
    int j, k;
    next[0] = -1;
    j = 0;
    k = -1;
    while(j < strlen(p)-1){
        if(k == -1 || p[j] == p[k]){
            next[++j] = ++k;
        }
        else
            k = next[k];
    }
}

int KMPMatch(char *s, char *p){
    int next[100];
    int i, j;
    i = 0;
    j = 0;
    getNext(p, next);
    while(i < strlen(s)){
        if(j == -1 || s[i]==p[j]){
            i++;
            j++;
        }
        else{
            j = next[j];
        }
        if(j == strlen(p))
            return i - strlen(p);
    }
    return -1;
}

int main() {
    freopen("../in.txt", "r", stdin);
    char s[100], p[100];
    gets(s);
    gets(p);
    int next[100];
    memset(next, -1, sizeof(next));
    getNext(p, next);
    cout << KMPMatch(s, p) << endl;
    return 0;
}
