class Solution {
    public:
        void nextPermutation(vector<int>& nums) {
            int findIndex = -1;
            int size = nums.size();
            for (int i = size - 2; i >= 0; i--){
                if(nums[i] < nums[i + 1]){
                    findIndex = i;
                    break;
                }
            }
    
            if(findIndex == -1){
                reverse(nums.begin(), nums.end());
            } else {
                for (int i = size - 1; i >= findIndex; i--){
                    if(nums[i] > nums[findIndex]){
                        swap(nums[i], nums[findIndex]);
                        break;
                    }
                }
                reverse(nums.begin() + findIndex + 1, nums.end());
            }
        }
    };