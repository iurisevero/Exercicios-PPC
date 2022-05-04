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
        if(!node) return node;
        
        int visited[101];
        map<int, Node*> new_nodes;
        memset(visited, -1, sizeof(visited));
        
        queue<Node*> to_visit;
        to_visit.push(node);
        
        Node* head = new Node(node->val);
        visited[head->val] = 1;
        new_nodes[head->val] = head;
        
        while(!to_visit.empty()){
            Node* visiting = to_visit.front();
            to_visit.pop();
            vector<Node*> new_neighbors;
            for(Node* n : visiting->neighbors){
                Node* neighbor;
                if(new_nodes.count(n->val))
                    neighbor = new_nodes[n->val];
                else{
                    neighbor = new Node(n->val);
                    new_nodes[neighbor->val] = neighbor;
                }
                new_neighbors.push_back(neighbor);
                
                if(visited[n->val] == -1){
                    visited[n->val] = 1;
                    to_visit.push(n);
                }
            }
            new_nodes[visiting->val]->neighbors = new_neighbors;
        }
        return head;
    }
};