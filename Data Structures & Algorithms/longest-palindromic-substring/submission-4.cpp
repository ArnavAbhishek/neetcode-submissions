class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();

        int start = 0, end = 0;
        int maxi = 1;

        for(int i=0; i<n; i++){
            int curstart=i, curend=i;
            int i1=i-1, i2=i+1;
            while(i1 >=0 && i2 < n && s[i1] == s[i2]){
                curstart=i1;
                curend=i2;
                i1--; i2++;
            }
            if(maxi < (curend-curstart+1)){
                start = curstart;
                end = curend;
                maxi = (curend-curstart+1);
            }
        }

        for(int i=0; i<n-1; i++){
            if(s[i] != s[i+1]) continue;
            int curstart=i, curend=i+1;
            int i1=i-1, i2=i+2;
            while(i1 >=0 && i2 < n && s[i1] == s[i2]){
                curstart=i1;
                curend=i2;
                i1--; i2++;
            }
            if(maxi < (curend-curstart+1)){
                start = curstart;
                end = curend;
                maxi = (curend-curstart+1);
            }
        }
        return s.substr(start, end-start+1);
    }
};
