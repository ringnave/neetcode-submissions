class Solution {
public:
    bool isPalindrome(string s) {
        string sanitized = "";

        for (char c : s) {
            if ('A' <= c && c <= 'Z' || 'a' <= c && c <= 'z' || '0' <= c && c <= '9') {
                if ('A' <= c && c <= 'Z') {
                    sanitized += (c + 32);
                    continue;
                }
                sanitized += c;
            }
        }
        
        int i = 0;
        int j = sanitized.length() - 1;
        while (i < j) {
            if (sanitized[i] != sanitized[j]) return false;

            ++i;
            --j;
        }

        return true;
    }
};
