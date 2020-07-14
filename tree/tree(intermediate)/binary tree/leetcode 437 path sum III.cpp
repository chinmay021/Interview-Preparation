/*You are given a binary tree in which each node contains an integer value.

Find the number of paths that sum to a given value.

The path does not need to start or end at the root or a leaf,
 but it must go downwards (traveling only from parent nodes to child nodes).*/

class Solution {
public:
    int count=0;
    void findPath(TreeNode* root, int sum){
        if(root == NULL){
            return;
        }
        if(root->val == sum){
            count++;
        }
        findPath(root->left,sum-root->val);
        findPath(root->right,sum-root->val);
    }
    int pathSum(TreeNode* root, int sum) {
        if(root == NULL)
            return 0;
        findPath(root,sum);
        pathSum(root->left,sum);
        pathSum(root->right,sum);
        return count;
    }
};