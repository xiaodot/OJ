#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>

using namespace std;

void quick_sort(int a[], int l, int r){
    if(l < r){
        int i = l, j = r, x = a[l];
        while(i < j){
            while(i < j && a[j] > x) j--;
            if(i < j)   a[i++] = a[j];
            while(i < j && a[i] <= x) i++;
            if(i < j)   a[j--] = a[i];
        }
        a[i] = x;
        quick_sort(a, l, i-1);
        quick_sort(a, i+1, r);
    }
}

void insert_sort(int a[], int n){
    for(int i=0; i<n; i++){
        for(int j=i-1; j>=0 && a[j]>a[j+1]; j--){
            swap(a[j], a[j+1]);
        }
    }
}

int main(){
    freopen("../in.txt", "r", stdin);
    int a[10000];
    int i = 0;
    while(cin >> a[i++]);
    int n = i-1;
    insert_sort(a, n);
    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }
    return 0;

}
