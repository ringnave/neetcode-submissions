class Solution {
public:
    int trap(vector<int>& height) {
        int total_water{0};
        int left{0};
        int right = height.size() - 1;
        int left_max = height[left];
        int right_max = height[right];

        while (left < right) {
            if (height[left] < height[right]) {
                ++left;
                left_max = max(left_max, height[left]);
                total_water += left_max - height[left];
            } else {
                --right;
                right_max = max(right_max, height[right]);
                total_water += right_max - height[right];
            }
        }

        return total_water;
    }
};
