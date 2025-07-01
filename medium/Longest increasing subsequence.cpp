//memoization
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

//tabulation
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int> (n+1,0));
        for(int ind=n-1;ind>=0;ind--){
            for(int prevInd=ind-1;prevInd>=-1;prevInd--){
                //not take 
                int len = 0 + dp[ind+1][prevInd+1];
                //take 
                if(prevInd==-1 || nums[ind]>nums[prevInd]){
                    len = max(len,1 + dp[ind+1][ind+1]);
                }
                dp[ind][prevInd+1] = len;
            }
        }
        return dp[0][0];
    }
};
//alternative solution (useful for printing lis)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        int maxi = 1;
        for(int ind=0;ind<n;ind++){
            for(int prev=0;prev<=ind-1;prev++){
                if(nums[ind]>nums[prev]){
                    dp[ind] = max(1+dp[prev], dp[ind]);
                }
            }
            maxi = max(maxi,dp[ind]);
        }
        return maxi;
    }
};
