class Solution {
public:
    string nTimesString(string s, int n){
        string ans = "";
        for (int i = 0; i < n; i++) ans += s;
        return ans;
    }
    string decodeString(string s) {
        vector < string > stack;
        string curNum = "", curString = "";
        
        for(char c : s){
            if(c == '['){
                stack.push_back(curString);
                stack.push_back(curNum);
                curString = "", curNum = "";
            }
            else if(c == ']'){
                string curNum = stack.back(); 
                stack.pop_back();
                string prev = stack.back(); 
                stack.pop_back();
                curString = prev + nTimesString(curString, stoi(curNum));
            }
            else if(isdigit(c)) curNum += c;
            else curString += c;
        }
        return curString;
    }
};