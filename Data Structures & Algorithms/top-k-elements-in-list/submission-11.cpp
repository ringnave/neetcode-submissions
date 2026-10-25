class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int, int> count;
        count.reserve(nums.size());
        vector<vector<int>> buckets(nums.size() + 1);

        for (int num : nums) {
            ++count[num];
        }

        for (const auto& [key, value] : count) {
            buckets[value].push_back(key);
        }

        for (int i = nums.size(); i >= 0; --i) {
            if (buckets[i].empty()) continue;

            for (int n : buckets[i]) {
                res.push_back(n);

                if (res.size() == k) return res;
            }
        }

        return res;
    }
};
