/*
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if(root == NULL){
            return NULL;
        }

        if(root->val == p->val){
            return p;
        }
        if(root->val == q->val){
            return q;
        }
        TreeNode* leftans = lowestCommonAncestor(root->left,p,q);
        TreeNode* rightans = lowestCommonAncestor(root->right,p,q);

        if(leftans == NULL && rightans ==  NULL){
            return NULL;
        }
        else if(leftans!=NULL && rightans == NULL){
            return leftans;
        }
        else if(leftans == NULL && rightans != NULL){
            return rightans;
        }
        else{
            return root;
        }        
    }
};