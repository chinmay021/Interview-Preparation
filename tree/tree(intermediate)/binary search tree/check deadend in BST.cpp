bool checkDeadEnd(Node* root, int min, int max){
    if(root == NULL)
        return false;
    if(min == max)
        return true;
    return ( checkDeadEnd(root->left, min, root->data - 1) || checkDeadEnd(root->right, root->data + 1, max) );
}
bool isDeadEnd(Node *root)
{
    return checkDeadEnd(root, 1, INT_MAX);
}