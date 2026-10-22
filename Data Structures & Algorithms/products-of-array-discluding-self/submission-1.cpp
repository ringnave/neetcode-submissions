class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prefix = 1;
        int postfix = 1;
        int len = nums.size();
        vector<int> ans(len);
        
        for (int i = 0; i < len; ++i) {
            ans[i] = prefix;
            prefix *= nums[i];
        }

        for (int i = len - 1; i >= 0; --i) {
            ans[i] *= postfix;
            postfix *= nums[i];
        }

        return ans;
    }
};
