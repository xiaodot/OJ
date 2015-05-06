#include <iostream>
#include <stdio.h>
#include <map>
#include <string>
#include <limits.h>

using namespace std;

map<string, int> month;


int main(){
    month["January"] = 1;
    month["February"] = 2;
    month["March"] = 3;
    month["April"] = 4;
    month["May"] = 5;
    month["June"] = 6;
    month["July"] = 7;
    month["August"] = 8;
    month["September"] = 9;
    month["October"] = 10;
    month["November"] = 11;
    month["December"] = 12;

    freopen("input.txt", "r", stdin);
    int T;
    scanf("%d", &T);

    for(int test=1; test<=T; test++){
        int res;
        int m1, m2, d1, d2, y1, y2;
        char s[20];
        scanf("%s %d, %d", &s, &d1, &y1);
        m1 = month[s];
        scanf("%s %d, %d", &s, &d2, &y2);
        m2 = month[s];

//        bool flag1 = (y1%4==0 && y1%100!=0 || y1%400==0) ? true : false;
//        bool flag2 = (y2%4==0 && y2%100!=0 || y2%400==0) ? true : false;

//
//        if(m1<2 || m1==2 && d1 <= 29){
//            ;
//        }
//        else{
//            y1++;
//        }
//
//        if(m2>=3){
//            ;
//        }
//        else{
//            y2--;
//        }
        res = (y2/4-y2/100+y2/400) - (y1/4-y1/100+y1/400);
        if((y1%4==0 && y1%100!=0 || y1%400==0) && (m1<2 || m1==2 && d1 <= 29)) res++;
        if((y2%4==0 && y2%100!=0 || y2%400==0) && (m2<2 || m2==2 && d2 < 29)) res--;
//        cout << s << " " << d2 << ", " << y2 << endl;
//        res = y2-y1;
        printf("Case #%d: %d\n", test, res);
    }
    cout << INT_MAX << endl;
    return 0;
}
