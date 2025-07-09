class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int> freeTime;
        freeTime.push_back(startTime[0]);
        for(int i=1;i<startTime.size();i++){
            freeTime.push_back(startTime[i]-endTime[i-1]);
        }
        freeTime.push_back(eventTime-endTime[endTime.size()-1]);
        //sliding window
        int i = 0;
        int j = 0;
        int currSum = 0;
        int maxAns = 0;
        while(j<freeTime.size()){
            currSum += freeTime[j];
            if(i<freeTime.size() && j-i+1 >k+1){
                currSum -= freeTime[i];
                i++;
            }
            maxAns = max(maxAns,currSum);
            j++;
        }
        return maxAns;
    }
};
