class Solution {
    TreeNode* sortedArrayToBSTUtil(vector<int>& nums, int start, int end){
        if(start > end) return NULL; 
        int midIdx =  start + (end - start)  / 2;
        TreeNode* root = new TreeNode( nums[midIdx] );
        root->left = sortedArrayToBSTUtil(nums, start, midIdx-1);
        root->right = sortedArrayToBSTUtil(nums, midIdx+1,end);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBSTUtil(nums, 0,nums.size()-1);
    }
}