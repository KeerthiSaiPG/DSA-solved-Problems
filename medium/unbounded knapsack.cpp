// User function Template for C++

class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = val.size();
        vector<vector<int>> dp(n, vector<int> (capacity+1,0));
        for(int i=0;i<=capacity;i++){
            dp[0][i] = (i/wt[0])*val[0];
        }
        for(int ind=1;ind<n;ind++){
            for(int W=0;W<=capacity;W++){
                int notpick = dp[ind-1][W];
                int pick = -1e8;
                if(wt[ind]<=W) pick = val[ind] + dp[ind][W-wt[ind]];
                dp[ind][W] = max(pick,notpick);
            }
        }
        return dp[n-1][capacity];
    }
};
