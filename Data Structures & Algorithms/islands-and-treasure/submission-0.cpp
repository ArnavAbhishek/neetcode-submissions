#include <bits/stdc++.h>

#define fr(i,n) for(int i=0; i<n; i++)
#define vi vector<int>

class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int,int>> q;

        fr(i, rows){
            fr(j, cols){
                if(grid[i][j] == 0){
                    q.push({i,j});
                }
            }
        }

        vi delx = {1,-1,0,0};
        vi dely = {0,0,1,-1};

        auto is_valid = [&](int x, int y){
            return (x<rows && x>=0 && y<cols && y>=0 && grid[x][y] != -1);
        };

        while(!q.empty()){
            auto cell = q.front();
            q.pop();
            fr(k,4){
                int x = cell.first + delx[k];
                int y = cell.second + dely[k];
                if(is_valid(x,y)){
                    if(grid[x][y] > 1 + grid[cell.first][cell.second]){
                        q.push({x,y});
                        grid[x][y] = 1 + grid[cell.first][cell.second];
                    }
                }
            }
        }
    }
};
