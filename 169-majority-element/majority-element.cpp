// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//        unordered_map<int,int>temp;
//        for(int i=0;i<nums.size();i++){
//           temp[nums[i]]++;
//        }
//        for(auto i:temp){
//         if(i.second>nums.size()/2) {
//             return i.first;
//        }
//     }
//     return -1;
//     }
// };
class Solution {
public:
    int majorityElement(vector<int>& nums) {
      int candidate =0;
      int count=0;
      for(int i=0;i<nums.size();i++){
        if(count==0){
            candidate=nums[i];
        }
        if(candidate==nums[i])count++;
        else count--;
      }  
      return candidate;
    }
};