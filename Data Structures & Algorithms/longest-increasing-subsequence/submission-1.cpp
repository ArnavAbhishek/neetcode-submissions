class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, 1);

        int ans = 1;
        for(int i=n-2; i>=0; i--){
            for(int j=i+1; j<n; j++){
                if(nums[j] > nums[i]) dp[i] = max(dp[i], 1+dp[j]);
            }
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};
