void inorderSuccessor(node* p, node* &next){ // reverse inorder traversal
    if (p)  
    {  
        inorderSuccessor(p->right,next);  
        p->next = next;  
        next = p;  
        inorderSuccessor(p->left,next);  
    }
}
void populateNext(node* p)  
{  
    node *next = NULL;  
    inorderSuccessor(p,next); 
}  