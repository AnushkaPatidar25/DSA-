// class Solution {
// public:
//     vector<int> majorityElement(vector<int>& nums) {
//       int count=0;
//       int candidate=0;
//       vector<int> ans;
//       if(nums.size()==1){
//          ans.push_back(nums[0]); 
//          return ans;
//       } 
//       for(int i=0;i<nums.size();i++){
//         if(count==0){
//             candidate=nums[i];
//         }
//         if(candidate==nums[i])count++;
//         else{
//             count--;
//         }
//       }
//       if(count==0){
//         ans=nums;
//       }
//       else{
//         ans.push_back(candidate);
//       }
//       return ans;
//     }
// };
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
       unordered_map<int,int> temp;
       vector<int>ans;
       for(int i=0;i<nums.size();i++){
        temp[nums[i]]++;
       } 
       for(auto it: temp){
        if(it.second>nums.size()/3){
        ans.push_back(it.first);
        }
       }
       return ans;
    }
};