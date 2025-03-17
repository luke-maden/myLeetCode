class Solution {
public:
    int maxArea(vector<int>& height) {
        int ptr1 = 0;
        int ptr2 = height.size() - 1;
        int maxVol = 0;
        int current;

        while(ptr1 < ptr2){
            current = min(height[ptr1], height[ptr2]) * (ptr2 - ptr1);
            maxVol = max(current, maxVol);

            if(height[ptr1] > height[ptr2]){
                ptr2--;
            } else {
                ptr1++;
            }
        }

        return maxVol;

    }
};