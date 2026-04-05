class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            map<char, int> mp;
            int left = 0, right = 0;
            int maxLen = 0;
            while (right < s.size()) {
                if (mp.find(s[right]) != mp.end()) {
                    left = max(mp[s[right]] + 1, left);
                }
                mp[s[right]] = right;
                maxLen = max(maxLen, right - left + 1);
                right++;
            }
            return maxLen;
        }
    };
