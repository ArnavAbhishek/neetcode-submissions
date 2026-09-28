#define fr(i,n) for(int i=0; i<n; i++)
#define vi vector<int>

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        set<pair<int,int>> pacific;
        set<pair<int,int>> atlantic;

        vi delx = {1,-1,0,0};
        vi dely = {0,0,1,-1};

        auto is_valid = [&](int i, int j, int pi, int pj) -> bool {
            return (i < rows && i >= 0 && j < cols && j >= 0 && grid[pi][pj] <= grid[i][j]);
        };

        auto dfs = [&](auto self, int i, int j) -> void {
            pacific.insert({i,j});

            fr(k,4){
                int x = i + delx[k];
                int y = j + dely[k];

                if(is_valid(x,y,i,j) && pacific.count({x,y}) == 0){
                    self(self, x, y);
                }
            }
        };

        fr(i,cols){
            if(pacific.count({0,i}) == 0){
                dfs(dfs, 0, i);
            }
        }
        fr(i,rows){
            if(pacific.count({i,0}) == 0){
                dfs(dfs, i, 0);
            }
        }


        auto dfs_atlantic = [&](auto self, int i, int j) -> void {
            atlantic.insert({i,j});

            fr(k,4){
                int x = i + delx[k];
                int y = j + dely[k];

                if(is_valid(x,y,i,j) && atlantic.count({x,y}) == 0){
                    self(self, x, y);
                }
            }
        };

        fr(i,cols){
            if(atlantic.count({rows-1,i}) == 0){
                dfs_atlantic(dfs_atlantic, rows-1,i);
            }
        }
        fr(i,rows){
            if(atlantic.count({i,cols-1}) == 0){
                dfs_atlantic(dfs_atlantic, i,cols-1);
            }
        }
        
        vector<vi> ans;
        fr(i,rows){
            fr(j,cols){
                if(atlantic.count({i,j}) && pacific.count({i,j})){
                    ans.push_back({i,j});
                }
            }
        }

        return ans;
    }
};
