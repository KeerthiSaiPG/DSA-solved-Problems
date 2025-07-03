class Solution {
public:
    char kthCharacter(int k) {
        string s = "a";
        unordered_map<char,char> freq;
        for(char ch='a';ch<'z';ch++){
            freq[ch] = ch+1;
        }
        freq['z'] = 'a';
        while(s.size()<k){
            string temp = s;
            for(auto it:temp){
                s += freq[it];
                if(s.size()>=k) break;
            }
        }
        return s[k-1];
    }
};
