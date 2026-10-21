class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "";

        for (const string& str : strs) {
            int len = str.length();
            encoded += to_string(len);
            encoded += '#';
            encoded += str;
        }

        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;

        int i = 0;
        while (i < s.length()) {
            int j = s.find('#', i);
            int len = stoi(s.substr(i, j - i));
            string word = s.substr(j + 1, len);

            decoded.push_back(word);

            i = j + len + 1;
        }

        return decoded;
    }
};
