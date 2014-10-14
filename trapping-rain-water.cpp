class Solution {
public:
    int trap(int A[], int n) {
    	vector<int> leftmost(n, 0), rightmost(n, 0);
    	int x = 0;
    	//left exclusive scan
        for (int i = 0; i < n; i++){
        	leftmost[i] = x;
        	if (A[i] > x){
        		x = A[i];
        	}
        }

        x = 0;
        //right exclusive scan
        for (int i = n - 1; i >= 0; i--){
        	rightmost[i] = x;
        	if (A[i] > x){
        		x = A[i];
        	}
        }

        int vol = 0;
        for (int i = 0; i < n; i++){
        	vol += max(0, min(leftmost[i], rightmost[i]) - A[i]);
        }
        return vol;
    }

};