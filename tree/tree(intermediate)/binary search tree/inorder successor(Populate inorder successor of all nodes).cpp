void inorderSuccessor(Node *p, node *&succ)
{ // reverse inorder traversal
    if (p)
    {
        inorderSuccessor(p->right, succ);
        p->next = succ;
        succ = p;
        inorderSuccessor(p->left, succ);
    }
}
void populateNext(Node *p)
{
    node *succ = NULL;
    inorderSuccessor(p, succ);
}
