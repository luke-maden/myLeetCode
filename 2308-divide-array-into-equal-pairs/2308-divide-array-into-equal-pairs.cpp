class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_set<int> numSet;

        for(int i = 0; i < nums.size(); i++){
            if(numSet.contains(nums[i])){
                numSet.erase(nums[i]);
            } else {
                numSet.insert(nums[i]);
            }
        }

        if(numSet.size() == 0){
            return true;
        }

        return false;
    }
};