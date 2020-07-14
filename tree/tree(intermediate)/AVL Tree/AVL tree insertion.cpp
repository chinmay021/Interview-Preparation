#include <bits/stdc++.h>
using namespace std;

class Node{
public:
	int key;
	Node* left;
	Node* right;
	int height;
};

int height(Node* root){
	if(root == NULL)
		return 0;
	return root->height;
}

Node* newNode(int key){
	Node* node= new Node();
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	node->height=1;

	return(node);
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

int getBalanceFactor(Node* root){
	if(root == NULL)
		return 0;
	return height(root->left) - height(root->right);
}

Node* insert(Node* root, int key){
	//normal BST insertion
	if(root == NULL){
		return newNode(key);
	}
	if(key < root->key)
		root->left = insert(root->left,key);
	else if(key > root->key)
		root->right = insert(root->right,key);
	//update height of this ancestor node
	root->height=1+ max(height(root->left),height(root->right));

	//get the balance factor for the node
	int balance = getBalanceFactor(root);

	/* if unbalanced ,then 4 cases possible
		1) left left case
		2) left right case
		3) right right case
		4) right left case
	
	if(balanceFactor > 1) // left subtree is longer than right subtree
	{
		if(height(root->left->left) > height(root->left->right)){
			 // left left case = right rotation
			root = rightRotate(root);
		}
		else{
			//left rotation of left child followed by right rotation of the root
			root->left = leftRotate(root->left);
			root = rightRotate(root);
		}
	}
	else{ //right subtree is longer than left subtree
		if(height(root->right->right) > height(root->right->left)){
			//right right case = left rotation
			root = leftRotate(root);
		}
		else{
			//right rotation of right child followed by left rotation of the root
			root->right = rightRotate(root->right);
			root = leftRotate(root);
		}
	}*/
	// or this condition can also be followed
	//LEFT LEFT CASE
	if (balance > 1 && key < root->left->key)  
        return rightRotate(root);  
  
    // Right Right Case  
    if (balance < -1 && key > root->right->key)  
        return leftRotate(root);  
  
    // Left Right Case  
    if (balance > 1 && key > root->left->key)  
    {  
        root->left = leftRotate(root->left);  
        return rightRotate(root);
    }  
  
    // Right Left Case  
    if (balance < -1 && key < root->right->key)  
    {  
        root->right = rightRotate(root->right);  
        return leftRotate(root);  
    }  
	return root;
}
void preOrder(Node *root)  
{  
    if(root != NULL)  
    {  
        cout << root->key << " ";  
        preOrder(root->left);  
        preOrder(root->right);  
    }  
}  
  
// Driver Code 
int main()  
{  
    Node *root = NULL;  
      
    /* Constructing tree given in  
    the above figure */
    root = insert(root, 10);  
    root = insert(root, 20);  
    root = insert(root, 30);  
    root = insert(root, 40);  
    root = insert(root, 50);  
    root = insert(root, 25);  
    root = insert(root, 60);
    root = insert(root, 45);
      
    /* The constructed AVL Tree would be  
                30  
            / \  
            20 40  
            / \ \  
        10 25 50  
    */
    cout << "Preorder traversal of the "
            "constructed AVL tree is \n";  
    preOrder(root);  
      
    return 0;  
}