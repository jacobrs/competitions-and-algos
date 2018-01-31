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
        vector<Node *> root;
        for(auto word : words) {
            vector<Node *> eval = root;
            // foreach letter in word
            for(int j = 0; j < word.length(); j++){
                // find or insert
                bool found = false;
                for(auto it: eval){
                    if(it->data == word[j]){
                        eval = it->children;
                        found = true;
                        if(j == word.length()-1){
                            it->leaf = true;
                        }
                    }
                }
                if(!found){
                    auto n = new Node(word[j]);
                    eval.push_back(n);
                    if(j == word.length()-1){
                        n->leaf = true;
                    }
                }
            }
        }
        // use dfs (iteratively) to find the longest string with all leaf bools

    }
};
