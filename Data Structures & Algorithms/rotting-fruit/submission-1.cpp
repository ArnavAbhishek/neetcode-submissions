#define vi vector<int>
#define fr(i,n) for(int i=0; i<n; i++)

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vi> time(rows, vi(cols, INT_MAX));

        queue<pair<int,int>> q;

        fr(i,rows){
            fr(j,cols){
                if(grid[i][j] == 2){
                    time[i][j] = 0;
                    q.push({i,j});
                }
            }
        }

        vi delx = {1,-1,0,0};
        vi dely = {0,0,1,-1};

        auto is_valid = [&](int i, int j) -> bool {
            return (i < rows && i >= 0 && j < cols && j >=0 && grid[i][j] == 1);
        };

        while(!q.empty()){
            auto cell = q.front();
            q.pop();

            fr(k,4){
                int x = cell.first + delx[k];
                int y = cell.second + dely[k];

                if(is_valid(x,y)){
                    if(time[x][y] > time[cell.first][cell.second] + 1){
                        time[x][y] = time[cell.first][cell.second] + 1;
                        q.push({x,y});
                    }
                }
            }
        }

        int ans = 0;
        fr(i,rows){
            fr(j,cols){
                if(time[i][j] == INT_MAX){
                    if(grid[i][j] == 1) return -1;
                    else continue;
                }
                ans = max(time[i][j], ans);
            }
        }

        return ans;
    }
};
