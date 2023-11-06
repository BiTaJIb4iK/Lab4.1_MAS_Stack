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
    vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> ret;

        pushValue(ret, root);

        return ret;
    }

private:
    void pushValue(std::vector<int>& vect, TreeNode* node){
        if(!node)
            return;
            
        pushValue(vect, node->left);
        vect.push_back(node->val);
        pushValue(vect, node->right);
    }
};