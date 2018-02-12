#include <cstdlib>
#include <climits>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        int i = INT_MAX;
        int j = INT_MAX;

        _helper(root, i, j);

        if(i != INT_MAX){
            return i;
        }
        return -1;
    }

    void _helper(TreeNode* root, int& i, int& j){
        if(root->left != NULL){
            if(root->left->val < i && root->left->val != j){
                if(root->left->val < j){
                    i = j;
                    j = root->left->val;
                }else{
                    i = root->left->val;
                }
            }
            _helper(root->left, i, j);
        }
        if(root->right != NULL){
            if(root->right->val < i && root->right->val != j){
                if(root->right->val < j){
                    i = j;
                    j = root->right->val;
                }else{
                    i = root->right->val;
                }
            }
            _helper(root->right, i, j);
        }
    }
};