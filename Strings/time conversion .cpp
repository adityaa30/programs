#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the timeConversion function below.
 */
string timeConversion(string s) {
    string hour_str=s.substr(0,2);
    int hour=stoi(hour_str);
    if (s.find("PM")){
        if(hour+12<24){
            hour_str=to_string(hour+12);
        }
    }
    else{
        if (hour==12){
            hour_str="00";

        }
    }
return s.replace(0,2,hour_str).erase(s.length()-2);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
