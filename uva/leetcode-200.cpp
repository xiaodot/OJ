#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> point;

class Solution {
public:
    int numIslands(vector<vector<char>> &grid) {
        if(grid.empty() || grid[0].empty()) return 0;

        int m = grid.size(), n = grid[0].size();
        int res = 0;

        for(int i=0; i<m; i++){
            for(int j=0; i<n; j++){
                if(grid[i][j] == '1'){

                    cout << "In" << endl;

                    res++;
                    queue<point> que;
                    que.push(point(i,j));

                    while(!que.empty()){
                        point cur = que.front();
                        que.pop();
                        int x = cur.first, y = cur.second;
                        grid[x][y] = 'X';

                        if(x-1 >=0 && grid[x-1][y] == '1') que.push(point(x-1, y));
                        if(x+1 < m && grid[x+1][y] == '1') que.push(point(x+1, y));
                        if(y-1 >=0 && grid[x][y-1] == '1') que.push(point(x, y-1));
                        if(y+1 < n && grid[x][y+1] == '1') que.push(point(x, y+1));

                    }
                }
            }
        }
        return res;
    }
};

int main(){
    vector<vector<char> > grid = {{'1'}};
    Solution s;
    cout << s.numIslands(grid) << endl;

    return 0;
}
