class Solution {
public:
    int result=INT_MIN;
    int count=0;
    void inorder(TreeNode* root,int k){
        if(root == NULL)
            return;
        inorder(root->left,k);
        count++;
        if(count == k) 
            result=root->val;
        inorder(root->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        inorder(root,k);
        return result;
    }
};