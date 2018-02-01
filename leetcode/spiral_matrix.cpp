#include <vector>

using namespace std;

enum Direction {
    RIGHT,
    LEFT,
    TOP,
    BOTTOM
};

class Node {
public:
    bool visited;
    int data;
    Node(int val){
        data = val;
        visited = false;
    }
};

Direction next(Direction d){
    Direction dirs[4] = {RIGHT, BOTTOM, LEFT, TOP};

    for(int i = 0; i < 4; i++){
        if(dirs[i] == d){
            return dirs[(i+1)%4];
        }
    }
}

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> found;

        if(matrix.empty()){
            return found;
        }
        int cols = matrix[0].size();
        int rows = matrix.size();

        int nm = cols * rows;
        Node *array[rows][cols];

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                array[i][j] = new Node(matrix[i][j]);
            }
        }

        Direction dir = RIGHT;

        int count = 0;
        int row = 0;
        int col = 0;

        count ++;
        found.push_back(array[row][col]->data);
        array[row][col]->visited = true;

        while(count < nm){
            if(dir == RIGHT){
                while(col + 1 < cols && !array[row][col + 1]->visited){
                    count ++;
                    col ++;
                    found.push_back(array[row][col]->data);
                    array[row][col]->visited = true;
                }
            }else if(dir == LEFT){
                while(col - 1 >= 0 && !array[row][col - 1]->visited){
                    count ++;
                    col --;
                    array[row][col]->visited = true;
                    found.push_back(array[row][col]->data);
                }
            }else if(dir == BOTTOM){
                while(row + 1 < rows && !array[row + 1][col]->visited){
                    count ++;
                    row ++;
                    array[row][col]->visited = true;
                    found.push_back(array[row][col]->data);
                }
            }else if(dir == TOP){
                while(row - 1 >= 0 && !array[row - 1][col]->visited){
                    count ++;
                    row --;
                    array[row][col]->visited = true;
                    found.push_back(array[row][col]->data);
                }
            }
            dir = next(dir);
        }
        return found;

    }
};