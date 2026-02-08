// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//     int row=matrix.size();
//     int col=matrix[0].size();
//     int rowindex=0;
//     int colindex=col-1;
//     while(rowindex< row && colindex>=0 )   {
//         int element =matrix[rowindex][colindex];
//         if(element==target){
//             return 1;
//         }
//         if(element<target){
//             rowindex++;
//         }
//         else{
//             colindex--;
//         }
//     }
//     return 0; 
//     }
// };

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
          for(int i = 0;i < n ; i++){
            if(target < matrix[i][0] || target > matrix[i][m-1]) 
            continue;

            int l = 0 , r = m-1;
            while(l <= r){
                int mid = (l+r)/2;
                if(matrix[i][mid] == target){
                    return true;
                }
                else if(matrix[i][mid] > target) r = mid-1;
                else l = mid+1;
            }
          }
             return false;
    }
};