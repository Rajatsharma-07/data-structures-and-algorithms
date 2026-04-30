class Solution {
    public:
        void f(vector<int>& arr, int target, int index, vector<int>& ds, vector<vector<int>>& ans) {
            if (target == 0) {
                ans.push_back(ds);
                return;
            }
    
            for(int i = index; i < arr.size(); i++) {
                if (i != index && arr[i] == arr[i - 1]) continue;
                if (target >= arr[i]) {
                    ds.push_back(arr[i]);
                    f(arr, target - arr[i], i + 1, ds, ans);
                    ds.pop_back();
                } else {
                    break;
                }
            }
        }
    
        vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
            vector<vector<int>> ans;
            vector<int> ds;
            sort(candidates.begin(), candidates.end());
            f(candidates, target, 0, ds, ans);
            return ans;
        }
    };
