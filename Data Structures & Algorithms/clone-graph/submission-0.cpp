/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;

        unordered_map<Node*, Node*> cloned;

        auto dfs = [&](auto self, Node* cur) -> Node* {
            if(cloned.count(cur) != 0){
                return cloned[cur];
            }

            Node* ans = new Node(cur->val);
            cloned[cur] = ans;

            for(auto it: cur->neighbors){
                ans->neighbors.push_back(self(self, it));
            }

            return ans;
        };

        return dfs(dfs, node);
    }
};
