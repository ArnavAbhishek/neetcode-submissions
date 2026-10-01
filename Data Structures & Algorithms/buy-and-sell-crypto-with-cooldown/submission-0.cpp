class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<int> dp(n+1, -1);
        
        auto func = [&](auto self, int start) -> int {
            if(dp[start] != -1) return dp[start];
            if (start == n) return dp[start] = 0;

            int ans = 0;
            for(int i=start; i<n; i++){
                int curans = 0;
                for(int j=i+1; j<n; j++){
                    if(prices[j] > prices[i]){
                        if(j == n-1) curans = max(curans, prices[j] - prices[i]);
                        else curans = max(curans, prices[j] - prices[i] + self(self, j+2));

                    }
                }
                ans = max(ans, curans);
            }
            return dp[start] = ans;
        };

        return func(func, 0);
    }
};
