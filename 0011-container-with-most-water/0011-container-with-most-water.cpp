class Solution {
public:
    int maxArea(vector<int>& height) {
        int ptr1 = 0;
        int ptr2 = height.size() - 1;
        int max = 0;
        int current;

        while(ptr1 < ptr2){
            if(height[ptr1] > height[ptr2]){
                current = height[ptr2] * (ptr2 - ptr1);
                if(current > max){
                    max = current;
                }

                ptr2--;
            } else {
                current = height[ptr1] * (ptr2 - ptr1);
                if(current > max){
                    max = current;
                }

                ptr1++;
            }
        }

        return max;

    }
};