#include "mastermind.h"

void playMastermind(){
    char start = 'A';

    char end = start + (letters-1);
    int iter = 0;
    string code = randomizeString(length, start, end);
    bool run = true;
    cout << "You must choose letters between " << start << " and " << end << endl;
    while(run){
        iter++;
        string guess = readInputToString(length);
        toUpper(guess);
        int correctPos = checkCharactersAndPosition(code, guess);
        int correctLet = checkCharacters(code, guess);
        cout << "\n\nYou guessed: \"" << guess <<"\"\n"
             << correctLet << " correct letters in total.\n"
             << correctPos << " letters in the correct position.\n"; 
        if(correctPos == length){
            cout << "Congratulations! Your guess is correct. The code is: "
                 << code << endl;
            run = false;
        }
        else if(iter >= maxAttempts){
            cout << "Game over! You were not able to guess the code. The code is: "
                 << code << endl;
            run = false;
        }   
    }
}

void playMastermindVisual(){
    char start = 'A';

    MastermindWindow mwin{Point{900, 20}, winW, winH, "Mastermind"};
    char end = start + (letters-1);
    int iter = 0;
    string code = randomizeString(length, start, end);
    bool run = true;

    //addGuess(mwin, code, letters, start, iter);
    //hideCode(mwin, length);

    while(run){
        string guess = mwin.getInput(length, start, end);
        //iter++;

        addGuess(mwin, guess, letters, start, iter);

        int correctPos = checkCharactersAndPosition(code, guess);
        int correctLet = checkCharacters(code, guess);

        addFeedback(mwin, correctPos, correctLet, length, iter);

        iter++;

        cout << "\n\nYou guessed: \"" << guess <<"\"\n"
             << correctLet << " correct letters in total.\n"
             << correctPos << " letters in the correct position.\n"; 
        if(correctPos == length){
            cout << "Congratulations! Your guess is correct. The code is: "
                 << code << endl;
            run = false;
        }
        else if(iter >= maxAttempts){
            cout << "Game over! You were not able to guess the code. The code is: "
                 << code << endl;
            run = false;
        }   
    }
}

int checkCharactersAndPosition(string code, string guess){
    int len = code.size();
    int correct = 0;
    for(int i = 0; i < len; i++){
        if(code[i] == guess[i]){
            correct++;
        }
    }
    return correct;
}
int checkCharacters(string code, string guess){
    int len = code.size();
    char c = code[0];
    int correct = 0;
    for(int i = 0; i < len; i++){
        if(code[i] > c){
            c = code[i];
        }
    }
    for(char x = 'A'; x <= c; x++){
        int letterInCode = countChar(code,x);
        int letterInGuess = countChar(guess,x);
        correct += minOfTwo(letterInCode, letterInGuess);
    }
    return correct;
}