#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int x)
    { // constructor
        data = x;
        left = NULL;
        right = NULL;
    }
};

void insert(Node *root, int key)
{
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    { //checks level wise
        Node *temp = q.front();
        q.pop();
        if (temp->left == NULL)
        {
            temp->left = new Node(key);
            break;
        }
        else
            q.push(temp->left);

        if (temp->right == NULL)
        {
            temp->right = new Node(key);
            break;
        }
        else
            q.push(temp->right);
    }
}

void deletionBT(struct Node *root, int key)
{
    if (!root->left && !root->right)
    {
        if (root->data == key)
        {
            root = NULL;
            return;
        }
    }

    queue<Node *> q;
    q.push(root);
    Node *toDelete = NULL;
    Node *current = NULL;
    Node *parent = NULL;
    while (!q.empty())
    {
        current = q.front();

        if (current->data == key)
        {
            toDelete = current;
        }

        if (current->left)
        {
            q.push(current->left);
            parent = current;
        }

        if (current->right)
        {
            q.push(current->right);
            parent = current;
        }
        q.pop();
    }

    int temp = toDelete->data;
    toDelete->data = current->data;
    current->data = temp;

    if (parent->left)
        if (parent->left->data == key)
        {
            parent->left = NULL;
        }

    if (parent->right)
        if (parent->right->data == key)
        {
            parent->right = NULL;
        }
}

void inorder_traversal_recursive(Node *root)
{
    if (root == NULL)
        return;
    inorder_traversal_recursive(root->left);
    cout << root->data << " ";
    inorder_traversal_recursive(root->right);
}

void inorder_traversal_iterative(struct Node *root) // left current right
{
    stack<Node *> s;
    Node *curr = root;

    while (curr != NULL || s.empty() == false)
    {

        while (curr != NULL)
        {
            s.push(curr);
            curr = curr->left;
        }

        curr = s.top();
        s.pop();

        cout << curr->data << " ";
        /* we have visited the node and its 
           left subtree.  Now, it's right 
           subtree's turn */
        curr = curr->right;
    }
}

void preorder_traversal_recursive(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    postorder_traversal_recursive(root->left);
    postorder_traversal_recursive(root->right);
}

void preorder_traversal_iterative(node *root) //current left right
{
    /*1) Create an empty stack nodeStack and push root node to stack.
	2) Do following while nodeStack is not empty.
	….a) Pop an item from stack and print it.
	….b) Push right child of popped item to stack
	….c) Push left child of popped item to stack*/
    // Base Case
    stack<Node *> s;

    s.push(root);

    while (!s.empty())
    {
        auto curr = s.top();
        cout << curr->data << " ";
        s.pop();
        if (curr->right)
            s.push(curr->right);
        if (curr->left)
            s.push(curr->left);
    }
}
void postorder_traversal_iterative(Node *root) // left right current
{

    if (root == NULL)
        return;

    // Create two stacks
    stack<Node *> s1, s2;

    // push root to first stack
    s1.push(root);
    Node *node;

    // Run while first stack is not empty
    while (!s1.empty())
    {
        // Pop an item from s1 and push it to s2
        node = s1.top();
        s1.pop();
        s2.push(node);

        // Push left and right children
        // of removed item to s1
        if (node->left)
            s1.push(node->left);
        if (node->right)
            s1.push(node->right);
    }

    // Print all elements of second stack
    while (!s2.empty())
    {
        node = s2.top();
        s2.pop();
        cout << node->data << " ";
    }
}

void postorder_traversal_recursive(Node *root)
{
    if (root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}
void levelOrder(Node *node) //level order traversal
{
    if (node == NULL)
        return;
    queue<Node *> q;
    q.push(node);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        cout << temp->data << " ";
        if (temp->left)
        {
            q.push(temp->left);
        }
        if (temp->right)
        {
            q.push(temp->right);
        }
    }
}

void levelOrder(Node *node) //level order traversal line by line i.e 1 \n 2 3 \n 4 5 6 7
{
    if (node == NULL)
        return;
    queue<Node *> q;
    q.push(node);
    while (!q.empty())
    {
        int node_count = q.size();
        while (node_count > 0)
        {
            Node *temp = q.front();
            q.pop();
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
            node_count--;
        }
        cout << "\n"
             << " ";
    }
}

void reversePrint(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> q;
    stack<Node *> s;
    q.push(root);
    Node *temp = NULL;
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        if (temp->right)
        {
            q.push(temp->right);
        }
        if (temp->left)
        {
            q.push(temp->left);
        }
        s.push(temp);
    }
    while (!s.empty())
    {
        cout << s.top()->data << " ";
        s.pop();
    }
}

