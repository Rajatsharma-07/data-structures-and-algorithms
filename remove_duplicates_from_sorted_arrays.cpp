class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            int n = nums.size();
            if (n == 1) {
                return 1;
            }
            int left = 0;
            int right = 1;
            while (right < n) {
                if (nums[left] == nums[right]) {
                    right ++;
                } else {
                    swap(nums[left + 1], nums[right]);
                    left ++;
                    right ++;
                }
            }
            return left + 1;
        }
    };
