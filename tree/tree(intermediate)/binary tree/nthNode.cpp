void nthinorder(Node* root, int n) {
		static int count=0;
		if(root!=NULL && count < n) {
			nthinorderUtil(root->left,n);
			count++;
			if(count==n) {
				cout<<root->data;
				return;
			}	
			nthinorder(root->right, n);
		}
	}