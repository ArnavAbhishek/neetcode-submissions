#define fr(i,n) for(int i=0; i<n; i++)
#define fra(i,a,n) for(int i=a; i<n; i++)

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordList.insert(wordList.begin(), beginWord);
        int n = wordList.size();
        int len = beginWord.size();
        vector<vector<int>> adj(n);

        fr(i,n){
            fra(j,i+1,n){
                int cur=0;
                fr(k,len){
                    if(wordList[i][k] != wordList[j][k]) cur++;
                }
                if(cur == 1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int bind=0, eind=-1;
        fr(i,n){
            if(wordList[i] == endWord) eind=i;
        }
        if(eind == -1) return 0;

        queue<int> q;
        q.push(bind);
        vector<int> dist(n, INT_MAX);
        dist[bind] = 1;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto it: adj[node]){
                if(dist[it] > 1 + dist[node]){
                    dist[it] = 1 + dist[node];
                    q.push(it);
                }
            }
        }

        if(dist[eind] == INT_MAX){
            return 0;
        }
        return dist[eind];
    }
};
