class Solution {
    public:
        int longestConsecutive(vector<int>& nums) {
            unordered_set<int> map;
            int n = nums.size();
            if (n == 0) return 0;
            for (int i = 0; i < n; i++) {
                map.insert(nums[i]);
            }
    
            int longest = 0;
    
            for (auto it: map) {
                if (map.find(it - 1) == map.end()) {
                    int x = it;
                    int count = 1;
                    while(map.find(x + 1) != map.end()) {
                        count++;
                        x++;
                    }
                    longest = max(longest, count);
                }
            }
            return longest;
        }
    };
