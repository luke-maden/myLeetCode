class Solution {
public:
    int findGCD(vector<int>& nums) {
        int largest = nums[0];
        int smallest = nums[0];
        int div;

        for(int i = 1; i < nums.size(); i++){
            largest = max(largest, nums[i]);
            smallest = min(smallest, nums[i]);
        }

        div = smallest;

        while(div > 0){
            if(largest % div == 0 & smallest % div == 0){
                return div;
            }

            div--;
        }


        return div;
    }
};