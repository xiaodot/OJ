
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>

using namespace std;

bool comp(char i, char j){return (i>j);}

int main(){
//    freopen("in.txt", "r", stdin);
    int T;
    char c;
    c = getchar();
    printf("%d", c);

  //use cin.get to input a long string which can contain " " but can't contain '\n'
    char ch[1000];
    cin.get(ch, 200);
    puts(ch);

// cin.get()   the same with getchar(), and cin.getline()
// cin.getline(char*, length)
// getline(cin, str)
// gets()  s means string
// puts()


// Just need  to remember these function: getchar() getline(cin, string) gets(char*)（不用给出长度）
// 或者cin.get(): 具有cin.getline(char*, length), getchar()的作用
// scanf("%s", char*)

    cin >> T;
    getchar();
    for(int test=1; test<=T; test++){
        string s;
        getline(cin, s);
        int len = s.length();
        do{
            cout << s << endl;

        }
        while(next_permutation(s.begin(), s.end(), comp));
    }

    return 0;
}
