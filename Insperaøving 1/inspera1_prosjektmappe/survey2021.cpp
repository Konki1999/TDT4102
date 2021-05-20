#include "survey2021.h"

// Implement all the necessary functions as described in the task.

map<string,int> mapSurvey(){
    map<string,int> surveyRes;
    fstream readFile;
    readFile.open("survey_2021.txt", ios::in);
    if(!readFile){
        throw "No such file \"survey_2021.txt\"\n";
    }
    else{
        string line;
        while(getline(readFile,line)){
            istringstream words (line);
            string word;
            while(getline(words, word, ' ')){
                if(surveyRes.count(word) == 0){
                    surveyRes.insert({word,1});
                }
                else{
                    surveyRes[word] = surveyRes[word] + 1;
                }
            }
        }
    }
    readFile.close();
    return surveyRes;
}

vector<string> sortVector(map<string,int> map){
    vector<string> vec;
    for(auto& i : map){
		vec.push_back(i.first);
	}
    int iter = 0;
    int counter = 0;
    while(true){
        //bruker bubble sort fordi det er enklest
        if(iter+1 == vec.size()){
            iter = 0;
            if(counter == 0){
                break;
            }
            counter = 0;
        }
        string word1 = vec[iter];
        string word2 = vec[iter+1];
        if(map[word1]<map[word2]){
            vec[iter] = word2;
            vec[iter+1] = word1;
            counter++;
        }
        iter++;
    }
    return vec;
}

void surveyResults(map<string,int> map){
    fstream writeFile;
    writeFile.open("surveyResults.txt", ios::out);
    if(!writeFile){
        ofstream file{"surveyResults.txt"};
    };

    vector<string> vec = sortVector(map);
    writeFile << "Survey results 2021:\n--------------\n";
    for(string x : vec){
        string output = x + ", " + to_string(map.at(x)) + '\n' ;
        writeFile << output;
    }
    writeFile.close();
}