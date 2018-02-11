#include <cstring>
#include <climits>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        vector<int> vals;
        vals.push_back(root->val);
        popVals(root, vals);
        sort(vals.begin(), vals.end());
        int smallestInversion = INT_MAX;
        int last = vals.front();
        vals.erase(vals.begin());
        for(int i : vals){
            if(i - last < smallestInversion){
                smallestInversion = i - last;
            }
            last = i;
        }
        return smallestInversion;
    }

    void popVals(TreeNode* root, vector<int>& vals){
        if(root->left != NULL){
            vals.push_back(root->left->val);
            popVals(root->left, vals);
        }
        if(root->right != NULL){
            vals.push_back(root->right->val);
            popVals(root->right, vals);
        }
    }
};