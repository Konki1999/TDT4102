#include "Emoji.h"

Face::Face(Point c, int r) : shape{c, r} {
    shape.set_fill_color(Color::yellow);
};

void Face::attach_to(Graph_lib::Window& win){
    win.attach(shape);
};

FaceWithEyes::FaceWithEyes(Point c, int r) : Face(c, r), leftEye{Point{c.x-r/3, c.y-r/3},r/6}, rightEye{Point{c.x+r/3, c.y-r/3},r/6} {
    leftEye.set_fill_color(Color::black);
    rightEye.set_fill_color(Color::black);
};

void FaceWithEyes::attach_to(Graph_lib::Window& win){
    Face::attach_to(win);
    win.attach(leftEye);
    win.attach(rightEye);
};

SmilingFace::SmilingFace(Point c, int r) : FaceWithEyes(c,r), mouth{c, 5*r/3, 5*r/6, 180, 360}{};

void SmilingFace::attach_to(Graph_lib::Window& win){
    FaceWithEyes::attach_to(win);
    win.attach(mouth);
};

SadFace::SadFace(Point c, int r) : FaceWithEyes(c,r), mouth{{c.x,c.y+5*r/12}, 5*r/3, 5*r/6, 0, 180}{};

void SadFace::attach_to(Graph_lib::Window& win){
    FaceWithEyes::attach_to(win);
    win.attach(mouth);
};

ShockedFace::ShockedFace(Point c, int r) : FaceWithEyes(c,r), mouth{{c.x,c.y+r/2}, r/3}{
    mouth.set_fill_color(Color::black);
};

void ShockedFace::attach_to(Graph_lib::Window& win){
    FaceWithEyes::attach_to(win);
    win.attach(mouth);
};

MehFace::MehFace(Point c, int r) : FaceWithEyes(c,r), mouth{{c.x-2*r/3,c.y+r/4},4*r/3,r/10}{
    mouth.set_fill_color(Color::black);
};

void MehFace::attach_to(Graph_lib::Window& win){
    FaceWithEyes::attach_to(win);
    win.attach(mouth);
};