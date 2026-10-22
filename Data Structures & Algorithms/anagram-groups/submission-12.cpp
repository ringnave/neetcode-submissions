class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> seen;
        seen.reserve(strs.size());

        for (const string& str : strs) {
            string sorted_str = str;
            sort(sorted_str.begin(), sorted_str.end());
            seen[sorted_str].push_back(str);
        }

        vector<vector<string>> ans;
        ans.reserve(strs.size());

        for (const auto& [key, val] : seen) {
            ans.push_back(val);
        }

        return ans;
    }
};
