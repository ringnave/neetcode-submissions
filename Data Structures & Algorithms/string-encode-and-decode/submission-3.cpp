class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "";
        
        for (const string& str : strs) {
            encoded += to_string(str.length());
            encoded += '#';
            encoded += str;
        }

        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        int i=0;
        
        while (i < s.length()) {
            int j = s.find('#', i);
            int len = stoi(s.substr(i, j - i));
            
            decoded.push_back(s.substr(j + 1, len));
            i = j + len + 1;
        }

        return decoded;
    }
};
