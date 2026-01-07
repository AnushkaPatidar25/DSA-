class Solution {
public:
// int binarysearch(int n){
//      int s=0;
//         int e=n;
//         int ans=-1;
//        long long int mid=s+(e-s)/2;
//        while(s<=e){
//         long long int square =mid*mid; 
//         if(square==n){
//             return mid;
//         }
//         if(square<n){
//             ans=mid;
//             s=mid+1;
//         }
//         else{
//             e=mid-1;
//         }
//            mid=s+(e-s)/2;
//        }
//        return ans;
// }
    int mySqrt(int x) {
    //   return binarysearch(x); 
     int s=0;
        int e=x;
        int ans=-1;
       long long int mid=s+(e-s)/2;
       while(s<=e){
        long long int square =mid*mid; 
        if(square==x){
            return mid;
        }
        if(square<x){
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
           mid=s+(e-s)/2;
       }
       return ans;
} 
};