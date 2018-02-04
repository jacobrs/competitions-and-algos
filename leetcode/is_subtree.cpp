#include <cstdlib>

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(t == NULL && s == NULL){
            return true;
        }
        if(s == NULL || t == NULL){
            return false;
        }

        if(s->val == t->val){
            if(t->val == NULL){
                return true;
            }
            return (isSubtree(s->left, t->left) && isSubtree(s->right, t->right)) || (isSubtree(s->left, t) || isSubtree(s->right, t));
        }else{
            return isSubtree(s->left, t) || isSubtree(s->right, t);
        }
    }
};