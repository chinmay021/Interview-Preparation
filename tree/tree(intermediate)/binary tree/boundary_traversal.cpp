void leftBoundary(Node* root){
   if (root ==NULL) return;
   if(root->left){
       cout<<root->data<<" ";
       leftBoundary(root->left);
   }
   else if(root->right){
       cout<<root->data<<" ";
       leftBoundary(root->right);
   }
}
void leafNode(Node* root){
    if( root == NULL ) return;
    
    if(root->left == NULL && root->right ==NULL){
        cout<<root->data<<" ";
    }
    leafNode(root->left);
    leafNode(root->right);
    
}

void rightBoundary(Node* root){
    if (root ==NULL) return;
   if(root->right){
       rightBoundary(root->right);
       cout<<root->data<<" ";
   }
   else if(root->left){
       rightBoundary(root->left);
       cout<<root->data<<" ";
   }
}
void printBoundary(Node *root)
{
    if(!root) return;
    cout<<root->data<<" ";
     leftBoundary(root->left);
     leafNode(root->left);
     leafNode(root->right);
     rightBoundary(root->right);
}