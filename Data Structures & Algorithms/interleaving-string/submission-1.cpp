class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()) return false;
        // cout << "yes";

        int i1 = s1.size()-1;
        int i2 = s2.size()-1;
        int i3 = s3.size()-1;

        vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, -1));

        auto func = [&](auto self, int i1, int i2) -> bool {
            
            if(i1>=0 && i2>=0 && dp[i1][i2] != -1) return dp[i1][i2];
            if(i1 == -1 || i2 == -1){
                if(i1 == -1){
                    return s2.substr(0,i2+1) == s3.substr(0,i3+1);
                }
                else{
                    return s1.substr(0,i1+1) == s3.substr(0,i3+1);
                }
            }
            if(s1[i1] != s3[i3] && s2[i2] != s3[i3]) return false;
            else if(s1[i1] == s3[i3] && s2[i2] == s3[i3]){
                i3--;
                return dp[i1][i2] = (self(self, i1-1, i2) || self(self, i1, i2-1));

            }
            else if(s1[i1] == s3[i3]){
                i3--;
                return dp[i1][i2] = self(self, i1-1, i2);
            }
            else{
                i3--;
                return dp[i1][i2] = self(self, i1, i2-1);
            }
            return false;
        };

        return func(func, i1, i2);
    }
};
