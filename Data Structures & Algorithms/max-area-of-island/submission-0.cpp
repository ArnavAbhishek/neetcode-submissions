#include <bits/stdc++.h>

#define fr(i,n) for(int i=0; i<n; i++)
#define vi vector<int>

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        vi delx = {1,-1,0,0};
        vi dely = {0,0,1,-1};

        vector<vi> vis(rows, vi(cols, 0));

        auto is_valid = [&](int i, int j) -> bool {
            return (i<rows && i>=0 && j<cols && j>=0 && vis[i][j] == 0 && grid[i][j] ==1);
        };

        int curarea=0;

        auto dfs = [&](auto self, int i, int j) -> void {
            vis[i][j] = 1;
            curarea++;
            fr(k,4){
                int xnew = i + delx[k];
                int ynew = j + dely[k];

                if(is_valid(xnew, ynew)){
                    self(self, xnew, ynew);
                }
            }
        };

        int area = 0;
        fr(i,rows){
            fr(j,cols){
                if(is_valid(i,j)){
                    dfs(dfs, i, j);
                    area = max(area, curarea);
                    curarea = 0;
                }
            }
        }

        return area;
    }
};
