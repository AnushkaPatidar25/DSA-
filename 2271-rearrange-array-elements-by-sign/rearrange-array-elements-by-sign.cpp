class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
     vector<int>arr1(nums.size()/2);
      vector<int>arr2(nums.size()/2);   
      int k1=0,k2=0,i=0;
      for(int j=0;j<nums.size();j++){
        if(nums[j]>=0) arr1[k1++]=nums[j];
        else{ arr2[k2++]=nums[j];}
      }
      vector<int> result(nums.size());
     for(int j=0;j<arr1.size();j++){
        result[i]=arr1[j];
         result[i+1]=arr2[j];
         i+=2;
      }
      return result;
    }
};