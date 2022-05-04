/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> level_order;
        queue<TreeNode*> to_visit;
        if(root != nullptr)
            to_visit.push(root);

        while(!to_visit.empty()){
            int _visit_size = to_visit.size();
            vector<int> visited;
            for(int i=0; i < _visit_size; ++i){
                TreeNode *visiting = to_visit.front();
                to_visit.pop();
                visited.push_back(visiting->val);
                if(visiting->left != nullptr)
                    to_visit.push(visiting->left);
                if(visiting->right != nullptr)
                    to_visit.push(visiting->right);
            }
            level_order.push_back(visited);
        }
        return level_order;
    }
};