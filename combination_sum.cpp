class Solution {
    public:
        void f(vector<int>& candidates, int target, int index, vector<int>& ds, vector<vector<int>>& ans) {
            if (index == candidates.size()) {
                if (target == 0) {
                    ans.push_back(ds);
                }
                return;
            }
            if (candidates[index] <= target) {
                ds.push_back(candidates[index]);
                f(candidates, target - candidates[index], index, ds, ans);
                ds.pop_back();
            }
            f(candidates, target, index + 1, ds, ans);
        }
        
        vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            vector<vector<int>> ans;
            vector<int> ds;
            f(candidates, target, 0, ds, ans);
            return ans;
        }
    };
