class Solution {
public:
    string removeKdigits(string num, int k) {
        // can't sort
       // 1432219 -> msb left side se hai
       //increasing order(<=) me digit ko rkho warna pop -> monotonic stack
        if(num.length() <= k)   
            return "0";
        
        // k is 0 , no need of removing /  preforming any operation
        if(k == 0)
            return num;
        
        string res = "";// result string
        stack <char> s; // char stack
        
        s.push(num[0]); // pushing first character into stack
        
        for(int i = 1; i<num.length(); ++i)
        {
            while(k > 0 && !s.empty() && num[i] < s.top())
            {
                // if k greater than 0 and our stack is not empty and the upcoming digit,
                // is less than the current top than we will pop the stack top
                --k;
                s.pop();
            }
            
            s.push(num[i]);
            
            // popping preceding zeroes
            if(s.size() == 1 && num[i] == '0')
                s.pop();
        }
        
        while(k && !s.empty())
        {
            // for cases like "456" where every num[i] > num.top()
            --k;
            s.pop();
        }
        
        while(!s.empty())
        {
            res.push_back(s.top()); // pushing stack top to string
            s.pop(); // pop the top element
        }
        
        reverse(res.begin(),res.end()); // reverse the string 
        
        if(res.length() == 0)
            return "0";
        
        return res;

    //     stack<char> st;  //string v rkh skte
    //     int n = num.length();
    //     if(n==k)
    //         return "0";
    //     if(k==0)
    //         return num;

    //     for(int i=0;i<n;i++){
    //         if(!st.empty() && k>0 && st.top() > num[i]){ //decreasing hai curr elem
    //             st.pop();k--;
    //         }   //agar k==0 hai toh can't pop
    //         // if(st.empty() && num[i] == '0')  //0200 -> don't push
    //         //     continue; 
    //         st.push(num[i]);
    //     }
    //         //remove remaining k digit
    //     while(k-- && !st.empty() ){    // 1 2 3 4 5 k=3 o/p -> 12
    //         st.pop();
    //     }
    
    //    string ans;
    //    while(!st.empty()){
    //     ans = st.top() + ans;  //if ans+= st.top() toh fir reverse kro
    //     st.pop();
    //    }
    // if(!ans.empty() && ans[0]=='0')
    //     ans.erase(0,1);
    // //    reverse(ans.begin(), ans.end());

    //    return ans.empty() ? "0" : ans;
    }
};