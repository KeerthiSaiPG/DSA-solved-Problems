//memoization
class Solution {
public:
    int f(int ind1, int ind2, string& s1, string& s2,vector<vector<int>>& dp){
        if(ind1<0 || ind2<0) return 0;
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        if(s1[ind1]==s2[ind2]){
            return dp[ind1][ind2] = 1 + f(ind1-1,ind2-1,s1,s2,dp);
        }
        return dp[ind1][ind2] = max(f(ind1-1,ind2,s1,s2,dp),f(ind1,ind2-1,s1,s2,dp));
    }
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string s2 = s;
        reverse(s2.begin(),s2.end());
        vector<vector<int>> dp(n,vector<int> (n,-1));
        return f(n-1,n-1,s,s2,dp);
    }
};

//tabulation
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string s2 = s;
        reverse(s2.begin(),s2.end());
        vector<vector<int>> dp(n+1,vector<int> (n+1,0));
        for(int i=0;i<=n;i++) dp[i][0] = 0;
        for(int j=0;j<=n;j++) dp[0][j] = 0;
        for(int ind1=1;ind1<=n;ind1++){
            for(int ind2=1;ind2<=n;ind2++){
                if(s[ind1-1]==s2[ind2-1]){
                    dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];
                }
                else dp[ind1][ind2] = max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
            }
        }
        return dp[n][n];
    }
};