void printSpiral(struct node *root)
{
    if (root == NULL)
        return; // NULL check

    // Create two stacks to store alternate levels
    stack<struct node *> s1; // For levels to be printed from right to left
    stack<struct node *> s2; // For levels to be printed from left to right

    // Push first level to first stack 's1'
    s1.push(root);

    // Keep printing while any of the stacks has some nodes
    while (!s1.empty() || !s2.empty())
    {
        // Print nodes of current level from s1 and push nodes of
        // next level to s2
        while (!s1.empty())
        {
            struct node *temp = s1.top();
            s1.pop();
            cout << temp->data << " ";

            // Note that is right is pushed before left
            if (temp->right)
                s2.push(temp->right);
            if (temp->left)
                s2.push(temp->left);
        }

        // Print nodes of current level from s2 and push nodes of
        // next level to s1
        while (!s2.empty())
        {
            struct node *temp = s2.top();
            s2.pop();
            cout << temp->data << " ";

            // Note that is left is pushed before right
            if (temp->left)
                s1.push(temp->left);
            if (temp->right)
                s1.push(temp->right);
        }
    }
}

bool searchNode(Node *root, key)
{
    if (root == NULL)
        return false;
    if (root->data == key)
        return true;
    if (searchNode(root->left, key))
        return true;
    if (searchNode(root->right, key))
        return true;
    return false;
}

int height(Node *node)
{
    if (node == NULL)
        return 0;
    int heightleft = height(node->left);
    int heightright = height(node->right);
    return (1 + max(heightleft, heightright));
}

int diameter(Node *node)
{
    if (node == NULL)
        return 0;

    //passing through root
    int leftheight = height(node->left);
    int rightheight = height(node->right);
    int rootdiameter = leftheight + rightheight + 1;
    //not passing through root
    int leftdiameter = diameter(node->left);
    int rightdiameter = diameter(node->right);
    int res = max(rootdiameter, max(leftdiameter, rightdiameter));
    return res;
}

void mirror(Node *node)
{
    if (node == NULL)
        return;
    mirror(node->left);
    mirror(node->right);
    swap(node->left, node->right);
}

//balanced binary tree(diff between left subtree or right subtree should be less than 1 for any given node)

//O(NlogN0)
int height(TreeNode *node)
{
    if (node == NULL)
        return 0;
    int heightleft = height(node->left);
    int heightright = height(node->right);
    return (1 + max(heightleft, heightright));
}
bool isBalanced(TreeNode *root)
{
    if (root == NULL)
        return 1;
    int lheight = height(root->left);
    int rheight = height(root->right);
    if (abs(lheight - rheight) <= 1 && isBalanced(root->left) && isBalanced(root->right))
        return 1;
    return 0;
}

//O(N)
int dfsHeight(TreeNode *root)
{
    if (root == NULL)
        return 0;

    int leftHeight = dfsHeight(root->left);
    int rightHeight = dfsHeight(root->right);

    if (abs(leftHeight - rightHeight) > 1 || (leftHeight == -1) || (rightHeight == -1))
        return -1;
    return max(leftHeight, rightHeight) + 1;
}
bool isBalanced(TreeNode *root)
{
    return dfsHeight(root) != -1;
}

// Returns maximum value in a given Binary Tree
int findMax(struct node *root)
{
    if (root == NULL)
        return INT_MIN;
    if (root)
    {
        int res = root->data;
        int lmax = findMax(root->left);
        int rmax = findMax(root->right);
        return max(res, max(lmax, rmax));
    }
}

// Returns minimum value in a given Binary Tree
int findMin(struct node *root)
{
    if (root == NULL)
        return INT_MAX;
    if (root)
    {
        int res = root->data;
        int lmin = findMin(root->left);
        int rmin = findMin(root->right);
        return min(res, min(lmin, rmin));
    }
}

//bst
Node *insert(Node *node, int data)
{
    if (node == NULL)
        return newNode(data);
    if (node->data > data)
        node->left = insert(node->left, data);
    else if (node->data < data)
        node->right = insert(node->right, data);
    return node;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    Node *root = new Node(0);

    cout << "Inorder traversal before insertion:";
    inorder_traversal(root);

    for (int i = 1; i < 15; ++i)
    {
        insert(root, i);
    }

    cout << endl;
    cout << "\nInorder traversal after insertion:";
    inorder_traversal(root);

    return 0;
}