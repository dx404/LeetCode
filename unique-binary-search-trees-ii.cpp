class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
        return generateTrees(1, n);
    }

    vector<TreeNode *> generateTrees(int a, int b) {
        vector<TreeNode *> treeRepo;
        if (a > b) {
            treeRepo.push_back(nullptr);
            return treeRepo;
        }
        if (a == b){
            treeRepo.push_back(new TreeNode(a));
            return treeRepo;
        }
        for (int k = a; k <= b; k++){
            vector<TreeNode *> leftVec = generateTrees(a, k - 1);
            vector<TreeNode *> rightVec = generateTrees(k + 1, b);
            for (auto left : leftVec){
                for (auto right : rightVec){
                    TreeNode *root = new TreeNode(k);
                    root->left = left;
                    root->right = right;
                    treeRepo.push_back(root);
                }
            }
        }
        
        return treeRepo;
    } 
    
    int numTrees(int n) {
        if (n <= 1) return 1;
        int count = 0;
        for (int i = 0; i <= n-1; i++){
            count += numTrees(i) * numTrees(n-i-1);
        }
        return count;
    }
    
};