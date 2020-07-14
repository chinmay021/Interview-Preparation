void inorder(Node* root, vector<int> &v){
    if(root == NULL)
        return;
    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
}

void convertToBST(Node* root, vector<int> &v,int &index){
    if(root == NULL)
        return;
    convertToBST(root->left,v,index);
    root->data=v[index];
    index++;
    convertToBST(root->right,v,index);
}
Node *binaryTreeToBST (Node *root)
{
    vector<int> v;
    inorder(root,v);
    sort(v.begin(),v.end());
    int index=0;
    convertToBST(root,v,index);
    return root;
}