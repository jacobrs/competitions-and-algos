#include <string>
#include <vector>

using namespace std;

class Node {
public:
    char data;
    bool leaf;
    vector<Node*> children;
    Node(char val){
        data = val;
        leaf = false;
    }
};

class Solution {
public:
    string longestWord(vector<string>& words) {
        Node * root = new Node('_');
        root->leaf = true;
        for(auto word : words) {
            vector<Node *>* eval = &(root->children);
            // foreach letter in word
            for(int j = 0; j < word.length(); j++){
                // find or insert
                bool found = false;
                for(auto it: *eval){
                    if(it->data == word[j]){
                        eval = &it->children;
                        found = true;
                        if(j == word.length()-1){
                            it->leaf = true;
                        }
                    }
                }
                if(!found){
                    auto n = new Node(word[j]);
                    eval->push_back(n);
                    if(j == word.length()-1){
                        n->leaf = true;
                    }
                    eval = &n->children;
                }
            }
        }

        return dfs(root, "");
    }

    string dfs(Node* root, string path){
        if(root->children.empty()){
            return path;
        }
        string res = path;
        for(auto n : root->children){
            if(n->leaf) {
                string comp = dfs(n, path + n->data);
                if (comp.length() > res.length()) {
                    res = comp;
                } else if (res.length() == comp.length()) {
                    if (res.compare(comp) > 0) {
                        res = comp;
                    }
                }
            }
        }
        return res;
    }
};
