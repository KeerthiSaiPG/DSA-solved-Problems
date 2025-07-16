class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int oddCount = 0;
        int evenCount = 0;
        for(auto it:nums){
            if(it%2==0){
                evenCount++;
            }
            else oddCount++;
        }
        int parity = nums[0]%2;
        int alternating = 1;
        for(int i=1;i<nums.size();i++){
            int currParity = nums[i]%2;
            if(currParity != parity){
                alternating++;
                parity = currParity;
            }
        }
        return max({evenCount, oddCount, alternating});
    }
};
