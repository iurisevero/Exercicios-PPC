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
    static bool compareMinor(int a, int b){
        return a < b;
    }
    
    static bool compareBigger(int a, int b){
        return a > b;
    }
    
    template <class Compare>
    bool comparingDFS(TreeNode* root, int compare_value, Compare comp){
        if(root == nullptr) return true;
        if(comp(root->val, compare_value)){
            bool valid_left, valid_right;
            valid_left = comparingDFS(root->left, compare_value, comp);
            valid_right = comparingDFS(root->right, compare_value, comp);
            return valid_left && valid_right;
        }
        return false;
    }
    
    bool isValidBST(TreeNode* root) {
        if(root == nullptr) return true;
        bool valid_left = comparingDFS(root->left, root->val, compareMinor);
        bool valid_right = comparingDFS(root->right, root->val, compareBigger);
        return valid_left && valid_right && isValidBST(root->left) && isValidBST(root->right);
    }
};


/* Solução educative.oi

bool is_bst_rec(
    BinaryTreeNode* root,
    int min_value,
    int max_value) {

  if (root == nullptr) {
    return true;
  }

  if (root->data < min_value || 
      root->data > max_value) {
    return false;
  }

  return 
    is_bst_rec(root->left, min_value, root->data) &&
      is_bst_rec(root->right, root->data, max_value);
}

bool is_bst(BinaryTreeNode* root) {
  return 
    is_bst_rec(
      root,
      numeric_limits<int>::min(), 
      numeric_limits<int>::max());
}

*/