class Solution {
public:
    string removeOuterParentheses(string s) {
        string str="";
        int level=0;
        for(char ch: s){
          if(ch=='('){
           if(level>0) str+=ch;
           level++;
          }
           else if (ch==')'){
            level--;
            if(level>0) str+=ch;
           }
        }
      return str;
    }
};