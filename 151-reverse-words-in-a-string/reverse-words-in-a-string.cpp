class Solution {
public:

void reverse(string &s,int st,int e){

    while(st<e){
        swap(s[st++],s[e--]);
    }
}
    string reverseWords(string s) {
        string temp;
        stringstream ss(s);
        string word;
        while(ss>>word){
            if(!temp.empty()) temp+=" ";
            temp+=word;
        }
        s=temp;
      reverse(s,0,s.length()-1);
      int start=0;
      for(int i=0;i<s.length();i++){
        if(s[i]==' '){
            reverse(s,start,i-1);
            start=i+1;
        }
      }
      reverse(s,start,s.length()-1);
      return s;
    }
};