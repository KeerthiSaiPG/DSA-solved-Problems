class Solution {
public:
    bool f(int ind, string& s, vector<string>& wordDict, unordered_set<string>& st, vector<int>& dp){
        if(ind==s.size()) return true;
        if(st.find(s) != st.end()) return true;
        if(dp[ind] != -1) return dp[ind];
        for(int l=1;l<=s.size();l++){
            if(st.find(s.substr(ind,l)) != st.end() && f(ind+l,s,wordDict,st,dp)) return dp[ind] = true;
        } 
        return dp[ind] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(),wordDict.end());
        vector<int> dp(s.size()+1,-1);
        return f(0,s,wordDict,st,dp);
    }
};
