 */
class Solution {
public:
    TreeNode* bstFromPreorderUtil(vector<int> &preorder, int low, int high){
        if(low>high){
            return NULL;
        }
        TreeNode* node = new TreeNode(preorder[low]);
        int mid;
        for(mid= low+1; mid<=high; ++mid){
            if(preorder[mid] > preorder[low])
                break;
        }
        node->left=bstFromPreorderUtil(preorder,low+1,mid-1);
        node->right=bstFromPreorderUtil(preorder,mid,high);
        return node;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size() == 0)
            return NULL;
        int preindex=0;
        return bstFromPreorderUtil(preorder,0,preorder.size()-1);
    }
};