class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prefix{1};
        int postfix{1};
        int n = nums.size();
        vector<int> res(n, 1);

        for (int i = 0; i < n; ++i) {
            res[i] = prefix;
            prefix *= nums[i];
        }

        for (int j = n - 1; j >= 0; --j) {
            res[j] *= postfix;
            postfix *= nums[j];
        }

        return res;
    }
};
