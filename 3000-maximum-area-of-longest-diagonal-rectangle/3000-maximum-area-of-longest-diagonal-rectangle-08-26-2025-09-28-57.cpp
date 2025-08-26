class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        //bada diagoonal wale ka area store
        int i =0;
        double diagonal_length = 0.0;
        double max_area = 0;

        while(i < dimensions.size() ){
            if(sqrt(dimensions[i][0]*dimensions[i][0] + dimensions[i][1]*dimensions[i][1]) >= diagonal_length){
                if(sqrt(dimensions[i][0]*dimensions[i][0] + dimensions[i][1]*dimensions[i][1]) == diagonal_length){
                    if(max_area < dimensions[i][0]*dimensions[i][1])  //same diagonal length me largest area store
                        max_area = dimensions[i][0] * dimensions[i][1];
                    }
                    else{
                        diagonal_length = sqrt(dimensions[i][0]* dimensions[i][0] + dimensions[i][1]* dimensions[i][1]); 
                        max_area = dimensions[i][0]* dimensions[i][1];
                    }    
                }
            i++;
        }
        return int(max_area);
    }
};