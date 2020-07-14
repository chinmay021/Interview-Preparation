class Solution {
public:
    int ans;
    void dfs(TreeNode* root, int L, int R){
        if(root == NULL)
            return;
        if(root->val >=L && root->val <= R){
            ans+=root->val;
        }
        if(root->val > L)
            dfs(root->left,L,R);
        if(root->val < R)
            dfs(root->right,L,R);
    }
    int rangeSumBST(TreeNode* root, int L, int R) {
        ans=0;
        dfs(root,L,R);
        return ans;
    }
};