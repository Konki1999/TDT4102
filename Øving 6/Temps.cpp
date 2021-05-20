#include "Temps.h"

istream& operator>>(istream& is, Temps& t){
    double max, min;
    is >> max  >> min;
    if(!is){
        return is;
    }
    t.max = max;
    t.min = min;
    return is;
}

vector<Temps> readTemps(string filename){
    ifstream readFile;
    readFile.open(filename, ios::in);
    if (!readFile) {
        cout << "No such file \"" << filename << "\"\n";
    }
    else{
        vector<Temps> tempLst;
        Temps t{};
        while(readFile >> t){
            tempLst.push_back(t);
        }
        return tempLst;
    }
}

void tempStats(vector<Temps> temps){
    int n = temps.size();
    double min = temps[0].min;
    double max = temps[0].max;
    int minDay = 0;
    int maxDay = 0;
    for(int i = 0; i < n; i++){
        if(temps[i].min < min){
            min = temps[i].min;
            minDay = i;
        }
        if(temps[i].max > max){
            max = temps[i].max;
            maxDay = i;
        }
    }
    cout << "Laveste temperatur ble maalt " << minDay << " dager etter 3. februar 2018. Temperaturen var: " << min << endl;
    cout << "Hoeyeste temperatur ble maalt " << maxDay << " dager etter 3. februar 2018. Temperaturen var: " << max << endl;
}

void testTemps(){
    vector<Temps> tempLst = readTemps("temperatures.txt");
    tempStats(tempLst);
}