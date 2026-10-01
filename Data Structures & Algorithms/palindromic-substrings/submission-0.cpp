class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();

        int cur=0;
        for(int i=0; i<n; i++){
            int i1=i, i2=i;
            while(i1 >=0 && i2 < n && s[i1] == s[i2]){
                i1--; i2++;
                cur++;
            }
        }

        for(int i=0; i<n-1; i++){
            if(s[i] != s[i+1]) continue;
            int i1=i, i2=i+1;
            while(i1 >=0 && i2 < n && s[i1] == s[i2]){
                i1--; i2++;
                cur++;
            }
        }

        return cur;
    }
};
