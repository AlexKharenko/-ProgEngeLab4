#pragma once
#include <iostream>
#include <string>

using namespace std;

class Program {
	bool work;
	string name_func;
	string name_in;
	string name_out;
public:
	void set_name_func(char* argv);
	void set_name_in(char* name);
	void set_name_out(char* name);
	void set_work(int argc);
	bool get_work();
	void out_f_in_out();
};

class archive:public Program {
	
public:
	
};
