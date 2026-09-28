#define fr(i,n) for(int i=0; i<n; i++)
#define vi vector<int>

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vi parent(n+1);
        vi size(n+1, 1);

        fr(i,n+1) parent[i] = i;

        auto get_ult_parent = [&](auto self, int node) -> int {
            if(node == parent[node]) return node;
            return parent[node] = self(self, parent[node]);
        };

        auto union_by_size = [&](int i, int j) -> void {
            int pari = get_ult_parent(get_ult_parent, i);
            int parj = get_ult_parent(get_ult_parent, j);

            if(pari == parj) return;

            if(size[pari] < size[parj]){
                parent[pari] = parj;
                size[parj] += size[pari];
            }
            else{
                parent[parj] = pari;
                size[pari] += size[parj];
            }
        };

        for(auto it: edges){
            if(get_ult_parent(get_ult_parent, it[0]) == get_ult_parent(get_ult_parent, it[1])){
                return {it[0], it[1]};
            }
            else{
                union_by_size(it[0], it[1]);
            }
        }
        return {};
    }
};
