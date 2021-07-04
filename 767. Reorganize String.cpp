class Solution {
public:
    string reorganizeString(string s) {
        if (s == "")
            return "";
        
        // construct hash map
        unordered_map<char, int> mp;
        int maxNum = INT_MIN;
        char maxNumChar;
        for (char c : s){
            mp[c] += 1;
        }
        
        // find the most frequent char
        for(auto it = mp.begin(); it != mp.end(); ++it){
            if(it -> second > maxNum){
                maxNumChar = it -> first;
                maxNum = it -> second;
            }
        }

        // math proof        
        int sz = s.length();
        if(sz % 2 == 0){
            if(maxNum > sz/2){
                return "";
            }
        } else {
            if(maxNum > sz/2 + 1){
                return "";
            }
        }
        
        // construct rearrangement
        string res;
        priority_queue<pair<int, char>> hp;
        for(auto it = mp.begin(); it != mp.end(); ++it){
            hp.push({it->second, it->first});
        }
        int prevFreq = 0;
        char prevChar;
        pair<int, char> topChar;

        while(!hp.empty()){
            topChar = hp.top();
            hp.pop();
            res.push_back(topChar.second);
            topChar.first -= 1;
            if (prevFreq > 0){
                hp.push({prevFreq, prevChar});
            }
            prevFreq = topChar.first;
            prevChar = topChar.second;
        }
        
        return res;
    }
};