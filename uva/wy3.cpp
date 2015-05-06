#include <iostream>
#include <limits.h>

using namespace std;

int N;
int m, n;
int **A;

void check(int x, int y, int dir, int type, int k, int &count){
	if(k < 0) return;
	if(x < 0 || x>m+1 || y<0 || y>n+1) return;
	if(A[x][y] == type) {
		count++;
		A[x][y] = INT_MAX;
	}
	else if(A[x][y] <= 0){
		if(k >= -A[x][y]){
            A[x][y] = -k;
            switch (dir){
            case 0:
                check(x,y-1,0,type,k,count);
                check(x+1,y,1,type,k-1,count);
                check(x-1,y,3,type,k-1,count);
                break;
            case 1:
                check(x,y-1,0,type,k-1,count);
                check(x+1,y,1,type,k,count);
                check(x,y+1,2,type,k-1,count);
                break;
            case 2:
                check(x+1,y,1,type,k-1,count);
                check(x,y+1,2,type,k,count);
                check(x-1,y,3,type,k-1,count);
                break;
            case 3:
                check(x,y-1,0,type,k-1,count);
                check(x,y+1,2,type,k-1,count);
                check(x-1,y,3,type,k,count);
                break;
            }
		}
	}
	return;
}

void lianliankan(){
	scanf("%d%d", &m, &n);
	int t;
	A = new int*[m+2];

	for(int i=0; i<m+2; i++){
        A[i]=new int[n+2];
	}

	for(int i=0; i<=m+1; i++){
        for(int j=0; j<=n+1; j++){
			A[i][j]=0;
		}
	}

	for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
			scanf("%d", &A[i][j]);
		}
	}

	int x, y, k, type, c = 0;
	scanf("%d%d%d", &x, &y, &k);
	type = A[x][y];
	A[x][y] = INT_MAX;
	if(type == 0) {
        printf("error\n");
        return;
    }
	check(x,y-1,0,type,k,c);
	check(x+1,y,1,type,k,c);
	check(x,y+1,2,type,k,c);
	check(x-1,y,3,type,k,c);
	printf("%d\n", c);
}

int main(){
    //cin >> N;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		lianliankan();
	}
	return 0;
}
