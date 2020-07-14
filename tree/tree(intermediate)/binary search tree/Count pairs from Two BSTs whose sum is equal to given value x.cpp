void fill(Node* root,unordered_map<int,bool> &mp1)
{
    if(root == NULL)
        return;
    mp1[root->data] = true;
    fill(root->left,mp1);
    fill(root->right,mp1);
    return;
}
int countPairs(Node* root1, Node* root2, int x)
{
    int result = 0;
    unordered_map<int,bool> mp1,mp2;
    fill(root1,mp1);
    fill(root2,mp2);
    for(auto it = mp1.begin();it!= mp1.end();it++)
    {
        if(mp2[x-(it->first)] == true)
        result++;
    }
    return result;

}



// recursive apporach 

bool search(Node* root, int val)
{
    bool flag=false;
    if(root!=NULL)
    {
        if(root->data==val||search(root->left,val)||search(root->right,val))
        flag=true;

    }
    return flag;
}
int countPairs(Node* root1, Node* root2, int x)
{
    if(root1==NULL)
        return 0;
    else if(search(root2,x-root1->data))
        return 1+countPairs(root1->left,root2,x)+countPairs( root1->right,root2, x);
    else
        return countPairs(root1->left,root2,x)+countPairs( root1->right,root2, x);
}