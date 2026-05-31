class Solution {
public:
    string largestOddNumber(string num) {
      string temp="";
      string max;
      for(char ch: num){
        temp+=ch;
        if((ch-'0')%2 ==1){
            max=temp;
        }
      }
     return max;
    }
};