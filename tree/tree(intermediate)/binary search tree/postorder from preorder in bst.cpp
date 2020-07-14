vector<int> v;
void findPostOrderUtil(int pre[], int n, int minval, int maxval, int& preIndex) 
{ 

    if (preIndex == n) 
        return; 
    if (pre[preIndex] < minval || pre[preIndex] > maxval) { 
        return; 
    } 
    int val = pre[preIndex]; 
    preIndex++; 
  
    findPostOrderUtil(pre, n, minval, val, preIndex);  
    findPostOrderUtil(pre, n, val, maxval, preIndex); 
  
    v.push_back(val);
} 
  
// Function to find postorder traversal. 
vector<int> findPostOrder(int pre[], int n) 
{ 
    int preIndex = 0; 
  
    findPostOrderUtil(pre, n, INT_MIN, INT_MAX, preIndex); 
    return v;
} 