class Solution {
    vector<int>row(int row ){
        vector<int>v;
        int ans=1;
        v.push_back(1);
        for(int col=1;col<row;col++){
         ans=ans*(row-col);
         ans=ans/col;
         v.push_back(ans);
        }
     return v;
    }
public:
    vector<vector<int>> generate(int numRows) {
     vector<vector<int>>ans;
     for(int i=1;i<=numRows;i++){
       ans.push_back(row(i));
     }
    return ans;

    }
};