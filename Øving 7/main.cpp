//
// This is example code from Chapter 2.2 "The classic first program" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
// 
// keep_window_open() added for TDT4102, excercise 0

// This program outputs the message "Hello, World!" to the monitor

#include "Animals.h"
#include "Simple_window.h"
#include "Emoji.h"

// Size of window and emoji radius
constexpr int xmax = 1000;
constexpr int ymax = 600;
constexpr int emojiRadius = 50;

//------------------------------------------------------------------------------'

// C++ programs start by executing the function main
int main()
{
	testAnimal();

	using namespace Graph_lib;

	const Point tl{100, 100};
	const string win_label{"Emoji factory"};
	Simple_window win{tl, xmax, ymax, win_label};

	FaceWithEyes face1 = FaceWithEyes({150,150},70);
	face1.attach_to(win);

	SmilingFace face2 = SmilingFace({300, 150}, 70);
	face2.attach_to(win);

	SadFace face3 = SadFace({450, 150}, 70);
	face3.attach_to(win);

	ShockedFace face4 = ShockedFace({600, 150}, 70);
	face4.attach_to(win);

	MehFace face5 = MehFace({750, 150}, 70);
	face5.attach_to(win);

	win.wait_for_button();
}

//------------------------------------------------------------------------------
