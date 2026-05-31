class Solution {
public:
    bool rotateString(string s, string goal) {
        int shift=0;
     while(s!=goal && shift<=s.length() ){
        char first=s[0];
        for(int i=1;i<s.length();i++){
            s[i-1]=s[i];
   
        }
        s[s.length()-1]=first;
        shift++;
     }  
     if(s==goal) return true;
     else return false;
    }
};