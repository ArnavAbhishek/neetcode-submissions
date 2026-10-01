class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(n+1, 0);

        for(int i=n-1; i>=0; i--){
            int curans = 0;
            for(int j=i+1; j<n; j++){
                if(prices[j] > prices[i]){
                    if(j == n-1) curans = max(curans, prices[j] - prices[i]);
                    else curans = max(curans, prices[j] - prices[i] + dp[j+2]);
                }
            }
            dp[i] = max(curans, dp[i+1]);
        }

        return dp[0];
    }
};
