#include <iostream>

using namespace std;

int IniMap[105][105],Map[105][105];
int N = 0, M = 0, S = 0, stepnum = 0;
int player[2], box[2], dest[2];
char operation[10005];
char tmpchar;
int dx[4], dy[4];
int suc = 0;

bool check(int x, int y){
    if (x < 0 || x >= M || y < 0 || y >= N)
        return 0;
    else
        return 1;
}

int main()
{

    dx[0] = 1; dx[1] = -1; dx[2] = 0; dx[3] = 0;
    dy[0] = 0; dy[1] = 0; dy[2] = -1; dy[3] = 1;

    cin >> N >> M >> S;

    for (int i = 0 ; i <  M; ++i){
        for (int j = 0; j < N; ++j){
            cin >> tmpchar;
            IniMap[i][j] = tmpchar - '0';
            switch (IniMap[i][j]){
                case 1: player[0] = i;
                        player[1] = j;
                        break;
                case 2: dest[0] = i;
                        dest[1] = j;
                        break;
                case 3: box[0] = i;
                        box[1] = j;
                        break;
            };
        }
    }
    for (int i = 0; i < M; ++i){
        IniMap[i][N] = -1;
        IniMap[i][N+1] = -1;
    }
    for (int j = 0; j < N; ++j){
        IniMap[M][j] = -1;
        IniMap[M+1][j] = -1;
    }

    int dir = 0;
    int x, y;
    for (int i = 0; i < S; ++i){
        for(int m = 0; m < M; ++m){
            for(int n = 0; n < N; ++n){
                Map[m][n] = IniMap[m][n];
            }
        }
        int pex = player[0], pey = player[1];
        int bex = box[0], bey = box[1];
        Map[dest[0]][dest[1]] = 0;
        suc = 0;

        cin >> stepnum;

        for (int j = 0; j < stepnum; ++j){
            cin >> operation[j];
            switch (operation[j]){
                case 'd': dir = 0; break;//down
                case 'u': dir = 1; break;//up
                case 'l': dir = 2; break;//left
                case 'r': dir = 3; break;//right
            };
            x = pex + dx[dir]; y = pey + dy[dir];

            if (check(x,y) && Map[x][y] == 0){
                Map[pex][pey] = 0;
                Map[x][y] = 1;
                pex = x; pey = y;
            }
            else if(check(x,y) && Map[x][y] == 3 &&
                    check(x+dx[dir], y+dy[dir]) &&
                    Map[x+dx[dir]][y+dy[dir]] == 0){
                Map[bex][bey] = 0;
                Map[x+dx[dir]][y+dy[dir]] = 3;
                bex = x+dx[dir]; bey = y+dy[dir];

                Map[pex][pey] = 0;
                Map[x][y] = 1;
                pex = x; pey = y;
                if (bex == dest[0] && bey == dest[1])
                    suc = 1;
            }

        }
        if (suc == 1)
            cout << "YES"<<endl;
        else cout << "NO" <<endl;
    }
    return 0;
}

