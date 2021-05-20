#pragma once

#include <vector>

using namespace std;

class C{
    private:
        vector<int*> values;
        int val;
    public:
        C(int n){
            for(int i = 0; i < n; i++){
                int* value = new int{0};
                values.push_back(value);
            }
        }
        C(int n, int val) : C(n){
            for(auto el : values){
                *el = val;
            }
        }
        ~C(){
            for(auto el : values){
                delete el;
            }
        }
};