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
    unordered_map<Node*, Node*> umap;
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return node;
        if(umap.count(node)) return umap[node];
        umap[node] = new Node(node->val);
        for(auto nei: node->neighbors) {
            umap[node]->neighbors.push_back(cloneGraph(nei));
        }
    
        return umap[node];
    }
};
