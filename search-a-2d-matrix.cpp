class Solution {
public:
	int m, n;
    bool binSearch(vector<vector<int> > &p, int a, int b, int target){

        if (a > b){
            return false;
        }
        if (a == b){
            return p[a/n][a%n] == target;
        }
        int mid = (a+b)/2;

        if (target <= p[mid/n][mid%n]){
            return binSearch(p, a, mid, target);
        }
        else{
            return binSearch(p, mid+1, b, target);
        }
    }
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        m = matrix.size();
        n = matrix[0].size();
        return binSearch(matrix, 0, m*n-1, target);
    }
};