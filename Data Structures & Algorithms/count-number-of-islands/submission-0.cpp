#include <bits/stdc++.h>
#define fr(i,n) for(int i=0; i<n; i++)
#define vi vector<int>

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<int> delx = {1, -1, 0, 0};
        vector<int> dely = {0, 0, 1, -1};

        vector<vi> vis(rows, vi(cols, 0));

        auto is_valid = [&](int i, int j) -> bool {
            return (i < rows && i >= 0 && j < cols && j >= 0 && vis[i][j] == 0 && grid[i][j] == '1');
        };

        auto dfs = [&](auto self, int i, int j) -> void {
            vis[i][j] = 1;
            
            fr(k,4){
                if(is_valid(i+delx[k], j+dely[k])){
                    self(self, i+delx[k], j+dely[k]);
                }
            }
        };

        int cur=0;
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(is_valid(i,j)){
                    dfs(dfs, i, j);
                    cur++;
                }
            }
        }

        return cur;
    }
};
