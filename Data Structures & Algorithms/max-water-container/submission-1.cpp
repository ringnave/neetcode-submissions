class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left{0};
        int right = heights.size() - 1;
        int max_size = 0;

        while (left < right) {
            int width = right - left;
            int size = min(heights[left], heights[right]) * width;

            max_size = max(max_size, size);

            if (heights[left] < heights[right]) {
                ++left;
            } else {
                --right;
            }
        }

        return max_size;
    }
};
