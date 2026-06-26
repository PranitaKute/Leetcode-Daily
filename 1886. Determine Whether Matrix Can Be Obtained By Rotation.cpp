class Solution {
public:
    void rotation(vector<vector<int>>& mat){
        int rows = mat.size();
        int cols = mat[0].size();
        // int flag = 0;

        // transpose the matrix
        for(int i = 0; i < rows - 1; i++){
            for(int j = i + 1; j < cols; j++){
                swap(mat[i][j], mat[j][i]);
            }
        }
        // reverse the matrix
        for(int i = 0; i < rows; i++){
            reverse(mat[i].begin(),mat[i].end());
        }
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        // compare 2 matrix
        int rotations = 4;
        while(rotations--){
            rotation(mat);
            if(mat == target){
                return true;
            }
            // else{
            //     return false;
            // }
        }
        return false;
    }
    
};
