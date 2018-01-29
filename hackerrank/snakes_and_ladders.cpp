#include <vector>
#include <iostream>

using namespace std;

int getResult(vector < vector<int> > v1, vector <vector<int> > v2, int val) {
    for (auto &it : v1) {
        if(it.at(0) == val){
            return it.at(1);
        }
    }
    for (auto &it : v2) {
        if(it.at(0) == val){
            return it.at(1);
        }
    }
    return -1;
}

int _helper(vector < vector<int> > ladders, vector < vector<int> > snakes, int curr, int moves, int *cache, bool *visited){
    if(curr >= 100){
        return moves;
    }
    int teleport = getResult(ladders, snakes, curr);
    if(teleport != -1){
        return _helper(ladders, snakes, teleport, moves, cache, visited);
    }
    else{
        if(cache[curr] == 0) {
            if(visited[curr]){
                return 100000000;
            }
            int m = INT_MAX;
            visited[curr] = true;
            for (int i = 1; i <= 6; i++) {
                // return max of all 6
                int res = _helper(ladders, snakes, curr + i, moves + 1, cache, visited);
                if (res < m) {
                    m = res;
                }
            }
            cache[curr] = m - moves;
            visited[curr] = false;
            return m;
        }else{
            return cache[curr] + moves;
        }
    }
}

int quickestWayUp(vector < vector<int> > ladders, vector < vector<int> > snakes) {
    int cache[100] = {0};
    bool visited[100] = {false};
    int m = INT_MAX;
    for(int i = 1; i <= 6; i++){
        // return max of all 6
        cache[i] = _helper(ladders, snakes, 1+i, 1, cache, visited);
        if(cache[i] < m){
            m = cache[i];
        }
    }
    if(m > 1000000){
        return -1;
    }
    return m;
}

int main() {
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        vector< vector<int> > ladders(n,vector<int>(2));
        for(int ladders_i = 0;ladders_i < n;ladders_i++){
            for(int ladders_j = 0;ladders_j < 2;ladders_j++){
                cin >> ladders[ladders_i][ladders_j];
            }
        }
        int m;
        cin >> m;
        vector< vector<int> > snakes(m,vector<int>(2));
        for(int snakes_i = 0;snakes_i < m;snakes_i++){
            for(int snakes_j = 0;snakes_j < 2;snakes_j++){
                cin >> snakes[snakes_i][snakes_j];
            }
        }
        int result = quickestWayUp(ladders, snakes);
        cout << result << endl;
    }
    return 0;
}