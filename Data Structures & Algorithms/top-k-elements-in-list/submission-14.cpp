class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        // count.reserve(nums.size());
        
        for (int num : nums) {
            ++count[num];
        }

        vector<vector<int>> buckets(nums.size() + 1);

        for (const auto& [key, value] : count) {
            buckets[value].push_back(key);
        }

        vector<int> res;
        res.reserve(k);

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
