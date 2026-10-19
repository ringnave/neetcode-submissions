class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;

        for (const int& num : nums) m[num]++;

        vector<vector<int>> buckets(nums.size() + 1);

        for (const auto& [key, val] : m) {
            buckets[val].push_back(key);
        }

        vector<int> answer;
        answer.reserve(k);

        for (int i=nums.size(); i>=0; i--) {
            for (const int& content : buckets[i]) {
                answer.push_back(content);
                if (answer.size() == k) return answer;
            }
        }

        return {};
    }
};
