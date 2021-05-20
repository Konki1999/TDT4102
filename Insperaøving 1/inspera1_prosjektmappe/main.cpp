#include "std_lib_facilities.h"
#include "survey2021.h"

int main()
{
	map<string,int> wordCount = mapSurvey();
	for(auto& i : wordCount){
		cout << "Ordet " << i.first << " forekommer " << i.second << " ganger.\n";
	}
	cout << "\nListe sortert i synkende rekkefølge:\n";
	vector<string> sortedMapVec = sortVector(wordCount);
	for(auto& x : sortedMapVec){
		cout << x << endl;
	}

	surveyResults(wordCount);
}
