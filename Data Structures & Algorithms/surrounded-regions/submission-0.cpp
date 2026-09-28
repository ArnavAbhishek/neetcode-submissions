#define fr(i,n) for(int i=0; i<n; i++)

class Solution {
public:
    void solve(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        auto is_valid =[&](int i, int j) -> bool {
            return (i<rows && i>=0 && j<cols && j>=0 && grid[i][j] == 'O');
        };

        vector<int> delx = {1,-1,0,0};
        vector<int> dely = {0,0,1,-1};

        auto dfs = [&](auto self, int i, int j) -> void {
            grid[i][j] = '+';
            fr(k,4){
                int x = i + delx[k];
                int y = j + dely[k];

                if(is_valid(x,y)){
                    self(self, x, y);
                }
            }
        };

        fr(i,rows){
            fr(j,cols){
                if(i == 0 || i == rows-1 || j == 0 || j == cols-1){
                    if (is_valid(i,j)) dfs(dfs, i, j);
                }
            }
        }
        
        fr(i,rows){
            fr(j,cols){
                if(grid[i][j] == '+') grid[i][j] = 'O';
                else if(grid[i][j] == 'O') grid[i][j] = 'X';
            }
        }
    }
};
