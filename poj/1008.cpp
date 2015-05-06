#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>

using namespace std;

int main(){
	freopen("../in.txt", "r", stdin);
	string Tzo[] = { "ahau", "imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac"};
	string Haa[] = {"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet"};
	int days; 
	int Haa_day, Haa_year, Haa_mon, Tzo_day, Tzo_mon, Tzo_year;
	string Haa_month, Tzo_month;
	int N;
	cin >> N;
	cout << N << endl;
	for(int test=1; test<=N; test++){
		//scanf("%d. %s %d", &Haa_day, &Haa_month, &Haa_year)
		cin >> Haa_day;
		getchar();
		cin >> Haa_month >> Haa_year;
		days = Haa_year*365;
		for(int i=1; i<=19; i++){
			if(Haa_month == Haa[i-1]){
				Haa_mon = i;
			}
		}
		if(Haa_mon<19) days += (Haa_mon-1)*20;
		else days += 360;
		days += Haa_day+1;

		Tzo_year = days%260==0? days/260-1: days/260;
		int temp = days%260==0? 260: days%260;
		Tzo_day = temp%13==0? 13: temp%13;
		Tzo_mon = temp%20;
		Tzo_month = Tzo[Tzo_mon];
		cout << Tzo_day << " " << Tzo_month << " " << Tzo_year << endl;
	}
	return 0;
}