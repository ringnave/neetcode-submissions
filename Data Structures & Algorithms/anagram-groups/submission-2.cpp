class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> seen;
        vector<vector<string>> answer;

        for (string& str : strs) {
            string original = str;
            sort(str.begin(), str.end());
            seen[str].push_back(original);
        }

        answer.reserve(seen.size());
        for (const auto& [key, values]: seen) {
            answer.push_back(move(values));
        }

        return answer;
    }
};
