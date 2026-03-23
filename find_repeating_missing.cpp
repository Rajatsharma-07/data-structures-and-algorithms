class Solution {
    public:
        vector<int> findRepeatingMissing(vector<int> &nums) {
            long long n = nums.size();
            long long s = 0;
            long long sn = (n * (n - 1)) / 2;
            for(int i = 0; i < n; i++) {
                s += nums[i];
            }

            long long s2 = 0;
            long long s2n = (n * (n + 1) * (2 * n + 1)) / 6;

            for(int i = 0; i < n; i++) {
                s2 += nums[i] * nums[i];
            }

            long long val1 = s - sn;
            long long val2 = s2 - s2n;

            val2 = val2/val1;

            long long repeating = (val1 + val2) / 2;
            long long missing = repeating - val1;

            return {int(repeating), int(missing)};
            
        }
}