#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <unordered_map>

using namespace std;

class Program {
	bool work;
	string name_func;
	string name_in =".\\";
	string name_out = ".\\";
	vector <string> data;
public:
	void set_name_func(char* argv);
	void set_name_in(char* name);
	void set_name_out(char* name);
	string get_name_func();
	void set_work(int argc);
	bool get_work();
	void read_data();
	vector<string> get_data();
	void out_f_in_out();
};

class archive:public Program {
	unordered_map<string, int> dictionary;
	int size = 255;
public:
	void init_dict();
	void out_dict();
	void compress();
};
