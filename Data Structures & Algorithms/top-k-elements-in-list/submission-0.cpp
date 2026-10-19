class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        vector<pair<int, int>> n;
        vector<int> a;

        for (const int& num : nums) {
            if (m.find(num) == m.end()) {
                m[num] = 1;
            } else {
                m[num]++;
            }
        }

        for (const auto& [key, value] : m) {
            n.push_back(pair(key, value));
        }

        sort(n.begin(), n.end(), [](const auto& a, const auto& b){
            return a.second < b.second;
        });

        for (int i=0; i<k; i++) {
            pair<int, int> t = n.back();
            n.pop_back();
            a.push_back(t.first);
        }

        return a;
    }
};
