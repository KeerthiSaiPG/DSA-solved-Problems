class Solution {
public:
    string decodeString(string s) {
        stack<pair<int,string>> st;
        int currNum = 0;
        string currString = "";
        for(char c:s){
            if(isdigit(c)){
                currNum = currNum*10 + (c-'0');
            }
            else if(c == '['){
                st.push({currNum,currString});
                currNum = 0;
                currString = "";
            }
            else if(c == ']'){
                auto p = st.top();st.pop();
                int num = p.first;
                string prevString = p.second;
                string temp = "";
                for(int i=0;i<num;i++){
                    temp += currString;
                }
                currString = prevString+temp;
            }
            else{
                currString += c;
            }
        }
        return currString;
    }
};
