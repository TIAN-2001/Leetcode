// stack + hashmap
// O(N)
// 11:49 - 11:57
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        int sz1 = nums1.size();
        vector<int> res;
        int sz2 = nums2.size();
        stack<int> s;
        unordered_map<int, int> mp2;
        
        for(int i = sz2-1; i >= 0; --i){
            while(!s.empty() && s.top()<=nums2[i]){
                s.pop();
            }
            if(s.empty()){
                mp2[nums2[i]] = -1;
            } else {
                mp2[nums2[i]] = s.top();
            }
            s.push(nums2[i]);
        }
        
        for(int i = 0; i < sz1; ++i){
            res.push_back(mp2[nums1[i]]);
        }
        
        return res;
    }
};