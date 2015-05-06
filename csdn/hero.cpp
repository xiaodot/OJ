#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;


//	查找公共子串
//	lcs记录公共子串
//	return	公共子串长度
int LCS(const char *str1  , int len1 , const char *str2 , int len2 , char *&lcs)
{
	if(NULL == str1 || NULL == str2)
	{
		return -1;	//空参数
	}

	//	压缩后的最长子串记录向量
	int *c = new int[len2+1];
	for(int i = 0 ; i < len2 ; ++i)
	{
		c[i] = 0;
	}
	int max_len = 0;	//匹配的长度
	int pos = 0;		//在str2上的匹配最末位置
	for(int i = 0 ; i < len1 ; ++i)
	{
		for(int j = len2 ; j > 0 ; --j)	//更新时从后往前遍历
		{
			if(str1[i] == str2[j-1])
			{
				c[j] = c[j-1] + 1;
				if(c[j] > max_len)
				{
					max_len = c[j];
					pos = j-1;
				}
			}
			else
			{
				c[j] = 0;
			}
		}
	}

	if(0 == max_len)
	{
		return 0;
	}

	//	得到公共子串
	lcs = new char[max_len];
	for(int i = 0 ; i < max_len ; ++i)
	{
		lcs[i] = str2[pos-max_len+1+i];
	}
//	cout<<"pos = "<<pos<<endl;
	delete [] c;
	return max_len;

}


//	test
int main()
{
    freopen("../in.txt", "r", stdin);
    int dp[2000][2000][3][3];
    memset(dp, 0, sizeof(dp));
    char str1[2010], str2[2010];
    while(cin >> str1){
        int len = strlen(str1);
        for(int i=0; i<len; i++){
            str2[len-1-i] = str1[i] - 13;
        }
        int len1 = strlen(str1);
        int len2 = strlen(str2);
//        char *lcs;
//        cout << LCS(str1 , len1 , str2 , len2 , lcs) << endl;

        for(int i = 1; i < len1; i++){
            for(int j = 1; j < len2;j++){
                for(int m = 0; m < 3; m++){
                    for(int n = 0; n < 3; n++){
                        if(!n || !m){
                            if(str1[i] == str2[j]){
                                dp[i][j][m][n] = dp[i-1][j-1][m][n] + 1;
                            }
                            else{
                                dp[i][j][m][n] = max(dp[i-1][j][m][n], dp[i][j-1][m][n]);
                                for(int k=1; k<=m; k++){
                                    dp[i][j][m][n] = max(dp[i][j][m][n], dp[i][j][m-k][n]);
                                }
                                for(int k=1; k<=n; k++){
                                    dp[i][j][m][n] = max(dp[i][j][m][n], dp[i][j][m][n-k]);
                                }

                            }
                        }

                    }
                }
            }
        }
        memset(str1, 0 , sizeof(str1));
        memset(str2, 0 , sizeof(str2));
        memset(dp, 0, sizeof(dp));
    }
}
