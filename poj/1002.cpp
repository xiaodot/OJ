#include <iostream>
#include <stdio.h>
#include <map>
#include <cstring>
#include <string>

using namespace std;

char mapping(char c){
	switch(c){
		case 'A':
		case 'B':
		case 'C': return '2';
		case 'D':
		case 'E':
		case 'F': return '3';
		case 'G':
		case 'H':
		case 'I': return '4';
		case 'J':
		case 'K':
		case 'L': return '5';
		case 'M':
		case 'N':
		case 'O': return '6';
		case 'P':
		case 'R':
		case 'S': return '7';
		case 'T':
		case 'U':
		case 'V': return '8';
		case 'W':
		case 'X':
		case 'Y': return '9';
		default: return c;
	}
}

// This problem is very easy if we use the Map data structure.
int main(){
	freopen("in.txt", "r", stdin);
	int N;
	cin >> N;
	map<string, int> m;
	for(int i=0; i<N; i++){
		string str;
		cin >> str;
		string id = "0000000";
		int j = 0;
		for(int i=0; i<str.length(); i++){
			if(str[i] == '-'){
				continue;
			}
			else{
				id[j++] = mapping(str[i]);
			}
		}
		if(m.count(id) >0){
			m[id] ++;
		}
		else{
			m[id] = 1;
		}
	}
	map<string, int> ::iterator ite;
	int cnt = 0;
	for(ite = m.begin(); ite!=m.end(); ite++){
        if(ite->second <= 1) continue;
        string first = ite->first;
        first.insert(3, "-");
		cout << first << " " << ite->second << endl;
		cnt ++;
	}
	if(!cnt){
        cout << "No duplicates." << endl;
	}
	return 0;
}
