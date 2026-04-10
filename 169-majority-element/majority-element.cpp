class Solution {
public:
    int majorityElement(vector<int>& nums) {
       unordered_map<int,int>temp;
       for(int i=0;i<nums.size();i++){
          temp[nums[i]]++;
       }
       for(auto i:temp){
        if(i.second>nums.size()/2) {
            return i.first;
       }
    }
    return -1;
    }
};