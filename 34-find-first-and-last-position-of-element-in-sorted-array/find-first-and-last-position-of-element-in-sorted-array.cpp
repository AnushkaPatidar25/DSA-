class Solution {
public:
    int firstsearch(vector<int>& nums, int target) {
     int i=0;
      int j=nums.size()-1;
       int mid=i+(j-i)/2;
     int ans=-1;
     while(i<=j){
        if (nums[mid]== target)
        {
            ans=mid;
            j=mid-1;
        }
        else if(nums[mid]<target){
            i=mid+1;
        }
        else{
            j=mid-1;
        }
        mid=i+(j-i)/2;
        
    }
    return ans;
    }
     int secondsearch(vector<int>& nums, int target) {
    int i=0;
    int j=nums.size()-1;
    int mid=i+(j-i)/2;
    int ans=-1;
    while(i<=j){
        if (nums[mid]== target)
        {
            ans=mid;
            i=mid+1;
        }
        else if(nums[mid]<target){
            i=mid+1;
        }
        else{
            j=mid-1;
        }
        mid=i+(j-i)/2;
        
    }
    return ans;
}
vector<int> searchRange(vector<int>&nums,int target){
    int first=firstsearch(nums,target);
      int second=secondsearch(nums,target);
      return {first,second};
}

};