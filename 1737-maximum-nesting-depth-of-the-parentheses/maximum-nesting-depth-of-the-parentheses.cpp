#include<stack>
class Solution {
public:
    int maxDepth(string s) {
     stack<char> st;
    int count=0;;
     int max=0;
     for(char ch: s)  {
        if(ch=='('){
            st.push(ch);
            count++;
            if(count>max) max=count;
        }
        else if(ch==')'){
            count--;
           if(!st.empty()){
            st.pop();
           }
        }
        }
       return max;
     } 
};