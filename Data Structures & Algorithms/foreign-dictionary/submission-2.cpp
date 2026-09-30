class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, vector<char>> adj;
        unordered_map<char, int> indeg;
        unordered_map<char, int> outdeg;
        unordered_set<char> chars;
        int n = words.size();

        for(int i=0; i<n; i++){
            for(int j=0; j<words[i].size(); j++){
                chars.insert(words[i][j]);
            }
        }

        for(int i=0; i<n-1; i++){
            int j1=0, j2=0;
            while(j1 < words[i].size() && j2 < words[i+1].size() && words[i][j1] == words[i+1][j2]){
                    j1++; j2++;
                }
                
                if(j1 < words[i].size() && j2 == words[i+1].size()) return "";
                if(j1 == words[i].size() || j2 == words[i+1].size()) continue;
                adj[words[i][j1]].push_back(words[i+1][j2]);
                indeg[words[i+1][j2]]++;
                outdeg[words[i][j1]]++;
            }
        
        string topo;
        for(auto it: chars){
            if(outdeg[it] == 0 && indeg[it] == 0){
                topo.push_back(it);
            }
        }
        queue<char> q;
        for(auto &[x,y] : adj){
            if(indeg.count(x) == 0){
                topo.push_back(x);
                q.push(x);
            }
        }
        
        while(!q.empty()){
            char ch = q.front();
            q.pop();

            for(auto it: adj[ch]){
                indeg[it]--;
                if(!indeg[it]){
                    q.push(it);
                    topo.push_back(it);
                }
            }
        }
        if(topo.size() != chars.size()) return "";
        return topo;

    }
};
