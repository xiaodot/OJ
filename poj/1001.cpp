#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

// Here, we use the string to store the result of calculating.
// If we use vector, it will be more convenient.
string mult(string str1, string str2){
	vector <char> res;
	int carry = 0;
	int i, j;
	for(i=0; i<str1.length(); i++){
        for(j=0; j<str2.length(); j++){
            int a = str1[str1.length() - 1 - i] - '0';
            int b = str2[str2.length() - 1 - j] - '0';
            int c = a*b + carry;
            char data;
            //two cases: one is that the position is still not occupied.

            if(res.size() < i+j+1){
               data = c%10 + '0';
                res.push_back(data);
            }
            // the other, the position is already there.
            else{
                c += res[i+j] - '0';
                data = c%10 + '0';
                res[i+j] = data;
            }
            carry = c/10;
        }
        //If the carry is not zero, we should add this value to the corresponding position.
        // Similarly, we should consider whether the position is already there.
        while(carry > 0){
            int z = i+j;
            if(res.size() < z+1){
                res.push_back(carry%10 + '0');
                carry = carry/10;
                z++;
            }
            else{
                int temp = res[z] - '0' + carry;
                res[z] = temp%10 +'0';
                carry = temp/10;
                z++;
            }

        }
	}
    string str="";
	for(int i=0; i<res.size(); i++){
        int index = res.size();
        index = index - i - 1;
        // we can not simply use str[i] = res[index];
        //在str长度之外，不能如下赋值！！！
//        str[i] = res[index];
        str += res[index];
	}
	return str;
}
//The divide and conquer
string calc(string str, int n){
	if(n==1) return str;
	string temp = calc(str, n/2);
	temp = mult(temp, temp);
	if(n%2==1) temp = mult(temp, str);
	return temp;
}

int main(){
	freopen("in.txt", "r", stdin);
	string str;
	int n;
	while(cin >> str >> n){
        int pos = str.find(".");
        string res = "";
        if(pos > -1){
            //Make the float number to be an integer
            int cnt = str.length() - 1 - pos;
            cnt = cnt*n;
            str.replace(pos, 1, "");
            res  = calc(str, n);
            // Add the digitals
            res.insert(res.length() - cnt, 1, '.');
        }
        else{
            res = calc(str, n);
        }

        //Deal with the format of the output
        //Leading zeros
        int i = 0;
        while(res[i] == '0' && res[i] != '.' && i<res.length()){
            i++;
        }
        res.replace(0, i, "");
        // Insignificant trailing zeros
        i = res.length()-1;
        while(res[i] == '0' && res[i] !='.' && i>=0){
            i--;
        }
        res.replace(i+1, res.length(), "");
        //Two special cases: "2332." and "0"
        if(res[res.length() - 1] == '.') res.replace(res.length()-1, 1, "");
        if(res == "") res = "0";
        cout << res << endl;
	}
	string strs = "es";
	for(int i=0; i<5; i++){
        strs[i] = 'i' + i;
	}
	cout << strs << endl;
	
	return 0;
}
