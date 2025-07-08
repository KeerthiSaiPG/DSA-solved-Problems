class Solution {
public:
    int bs(int ind, vector<vector<int>>& events){
        int l = ind+1, h = events.size()-1;
        int ans = events.size();
        while(l<=h){
            int m = l +(h-l)/2;
            if(events[m][0]>events[ind][1]){
                ans = m;
                h = m-1;
            }
            else l = m+1;
        }
        return ans;
    }
    int f(int ind, int k, vector<vector<int>>& events,vector<vector<int>>& dp){
        if(ind==events.size() ||k==0) return 0;
        if(dp[ind][k] != -1) return dp[ind][k];
        int nottake = 0 + f(ind+1,k,events,dp);
        int nextInd = bs(ind,events);
        int take = events[ind][2] + f(nextInd,k-1,events,dp);
        return dp[ind][k] = max(nottake,take);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        sort(events.begin(),events.end());
        vector<vector<int>> dp(n,vector<int> (k+1,-1));
        return f(0,k,events,dp);
    }
};
