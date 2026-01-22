class Solution {
public:
vector<int> solve(string expression){
    vector<int> ans;

    for(int i=0;i<expression.length();i++){
        if(expression[i]=='-' || expression[i]=='+' || expression[i]== '*'){
            vector<int> left_ans = solve(expression.substr(0,i)); //"2" -> leap of faith
            vector<int> right_ans = solve(expression.substr(i+1)); //"1-1"

            //after getting left and right 
            for(auto it: left_ans){
                for(auto it1: right_ans){
                    if(expression[i]=='*')
                        ans.push_back(it*it1);
                    else if(expression[i]=='+')
                        ans.push_back(it+it1);
                    else if(expression[i]=='-')
                        ans.push_back(it-it1);        
                }
            }
        }
    }    
    if(ans.empty())  //expression="12" -> no operator = no split
        ans.push_back(stoi(expression));             // = for loop me ni gya  

    return ans;    
}
    vector<int> diffWaysToCompute(string expression) {
        //har operator pe split and don;t split try kro -> pick and skip
        //2-1-1 -> 2 - (1-1) = 2 -> split at 1st idx
        //(2-1) -1 = 1-1 = 0  -> don't split at 1st, split at 3rd idx

        //recursio leap of fait -> wo ans le aayega left and right part ka and int me v convrt krlega  

        return solve(expression);
    }
};