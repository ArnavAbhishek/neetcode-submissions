class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<vector<int>> dp(rows, vector<int>(cols, -1));

        vector<int> delx = {1,-1,0,0};
        vector<int> dely = {0,0,1,-1};

        auto dfs = [&](auto self, int i, int j) -> int {
            if(dp[i][j] != -1) return dp[i][j];

            int ret = 1;

            for(int t=0; t<4; t++){
                int xnew = i+delx[t];
                int ynew = j+dely[t];

                if(xnew < rows && xnew >= 0 && ynew < cols && ynew >=0 && matrix[xnew][ynew] > matrix[i][j]){
                    ret = max(ret, 1 + self(self, xnew, ynew));
                }
            }

            return dp[i][j] = ret;
        };

        int ans = 0;
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                ans = max(ans, dfs(dfs, i, j));
            }
        }

        return ans;
    }
};
