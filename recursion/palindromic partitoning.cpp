class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;
        partitionUtil(ans, curr, 0, s.size(),s);
        return ans;
    }
private:
    void partitionUtil(vector<vector<string>> &ans, vector<string> &curr,  int start, int end, string str){
        if(start == end){
            ans.push_back(curr);
            return;
        }
        for(int i =start ; i<end; ++i){
            if(isPalindrome(str, start, i)){
                curr.push_back(str.substr(start, i-start+1));
                partitionUtil(ans, curr, i+1, end, str);
                curr.pop_back();
            }
        }
    }
    bool isPalindrome(string str, int low, int high){
        while(low < high)
        {
            if(str[low] != str[high]){
                return false;
            }
            low++;
            high--;
        } 
        return true;
    }
};