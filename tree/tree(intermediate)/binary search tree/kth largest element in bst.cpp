void reverseInorder(Node* root,int k,int &count1,int &result){
    if(root == NULL || count1>=k)
        return;
    reverseInorder(root->right,k,count1,result);
    count1++;
    if(count1 == k) 
        result=root->data;
    reverseInorder(root->left,k,count1,result);
}
int kthLargest(Node* root, int k) {
    int result=INT_MIN;
    int count1=0;
    reverseInorder(root,k,count1,result);
    return result;
}