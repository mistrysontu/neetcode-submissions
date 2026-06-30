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
class hashPair{
    size_t operator()(pair<int, int> &p){
        return p.first ^ p.second;
    }
};
class Solution {
public:
    unordered_map<Node*, Node*> umap;
    Node* cloneGraph(Node* node) {
        if(node == nullptr){
            return nullptr;
        }
        if(umap.count(node)) return umap[node];

        Node *newNode = new Node(node->val);

        umap[node] = newNode;

        for(auto nei: node->neighbors){
            cout << nei->val << endl;
            newNode->neighbors.push_back(cloneGraph(nei));
        }
        return newNode;
    }
};
