void sumOfLongRootToLeafPathUtil(Node* root, int current_len, int current_sum, int &max_sum, int &max_len){
    if(root == NULL){
        if(current_len > max_len){
            max_sum=current_sum;
            max_len=current_len;
        }
        else if(current_len == max_len && current_sum > max_sum){
            max_sum=current_sum;
        }
        return;
    }
    sumOfLongRootToLeafPathUtil(root->left, current_len+1, current_sum+root->data, max_sum, max_len);
    sumOfLongRootToLeafPathUtil(root->right, current_len+1, current_sum+root->data, max_sum, max_len);
}
int sumOfLongRootToLeafPath(Node* root)
{
    if( root == NULL)
        return 0;
    int current_len=0,current_sum=0;
    int max_len=0;
    int max_sum=INT_MIN;
	sumOfLongRootToLeafPathUtil(root,current_len,current_sum, max_sum, max_len);
	return max_sum;
}