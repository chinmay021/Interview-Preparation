#include <bits/stdc++.h>
using namespace std;

/*
	contruction of interval tree
*/
struct Interval
{
	int low, high;
};

struct IntervalTreeNode
{
	Interval* i;
	int max;
	IntervalTreeNode *left, *right;
};

IntervalTreeNode* newNode(Interval i)
{
	IntervalTreeNode* temp=new IntervalTreeNode;
	temp->i= new Interval(i); //aggrigate assignment
	temp->max=i.high;
	temp->left= temp->right =NULL;
};

IntervalTreeNode* insert(IntervalTreeNode* root,Interval i){
	if(root == NULL)
		return newNode(i);
	int l = root->i->low;
	if( i.low < l)
		root->left=insert(root->left,i);
	else
		root->right=insert(root->right,i);
	if(root->max < i.high)
		root->max=i.high;
	return root;
}
/*
	check overlapping and return the overlapping interval
*/


bool OverlapCheck(Interval i1, Interval i2){
	if(i1.low <= i2.high && i1.high >= i2.low)
		return true;
	return false;
}

Interval* overlapSearch(IntervalTreeNode* root, Interval i){
	if(root == NULL ) return NULL;

	if(OverlapCheck(*(root->i),i))
		return root->i;
	if(root->left != NULL && root->left->max >= i.low)
		return overlapSearch(root->left, i);
	return overlapSearch(root->right, i);
}
