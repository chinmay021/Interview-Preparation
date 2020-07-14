class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL){
            return NULL;
        }
        if(root == p || root == q ){
            return root;
        }
        TreeNode* leftSearch=lowestCommonAncestor(root->left, p, q);
        TreeNode* rightSearch=lowestCommonAncestor(root->right, p, q);
        if(leftSearch != NULL && rightSearch != NULL){
            return root;
        }
        return leftSearch ? leftSearch : rightSearch;
    }
};