class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        auto func = [&](auto self, int i, int j) -> int {
            if(dp[i][j] != -1) return dp[i][j];
            if(j<i) return dp[i][j] = 0;
            int ans = 0;
            for(int t=i; t<=j; t++){
                ans = max(ans, self(self, i, t-1) + nums[i-1]*nums[t]*nums[j+1] + self(self, t+1, j));
            }
            return dp[i][j]= ans;
        };

        return func(func, 1, nums.size()-2);
    }
};
