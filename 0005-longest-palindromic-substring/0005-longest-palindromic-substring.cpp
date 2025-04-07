class Solution {
public:
    string longestPalindrome(string s) {
    int start = 0, end = 0;

    for (int i = 0; i < s.length(); i++) {
        // odd length
        int len1 = expandFromCenter(s, i, i);
        // even length
        int len2 = expandFromCenter(s, i, i + 1);
        int len = max(len1, len2);

        if (len > end - start + 1) {
            start = i - (len - 1) / 2;
            end = i + len / 2;
        }
    }

    return s.substr(start, end - start + 1);
}

int expandFromCenter(string &s, int left, int right) {
    while (left >= 0 && right < s.length() && s[left] == s[right]) {
        left--;
        right++;
    }
    return right - left - 1;  
}
};