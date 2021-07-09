// stack: copy and paste the orginal array to the right and concatenate, so that
// circle is broken.
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        if(nums.size() == 1) // corner case
            return {-1};

        int sz = nums.size();
        vector<int> res(sz, -1);
        vector<int> nums2;     
        stack<int> s;
        for(int i = 0; i < 2*sz; ++i){
            nums2.push_back(nums[i % sz]);
        }
        
        for(int i = 2*sz-1; i >= 0; --i){
            while(!s.empty() && s.top()<=nums2[i]){
                s.pop();
            } 
            if(i < sz){
                if(s.empty()) {
                    res[i] = -1;
                } else {
                    res[i] = s.top();
                }            
            }
            s.push(nums2[i]);
        }
        
        return res;
    }
};