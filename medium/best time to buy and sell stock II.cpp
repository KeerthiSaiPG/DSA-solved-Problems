//memoization
class Solution {
public:
    int f(int ind, int buy, vector<int>& prices, vector<vector<int>>& dp){
        if(ind==prices.size()) return 0;
        if(dp[ind][buy] != -1) return dp[ind][buy];
        int profit = 0;
        if(buy){
            profit = max(-prices[ind]+f(ind+1,0,prices,dp),//take
                          0 + f(ind+1,1,prices,dp));//not take
        }
        else{
            profit = max(prices[ind] + f(ind+1,1,prices,dp), //take
                         0 + f(ind+1,0,prices,dp));//not take
        }
        return dp[ind][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int> (2,-1));
        return f(0,1,prices,dp);
    }
};
//tabulation
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int> (2,0));
        dp[n][0] = 0;
        dp[n][1] = 0;
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=1;buy>=0;buy--){
                int profit = 0;
                if(buy){
                    profit = max(-prices[ind]+dp[ind+1][0],//take
                                0 + dp[ind+1][1]);//not take
                }
                else{
                    profit = max(prices[ind] + dp[ind+1][1], //take
                                0 + dp[ind+1][0]);//not take
                }
                dp[ind][buy] = profit;
            }
        }
        return dp[0][1];
    }
};
