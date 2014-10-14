#define MAX3(x, y, z) max(max((x),(y)), (z))
class Solution {
public:
    // what about zero element path ? 
    unordered_map<TreeNode *, int> maxEndHere, maxSoFar;
    int maxPathSum(TreeNode *root) {
        if (root == nullptr)
            return maxSoFar[root] = numeric_limits<int>::min();
    	maxPathSum(root->left);
    	maxPathSum(root->right);
    	maxEndHere[root] = MAX3(root->val, 
    	                        root->val + maxEndHere[root->left], 
    	                        root->val + maxEndHere[root->right]);
    	maxSoFar[root] = MAX3(maxSoFar[root->left], 
    	                      maxSoFar[root->right], 
    	                      root->val +
    	                      max(0, maxEndHere[root->left]) + 
    	                      max(0, maxEndHere[root->right]));
    	maxEndHere.erase(root->left);
    	maxEndHere.erase(root->right);
    	maxSoFar.erase(root->left);
    	maxSoFar.erase(root->right);
    	maxSoFar[NULL] = numeric_limits<int>::min();
    	return maxSoFar[root];
    }
};