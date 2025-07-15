class Solution {
public:
    bool isValid(string word) {
        if(word.size()<3) return false;
        bool hasConsonent = false;
        bool hasVowel = false;
        for(auto ch:word){
            if(isalpha(ch)){
                ch = tolower(ch);
                if(ch=='a' || ch=='e' ||ch=='i'||ch=='o' || ch=='u'){
                    hasVowel = true;
                }
                else hasConsonent = true;
            }
            else if(!isdigit(ch)) return false;
        }
        return hasVowel && hasConsonent;
    }
};
