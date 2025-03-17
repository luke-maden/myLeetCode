class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, bool> freq;

        for(int i = 0; i < nums.size(); i++){
            freq[nums[i]] = !freq[nums[i]];
        }

        for(auto i = freq.begin(); i != freq.end(); i++){
            if(i->second){
                return false;
            }
        }

        return true;
    }
};