class Solution {
public:
	vector<int>	getkValidCandidates(vector<int>&nums, map<int,int>candidates, int k){
		map<int,int> candidatesCount;
		for(auto num : nums){
			if(candidates[num]){
				candidatesCount[num]++;
			}
		}
		vector<int> ans;
		int threshold = nums.size() / k;
		for(auto it : candidatesCount){
			if(it.second > threshold){
				ans.push_back(it.first);
			}
		}
		return ans;
	}

    vector<int> getCandidateElements(vector<int>&nums, int k){
    	int possibleCandidates=k-1 ;
    	bool zerocandidate;
    	map<int,int> candidates;

    	for(auto num : nums){
    		// if num is there in map
    		if(candidates[num]){
    			candidates[num]++;
    			continue;
    		}
    		//then,we will check if we have k-1 elements in map or not
    		if(candidates.size() < k-1){
    			candidates[num]++;
    			continue;
    		}
    		//then, we check if there exist a element in map with count = 0
    		zerocandidate = false;
    		for(auto it : candidates){
    			if(it.second == 0)
    				candidates.erase(it.first);
    				candidates[num]++;
    				zerocandidate=true;
    		}
    		//if none of the above it true then we decrement every candidates count by 1;
    		if(zerocandidate == false){
    			for(auto  it : candidates){
    				it.second = it.second-1;
    			}
    		}
    	}
    	return getkValidCandidates(nums,candidates,k);
    }
    
    vector<int> majorityElement(vector<int>& nums) {
        int k =3;
        return getCandidateElements(nums, k);
    }    
};