/*

Given a binary tree, determine if it is 
height-balanced

A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.

*/

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

    int height(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        
        int lefth = height(root->left);
        int righth = height(root->right);
        int h = 1 + max(lefth, righth);
        return h; 
    }

    bool isBalanced(TreeNode* root) {
        
        if(root == NULL){
            return true;
        }

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        int diff =  abs(leftHeight-rightHeight);
        int ans1 = diff <= 1;

        bool leftans = isBalanced(root->left);
        bool rightans = isBalanced(root->right);

        if(ans1 && leftans && rightans){
            return true;
        }
        else {
            return false;
        }
    }
};