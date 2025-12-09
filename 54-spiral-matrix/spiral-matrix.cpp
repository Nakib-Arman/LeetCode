class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size()*matrix[0].size();
        vector<int> result;
        int init_row = 0;
        int final_row=matrix.size();
        int init_col=0;
        int final_col=matrix[0].size();
        string direction = "right";
        int i=init_row;
        int j=init_col;
        while(result.size() < n){
            if(direction == "right"){
                while(final_col>i){
                    // cout<<matrix[matrix.size()-rows][i]<<" "<<i<<endl;
                    result.push_back(matrix[init_row][i]);
                    i++;
                }
                init_row++;
                i=init_row;
                direction = "down";
            }
            else if(direction == "down"){
                while(final_row>i){
                    // cout<<matrix[matrix.size()-rows][i]<<" "<<i<<endl;
                    result.push_back(matrix[i][final_col-1]);
                    i++;
                }
                final_col--;
                i=final_col;
                direction = "left";
            }
            else if(direction == "left"){
                while(init_col<i){
                    // cout<<matrix[matrix.size()-rows][i]<<" "<<i<<endl;
                    result.push_back(matrix[final_row-1][i-1]);
                    i--;
                }
                final_row--;
                i=final_row;
                direction = "up";
            }
            if(direction == "up"){
                while(init_row<i){
                    // cout<<matrix[matrix.size()-rows][i]<<" "<<i<<endl;
                    result.push_back(matrix[i-1][init_col]);
                    i--;
                }
                init_col++;
                i = init_col;
                direction = "right";
            }
        }
        return result;
    }
};