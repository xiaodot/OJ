#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<string, int> P;

bool myFunc(pair<string, int> P1, pair<string, int> P2){
	return P1.second < P2.second;
}
int main(){
	freopen("../in.txt", "r", stdin);
	int N, M;
	vector<P> myvec;

	string str;
	cin >> M >> N;
	for(int i=0; i<N; i++){
		cin >> str;
		myvec.push_back(P(str, i));
	}
	vector <P> :: iterator ite;
	for(ite=myvec.begin(); ite!=myvec.end(); ite++){
		str = ite->first;
		int rank=0;
		for(int i=0; i<str.length(); i++){
			for(int j=i+1; j<str.length(); j++){
				if(str[i] > str[j]) rank++;
			}
		}
		ite->second = rank;
	}
	sort(myvec.begin(), myvec.end(), myFunc);
	for(ite=myvec.begin(); ite!=myvec.end(); ite++){
		cout << ite->first <<   endl;
	}
	return 0;
}
