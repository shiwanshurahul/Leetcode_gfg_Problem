class Solution {
public:
    bool canBeValid(string s, string locked) {
        // ( ) ) ( ( ) ( (  -> false
        // 1 0 0 0 1 1 1 1    
        //2 stk rkho
        //1 for strict "(" jo can't be chnaged -> locked=1 wale
        //2 for indexes jo can be chnaged (chahe '(' ya')' ho
        //if s[i] ==')' toh pop kro with 1 or 2
        //last me 2nd stack should cncel out 1st
        //if 1 is empty and 2nd wala v empty or even size toh true
        int n = s.length();
        if(n%2 !=0)   //odd length
            return false;

        stack<int> strict_open;  //idx store
        stack<int> changable;

        for(int i=0;i<n;i++){
            if(locked[i]=='0'){ // any b/w (  or ) 
                changable.push(i);  //reserved
            } //else me locked==1 hai
            else if(s[i]=='(' && locked[i]=='1'){
                strict_open.push(i);
                cout<<strict_open.size();
            }
            else if(s[i]==')' && locked[i]=='1'){ //'(' dhundh
                if(!strict_open.empty())
                    strict_open.pop();
                else if(!changable.empty() )
                    changable.pop();
                else  //not balanced
                    return false;    
            }
        }
        while(!strict_open.empty() && !changable.empty() && changable.top() > strict_open.top() ){ //bad me aya ')' = balance
            changable.pop();                
            strict_open.pop();
        }    
        
        return strict_open.empty() && changable.size()%2 == 0;
    }
};