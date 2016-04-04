#ifndef MACRO_HPP
#define MACRO_HPP

#define USE(x) class x; // Use a class
#define VECTOR_OF(x) std::vector<x*> // Vector of pointers to objects
#define CONNECT(x) x* frame(){return x::access();} // Connects an object to a frame
#define INIT_CONNECTION(x) static x* _frame; // Initialize the connection
#define SET_CONNECTION(x) static void setFrameInstance(x* frame){x::_frame = frame;} static x* access(){return x::_frame;} // Creates connection methods
#define CONNECTION() setFrameInstance(this); // Connects the frame
#define INIT_FRAME(x) x* x::_frame = 0; // Initialize the frame connection

#endif