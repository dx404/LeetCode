class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> a;
        int m = (int)matrix.size();
        if (m==0) return a;
        int n = (int) matrix[0].size();
        int top = 0, bottom = m - 1, left = 0, right = n - 1;
        while (top < bottom && left < right){
            for (int j = left; j <= right - 1; j++){
                a.push_back(matrix[top][j]);
            }
            for (int i = top; i <= bottom - 1; i++){
                a.push_back(matrix[i][right]);
            }
            for (int j = right; j >= left + 1; j--){
                a.push_back(matrix[bottom][j]);
            }
            for (int i = bottom; i >= top + 1; i--){
                a.push_back(matrix[i][left]);
            }
            top++;
            left++;
            right--;
            bottom--;
        }
        if (top < bottom && left == right){
            for (int i = top; i <= bottom; i++){
                a.push_back(matrix[i][right]);
            }
        }
        if (top == bottom && left < right){
            for (int j = left; j <= right; j++){
                a.push_back(matrix[top][j]);
            }
        }
        if (top == bottom && left == right){
            a.push_back(matrix[top][left]);
        }
        return a;
    }
};
