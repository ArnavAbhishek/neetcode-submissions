class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();

        vector<int> dp(n+1, -1);
        
        auto func = [&](auto self, int start){
            if(dp[start] != -1) return dp[start];
            if(start == n) return dp[start] = true;

            bool ans = false;
            for(int i=start; i<n; i++){
                if(find(wordDict.begin(), wordDict.end(), s.substr(start, i-start+1)) != wordDict.end()){
                    ans = ans || self(self, i+1);
                }
                if(ans) return dp[start] = true;
            }
            return dp[start] = false;
        };

        return func(func, 0);

    }
};
