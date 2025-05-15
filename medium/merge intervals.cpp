class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> result;
        if(n==0) return result;
        sort(intervals.begin(),intervals.end());
        vector<int> mergeInterval = intervals[0];
        for(auto it:intervals){
            if(it[0]<=mergeInterval[1]){
                mergeInterval[1] = max(mergeInterval[1],it[1]);
            }
            else{
                result.push_back(mergeInterval);
                mergeInterval = it;
            }
        }
        result.push_back(mergeInterval);
        return result;
    }
};
