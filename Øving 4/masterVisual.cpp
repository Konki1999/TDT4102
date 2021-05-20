#include "masterVisual.h"

void addGuess(MastermindWindow &win, const string code, const int size, const char startLetter, const int round)
{
	cout << "Adding guess... \n";
    for(int i = 0; i < code.size(); i++){
        cout << "Added guess-letter number " << i+1 << endl;
        int c = code[i]%size;
		cout << "Color: " << c << endl;
        win.vr.push_back(new Rectangle{Point{(2*i + 1)*padX,(2*round + 3)*padY},padX,padY});
        win.vr[win.vr.size()-1].set_fill_color(c);
        win.attach(win.vr[win.vr.size()-1]);
    }
    cout << "Redrawing window...\n";
    win.redraw();
}

void addFeedback(MastermindWindow &win, const int correctPosition, const int correctCharacter, const int size,
				 const int round)
{
	cout << "Adding feedback... \n";
    for(int i = 1; i <= correctPosition; i++){
        cout << "Added correct position-circle number " << i << endl;
		int c = 2;
        win.vc.push_back(new Circle{Point{(2*size+1)*padX+radCircle*2*(i-1),(2*round + 4)*padY},radCircle});
        win.vc[win.vc.size()-1].set_fill_color(c);
        win.attach(win.vc[win.vc.size()-1]);
    }
	for(int i = correctPosition+1; i <= correctCharacter; i++){
        cout << "Added correct character-circle number " << i+1 << endl;
		int c = 3;
        win.vc.push_back(new Circle{Point{(2*size+1)*padX + 2*(correctPosition-1)*radCircle + radCircle*2*(i- correctPosition),(2*round + 4)*padY},radCircle});
        win.vc[win.vc.size()-1].set_fill_color(c);
        win.attach(win.vc[win.vc.size()-1]);
    }
	for(int i = correctCharacter+1; i <= size; i++){
        cout << "Added wrong circle number " << i+1 << endl;
		int c = 1;
        win.vc.push_back(new Circle{Point{(2*size+1)*padX + 2*(correctCharacter-1)*radCircle + radCircle*2*(i - correctCharacter),(2*round + 4)*padY},radCircle});
        win.vc[win.vc.size()-1].set_fill_color(c);
        win.attach(win.vc[win.vc.size()-1]);
    }
    cout << "Redrawing window...\n";
    win.redraw();
}

void hideCode(MastermindWindow &mwin, const int size)
{
	mwin.vr.push_back(new Rectangle{Point{padX, 3 * padY}, winW - size * padX, padY});
	mwin.vr[mwin.vr.size() - 1].set_fill_color(Color::black);
	mwin.attach(mwin.vr[mwin.vr.size() - 1]);
}

MastermindWindow::MastermindWindow(Point xy, int w, int h, const string &title) : Window(xy, w, h, title),
																				  button_pressed{false},
																				  guessBtn{upperLeftCornerBtn, btnW, btnH, "Add", cb_guess},
																				  guess{upperLeftCornerInBox, inBoxW, inBoxH, "Guess"}
{
	attach(guess);
	attach(guessBtn);
};

string MastermindWindow::wait_for_guess()
{
	while (!button_pressed)
	{
		Fl::wait();
	}
	button_pressed = false;
	string newGuess = guess.get_string();
	guess.clear_value();
	return newGuess;
}

string MastermindWindow::getInput(unsigned int n, char lower, char upper)
{
	bool validInput = false;
	string guess;
	while (!validInput)
	{
		guess.clear();
		string input = wait_for_guess();
		if (input.size() == n)
		{
			for (unsigned int i = 0; i < n; i++)
			{
				char ch = input[i];
				if (isalpha(ch) && toupper(ch) <= upper && lower <= toupper(ch))
				{
					guess += toupper(ch);
				}
				else
					break;
			}
		}
		if (guess.size() == n)
		{
			validInput = true;
		}
		else
		{
			cout << "Invalid input guess again\n";
		}
	}
	return guess;
}
