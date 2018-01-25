#include <string>

using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);

        int marker = -1;
        char m = '9';
        for(int i = 0; i < s.length(); i++){
            if(s[i] != m){
                marker = i;
                break;
            }
        }

        if(marker > -1){
            int m_idx = marker;
            char m = s[marker];
            bool swp = false;

            while(!swp && m_idx != s.length() - 1){
                for(int i = s.length()-1; i > marker; i--){
                    if(s[i] > m && s[i] > s[marker]){
                        m = s[i];
                        m_idx = i;
                        swp = true;
                    }
                }
                if(!swp){
                    marker++;
                    m_idx = marker;
                    m = s[m_idx];
                }
            }
            if(swp){
                //perform swap
                s[m_idx] = s[marker];
                s[marker] = m;
            }
        }
        return stoi(s);
    }
};