class Solution {
public:
    int f(int ind, int prevInd,int n, vector<int>& nums, vector<vector<int>>& dp){
        if(ind==nums.size()) return 0;
        if(dp[ind][prevInd+1] != -1) return dp[ind][prevInd+1];
        //nottake
        int len = 0 + f(ind+1,prevInd,n,nums,dp);
        //take
        if(prevInd==-1 || nums[ind]>nums[prevInd]){
            len = max(len, 1+f(ind+1,ind,n,nums,dp));
        }
        return dp[ind][prevInd+1] = len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        //co-ordinal change as we cannot store -1 (prevInd starts with -1)
        vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
        return f(0,-1,n,nums,dp);
    }
};
