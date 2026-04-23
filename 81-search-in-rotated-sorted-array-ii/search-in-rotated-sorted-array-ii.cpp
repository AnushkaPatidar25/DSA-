// class Solution {
// public:
//     bool binarysearch(vector<int> & nums,int k){
//         int start=0;
//         int end=nums.size()-1;
//         int mid=start+(end-start)/2;
//         while(start<=end){
//             if(nums[start]==nums[mid]&& nums[mid]==nums[end]){
//                      start++;
//                      end--;
//             }
//             if(nums[mid]==k){
//             return true;
//             }
//             else if(nums[mid]<k){
//                 start=mid+1;
//             }
//             else{
//                 end=mid-1;
//             }
//             mid=start+(end-start)/2;
//         }
//         return false;
//     }
//     bool search(vector<int>& nums, int target) {
//       return binarysearch(nums,target);
//       }  
// };
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1;

        while(start <= end){
            int mid = start + (end - start) / 2;

            if(nums[mid] == target) return true;

            // ❗ handle duplicates
            if(nums[start] == nums[mid] && nums[mid] == nums[end]){
                start++;
                end--;
            }
            // left sorted
            else if(nums[start] <= nums[mid]){
                if(nums[start] <= target && target < nums[mid]){
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            }
            // right sorted
            else{
                if(nums[mid] < target && target <= nums[end]){
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
        return false;
    }
};