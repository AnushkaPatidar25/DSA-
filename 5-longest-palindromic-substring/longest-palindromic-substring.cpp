class Solution {
public:
bool palindrome(string &s , int st,int e){
    while(st<e){
      if(s[st]!=s[e]) return false;
      st++;
      e--; 
    }
   return true;
}
    string longestPalindrome(string s) {
     string ans="";
     int maxlen=0;
     for(int i=0;i<s.length();i++){
       for(int j=i;j<s.length();j++){
        if(palindrome(s,i,j)){
           if(j-i+1>maxlen){
            maxlen=j-i+1;
           ans=s.substr(i,maxlen);
           }
        }
       }
     }
     return ans;  
    }
};