class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> seen;
        vector<vector<string>> answer;

        for (string str : strs) {
            string original = str;
            sort(str.begin(), str.end());
            seen[str].push_back(original);
        }

        for (const auto& [key, values]: seen) {
            answer.push_back(values);
        }

        return answer;
    }
};
