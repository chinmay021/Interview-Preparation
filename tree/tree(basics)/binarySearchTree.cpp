#include<bits/stdc++.h>
using namespace std;


struct Node{
	int data;
	Node* left;
	Node* right;
	Node(int x){
		data=x;
		left=NULL;
		right=NULL;
	}
};

 struct Node* insert(Node* node, int data)
{
    if(node==NULL)
        return new Node(data);
    if(node->data>data)
        node->left=insert(node->left,data);
    else if(node->data<data)
        node->right=insert(node->right,data);
    return node;
}

void inorder(struct Node *root) 
{ 
    if (root != NULL) 
    { 
        inorder(root->left); 
        cout<<root->data<<" ";
        inorder(root->right); 
    } 
} 

void postorder(struct Node *root) 
{ 
    if (root != NULL) 
    { 
        postorder(root->left); 
        postorder(root->right); 
        cout<<root->data<<" ";
    } 
} 

void preorder(struct Node *root) 
{ 
    if (root != NULL) 
    { 
    	cout<<root->data<<" ";
        preorder(root->left); 
        preorder(root->right); 
    } 
} 
int findMin(Node* root)
{
    Node* temp=root;
    while(temp && temp->left!=NULL)
    temp=temp->left;
    return temp->data;
}
Node *deleteNode(Node *root, int x)
{
    if(root==NULL)
        return NULL;
    else if(root->data < x)
        root->right=deleteNode(root->right,x);
    else if(root->data > x)
        root->left= deleteNode(root->left,x);
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
            
            root->data=findMin(root->right);
            root->right=deleteNode(root->right,root->data);
        }
    }
    return root;
}
Node* level_order(Node* root){
	if(root==NULL)
		return root;
	queue<Node*>q;
	q.push(root);
	while(!q.empty()){
		Node* temp=q.front();
		q.pop();
		cout<<temp->data<<" ";
		if(temp->left)
			q.push(temp->left);
		if(temp->right)
			q.push(temp->right);
	}
}

bool search(Node* root, int x)
{
    if(root == NULL) 
    	return 0;
    Node* temp=root;
    if(x < temp->data){
        return search(temp->left,x);
    }
    if(x > temp->data){
        return search(temp->right,x);
    }
    if(x == temp->data){
        return 1;
    }
}
bool check_bst(Node* root,int min, int max){
	if(root==NULL)
		return true;
	if(root->data < min || root->data > max){
		return false;
	}
	check_bst(root->left,min,root->data);
	check_bst(root->right,root->data,max);
}

void dfs(Node* root, vector<string>& res, string path){
        path+=to_string(root->data);
        if(root->left==NULL && root->right==NULL){
            res.push_back(path);
            return;
        }
        if(root->left!=NULL){
            dfs(root->left,res,path+"->");
        }
        if(root->right!=NULL){
            dfs(root->right,res,path+"->");
        }
    }
vector<string> binaryTreePaths(Node* root) {
        vector<string> res;
        if(root==NULL)
            return res;
        dfs(root,res,"");//dfs(root,final array,current path array)
        return res;
}


// vertical order traversal
void getVerticalOrder(Node* root, int hd, map<int, vector<int>> &m) 
{ 
    if (root == NULL) 
        return; 
  
    m[hd].push_back(root->data); 
  
    getVerticalOrder(root->left, hd-1, m); 
   
    getVerticalOrder(root->right, hd+1, m); 
} 
  
void printVerticalOrder(Node* root) 
{ 
    map < int,vector<int> > m; 
    int hd = 0; 
    getVerticalOrder(root, hd,m); 
    for (auto it=m.begin(); it!=m.end(); it++) 
    { 
        for(auto x : (*it).second){
        cout<<x<<" ";
        }
        cout<<endl;
    } 
} 

// top view of a binary tree

void topView(Node *root)
{
    if(root==NULL)
    return;
    map<int,int> mp;
    queue<pair<Node*,int>> q;
    int hd=0;
    q.push(make_pair(root,hd));  
    while(!q.empty())
    {
        pair<Node*,int> curr=q.front();
        q.pop();
        Node* temp=curr.first;
        int hd=curr.second;
        if(!mp[hd]){
            mp[hd]=temp->data;
        }
        
        
        if(temp->left)
            q.push(make_pair(temp->left,hd-1));
        if(temp->right)
            q.push(make_pair(temp->right,hd+1));
    }
    for(auto it=mp.begin();it!=mp.end();it++)
        cout<<it->second<<" ";
}
void bottomView(struct Node *root)
{
    if(root==NULL)
    return;
    map<int,int> mp;
    queue<pair<Node*,int>> q;
    int hd=0;
    q.push(make_pair(root,hd));
    
    while(!q.empty())
    {
        pair<Node*,int> curr=q.front();
        q.pop();
        Node* temp=curr.first;
        int hd=curr.second;
        mp[hd]=temp->data;
        if(temp->left)
            q.push(make_pair(temp->left,hd-1));
        if(temp->right)
            q.push(make_pair(temp->right,hd+1));
    }
    for(auto it=mp.begin();it!=mp.end();it++)
        cout<<it->second<<" ";
}

void leftView(Node *root)
{
   if(root == NULL ) return;
       cout<<root->data<<" ";
       if(root->left){
           leftView(root->left);
       }
       else if(root->right){
           leftView(root->right);
       }
}

int main(int argc, char const *argv[])
{
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    struct Node *root = NULL; 
    root = insert(root, 50); 
    insert(root, 30); 
    insert(root, 20); 
    insert(root, 40); 
    insert(root, 70); 
    insert(root, 60); 
    insert(root, 80); 
    inorder(root);
    cout<<"\n";
    level_order(root);
    cout<<"\n";
    preorder(root);
    cout<<"\n";
    postorder(root);
    cout<<"\nsearch element: ";
    cout<<search(root,40);
    cout<<"\ncheck bst: "<<check_bst(root,INT_MIN,INT_MAX);
    cout<<"\nroot to node paths :";
    vector<string> v = binaryTreePaths(root);
    for (std::vector<string>::iterator i = v.begin(); i != v.end(); ++i)
    {
        cout<<*i<<"\n";
    }
    cout<<"\nvertical order traversal :\n";
    printVerticalOrder(root); 
    cout<<"top view: \n";
    topView(root);
    cout<<"\nbottom view: \n";
    bottomView(root);
    cout<<"\nleft view: \n";
    leftView(root);

	return 0;
}