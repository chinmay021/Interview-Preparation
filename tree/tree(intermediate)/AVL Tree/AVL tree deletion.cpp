Node* minValNode(Node* node){
	Node* current = node;
	while(current>left != NULL){
		current=current->left;
	}
	return current;
}

Node* rightRotate(Node* root){
	Node* newRoot = root->left;
	root->left = newRoot->right;
	newRoot->right = root;
  
    // Update heights  
    root->height = max(height(root->left), 
                    height(root->right)) + 1;  
    newRoot->height = max(height(newRoot->left), 
                    height(newRoot->right)) + 1;  
  
    // Return new root  
    return newRoot;
}

Node* leftRotate(Node* root){
	Node* newRoot = root->right;
	root->right = newRoot->left;
	newRoot->left = root;
  
    // Update heights  
    root->height = max(height(root->left), 
                    height(root->right)) + 1;  
    newRoot->height = max(height(newRoot->left), 
                    height(newRoot->right)) + 1;  
  
    // Return new root  
    return newRoot;
}

int getBalance(Node* root){
	if(root == NULL)
		return 0;
	return height(root->left) - height(root->right);
}

int height(Node* root){
	if(root == NULL)
		return 0;
	return root->height;
}

Node* deleteNode(Node* root, int key)  
{  
      
    // STEP 1: PERFORM STANDARD BST DELETE  
    if (root == NULL)  
        return root;  
  
    // If the key to be deleted is smaller  
    // than the root's key, then it lies 
    // in left subtree  
    if ( key < root->data )  
        root->left = deleteNode(root->left, key);  
  
    // If the key to be deleted is greater  
    // than the root's key, then it lies  
    // in right subtree  
    else if( key > root->data )  
        root->right = deleteNode(root->right, key);  
  
    // if key is same as root's key, then  
    // This is the node to be deleted  
    else
    {  
        if(root->left==NULL && root->right==NULL)
        {
            root=NULL;
            delete root;
        
        }
        else if(root->left==NULL)
        {
            Node* temp=root;
            root=root->right;
            delete temp;
        }
        else if(root->right==NULL)
        {
            Node* temp=root;
            root=root->left;
            delete temp;
        }
        else
        {
            Node* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right=deleteNode(root->right,root->data);
        }  
    }  
  
    // If the tree had only one node 
    // then return  
    if (root == NULL)  
    return root;  
  
    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE  
    root->height = 1 + max(height(root->left),  
                           height(root->right));  
  
    // STEP 3: GET THE BALANCE FACTOR OF  
    // THIS NODE (to check whether this  
    // node became unbalanced)  
    int balance = getBalance(root);  
  
    // If this node becomes unbalanced,  
    // then there are 4 cases  
  
    // Left Left Case  
    if (balance > 1 &&  
        getBalance(root->left) >= 0)  
        return rightRotate(root);  
  
    // Left Right Case  
    if (balance > 1 &&  
        getBalance(root->left) < 0)  
    {  
        root->left = leftRotate(root->left);  
        return rightRotate(root);  
    }  
  
    // Right Right Case  
    if (balance < -1 &&  
        getBalance(root->right) <= 0)  
        return leftRotate(root);  
  
    // Right Left Case  
    if (balance < -1 &&  
        getBalance(root->right) > 0)  
    {  
        root->right = rightRotate(root->right);  
        return leftRotate(root);  
    }  
  
    return root;  
} 