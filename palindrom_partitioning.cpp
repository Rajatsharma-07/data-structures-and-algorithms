class Solution {
    public:
        bool check(string s, int left, int right) {
            while (left < right) {
                if (s[left] != s[right]) {
                    return false;
                }
                left++;
                right--;
            }
            return true;
        }
    
        void f(string s, int index, vector<string>& ds, vector<vector<string>>& ans) {
            if (index == s.size()) {
                ans.push_back(ds);
                return;
            }
    
            for (int i = index; i < s.size(); i++) {
                if (check(s, index, i)) {
                    string substring = s.substr(index, i - index + 1);
                    ds.push_back(substring);
                    f(s, i + 1, ds, ans);
                    ds.pop_back();
                }
            }
        }
    
        vector<vector<string> > partition(string s) {
            //your code goes here
            vector<vector<string>> ans;
            vector<string> ds;
            f(s, 0, ds, ans);
            return ans;
        }
    };
