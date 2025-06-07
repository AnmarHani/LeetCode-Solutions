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
private:
    bool isSameTree(TreeNode* firstNode, TreeNode* secondNode) {
        if (firstNode == nullptr && secondNode == nullptr) return true;
        if (firstNode == nullptr || secondNode == nullptr) return false;
        if (firstNode->val != secondNode->val) return false;

        return isSameTree(firstNode->left, secondNode->left) && isSameTree(firstNode->right, secondNode->right);
    }

    bool preorderDFS(TreeNode* root, TreeNode* subRoot) {
        if(root == nullptr) return false;

        if(isSameTree(root, subRoot) == true) return true;

        return preorderDFS(root->left, subRoot) || preorderDFS(root->right, subRoot);
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return preorderDFS(root, subRoot);
    }
};
