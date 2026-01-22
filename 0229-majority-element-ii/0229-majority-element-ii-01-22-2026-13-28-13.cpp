class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        //o(1) -> moore voting algo
        //moore voting algo
        //jo n/2 se jyada aa rha wo sbko cancel kr dega

        //>n/3 me max 2 majority elem hoenge = 2 var lo
        
        int n = nums.size();
        int majority_elem1 = 0;
        int majority_elem2 = 0;
        int cnt_1 = 0;  //elem1 wale ka ka cnt
        int cnt_2 = 0;
        //isme cnt_1==0 ya cnt_2==0 ka check pehle ni laga skte bad me lagao after nums[i]==majority_elem1 
        int i=0;
        while(i<n){
            if(nums[i]==majority_elem1){
                cnt_1++;
            }
            else if(nums[i]==majority_elem2){
                cnt_2++;
            }
            else if(cnt_1 == 0){
                majority_elem1 = nums[i]; //jo v elem hai
                cnt_1 = 1;
            } 
            else if(cnt_2 == 0){
                majority_elem2 = nums[i]; //jo v elem hai
                cnt_2 = 1;
            }
            else if(nums[i] !=majority_elem1 && nums[i] !=majority_elem2){
                cnt_1--;    //dono ka cnt --
                cnt_2--;
            }    
            i++;  
        }

        //check kro ki sahi hai
        vector<int> ans;
        int freq_1 = 0;
        int freq_2 = 0;
        for(auto it: nums){
            cout<<it;
            if(it == majority_elem1)
                freq_1++;
            else if(it == majority_elem2)
                freq_2++;    
        }
        if(freq_1> floor(n/3) )
            ans.push_back(majority_elem1);
        if(freq_2> floor(n/3) )
            ans.push_back(majority_elem2); 
        return ans;

    }
};