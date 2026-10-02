class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();

        vector<vector<bool>> dp(n+1, vector<bool>(m+1, 0));
        dp[0][0] = 1;
        for(int i=2; i<m+1; i++){
            if(p[i-1] == '*') dp[0][i] = 1;
        }

        for(int i=1; i<n+1; i++){
            for(int j=1; j<m+1; j++){
                if(s[i-1] == p[j-1] || p[j-1] == '.') dp[i][j] = dp[i-1][j-1];
                else if(p[j-1] == '*' ){
                    if(j>=2 && p[j-2] == '.'){
                        int temp = i;
                        if(j>=3){
                            while(i>=1 && s[i-1] != p[j-3]) i--;
                            dp[temp][j] = dp[i][j-2];
                            i = temp;
                            continue;
                        }
                        else dp[i][j] = 1;
                    }
                    else{
                        int idx = i;
                        char t = p[j-2];
                        while(i>=1 && s[i-1] == t){
                            i--;
                        }
                        dp[idx][j] = dp[i][j-2] || dp[idx][j-2];
                        i = idx;
                    }
                }
            }
        }
        return dp[n][m];
    }
};
