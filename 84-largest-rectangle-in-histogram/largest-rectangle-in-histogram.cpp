class Solution {
public:
void nextSmaller(vector<int>&heights,vector<int>&next,int n){
    stack<int>s;
    s.push(-1);
     for(int i=n-1;i>=0;i--){
        int curr=heights[i];
      while(s.top()!=-1 && heights[s.top()]>=curr) s.pop();  
       next[i]=s.top();
       s.push(i);
    }
  }
 void prevSmaller(vector<int>&heights,vector<int>&prev,int n){
    stack<int>s;
    s.push(-1);
    for(int i=0;i<n;i++){
        int curr=heights[i];
        while(s.top()!=-1 && heights[s.top()]>=curr) s.pop();
        prev[i]=s.top();
        s.push(i);
    }
 }
    int largestRectangleArea(vector<int>& heights) {
     int n=heights.size();
      vector<int>next(n);
      nextSmaller(heights,next,n);
      vector<int>prev(n);
      prevSmaller(heights,prev,n);
      int ans=INT_MIN;
      for(int i=0;i<n;i++){
        int l=heights[i];
        if(next[i]==-1) next[i]=n;
        int b=next[i]-prev[i]-1;
        int res=l*b;
        ans=max(ans,res);
      }  
      return ans;
    }
};