class Solution {
public:
    int maxArea(vector<int>& height) {
         int s=0,e=height.size()-1;
        int area =0,maxarea =0;
        while(s<e){
          area =min(height[s],height[e]) *abs(e-s); 
             maxarea =max(area,maxarea);
            if(min(height[s],height[e])==height[s])
                s++;
            else e--;
        }
        return maxarea;
    }
};