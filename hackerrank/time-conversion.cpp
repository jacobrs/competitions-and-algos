#import <string>
#import <iostream>

using namespace std;

string timeConversion(string s) {
    if(s.length() == 10){
        int hour = stoi(s.substr(0, 2));
        string am_pm = s.substr(8, 2);

        if(am_pm == "PM" && hour < 12){
            hour += 12;
        }else if(am_pm == "AM" && hour == 12){
            hour = 0;
        }
        string n_hour = '0' + to_string(hour);
        return n_hour.substr(n_hour.length()-2) + s.substr(2, 6);
    }
    return "NaT";
}

int main() {
    string s;
    cin >> s;
    string result = timeConversion(s);
    cout << result << endl;
    return 0;
}