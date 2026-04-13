class Solution {
public:
    string reverseWords(string s) {

            //m2:
            s+=' ';
            string ans;
            string temp;
            for(int i=0;i<s.length();i++){
                if(s[i] !=' '){   //not the end of word
                    temp += s[i];   //the; sky; is; blue
                }
                else{  //s[i] =' '
                    reverse(temp.begin(), temp.end());//eht; yks; si; eulb
                    ans+=temp;
                    ans+=' ';  // eht yks si eulb
                    temp.clear();
                }
            }
            


//         string x,ans;
//         int a=0;
//         reverse(s.begin(),s.end());//"eulb si yks eht"
//        for(int i=0;i<s.length();i++){
//            if(s[i]==' '){
//                 x =s.substr(a,i-a);
//                reverse(x.begin(),x.end());
//                ans+=x;ans+=' ';
//                a=i+1;
//                x.clear();
//            }
//       }
//       x =s.substr(a);
//         reverse(x.begin(),x.end());//last word
//       ans+=x;


 reverse(ans.begin(), ans.end());  // blue is sky the
//trailing spaces :
for(int i=0;i<ans.length();i++){
    if(ans[i]==' ' && ans[i+1]==' '){ 
    ans.erase(i,1);
    i-=1;
    }
}
 if(ans[0]==' ')
 ans.erase(0,1);//start index

if(ans[ans.length()-1] ==' ')
ans.pop_back();

      return ans;

    }
};