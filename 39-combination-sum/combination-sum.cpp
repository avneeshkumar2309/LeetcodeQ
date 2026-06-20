class Solution {
public:
    vector<vector<int>> ans;

    void solve(int idx,vector<int>& candidates, int tar, vector<int>&temp){
        if(tar==0){
            ans.push_back(temp);
            return;
        }

        if(idx >=candidates.size() || tar<0) return;

        //take element
        temp.push_back(candidates[idx]);
        solve(idx,candidates,tar-candidates[idx],temp);
        temp.pop_back();

        //not pick
        solve(idx+1,candidates,tar,temp);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        solve(0,candidates,target,temp);
        return ans;       
    }
};