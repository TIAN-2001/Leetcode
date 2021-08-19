class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // build graph
        int sz = tickets.size();
        for(int i = 0; i < sz; ++i){
            string from = tickets[i][0];
            string to = tickets[i][1];
            mp[from].push_back(to);
        }
        
        for(auto it = mp.begin(); it != mp.end(); ++it){
            sort(it->second.begin(),it->second.end());
        }
        
        
        // Backtracking
        // dfs. starting from JFK.        
        string start = "JFK";
        path.push_back(start);
        
        dfs(start, sz+1);
        
        return path;
        
    }
    
private:    
    vector<string> path;
    
    // struct compare{
    //     bool operator()(const string a, const string b){
    //         return a[0] > b[0];
    //     }
    // };
    
    // heap will not work but we could sort
    // unordered_map<string, priority_queue<string, vector<string>, compare>> mp;
    unordered_map<string, vector<string>> mp;
    
    bool flagSuccess = 0;
    
    void dfs(string from, int sizeTickets){
        // base case, where you should stop
        if(path.size() == sizeTickets) {
            flagSuccess = 1;
            return;
        }
        
        // Backtracking = top down dfs
        int sz = mp[from].size();
        // sort(mp[from].begin(), mp[from].end());
        
        // for pruning
        unordered_set<string> s;
        
        // top down
        for(int i = 0; i < sz; ++i){
            string next = mp[from][i];
            
            // pruning
            if(s.find(next) != s.end()){
                continue;
            }
            s.insert(next);            
            
            // pre order - do something
            mp[from].erase(mp[from].begin()+i);
            path.push_back(next);
            
            // top down - recurse to neighbors
            dfs(next, sizeTickets);
            // find your answer -> return
            if(flagSuccess == 1){
                return;
            }
            
            // restore for backtracking
            mp[from].insert(mp[from].begin()+i, next);
            path.erase(path.end());
        }
        
        return;
    }
};