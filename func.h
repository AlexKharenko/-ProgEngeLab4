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
	string name_in;
	string name_out;
public:
	void set_name_func(char* argv);
	void set_name_in(char* name);
	void set_name_out(char* name);
	void decom_out();
	void com_out();
	string get_name_in();
	string get_name_out();
	string get_name_func();
	void set_work(int argc);
	bool get_work();
	void out_f_in_out();
};

class archive:public Program {
	string data;
	unordered_map<string, int> dictionary;
	int size = 255;
	vector<int> output;
	int code = 256;
public:
	void read_data();
	void read_data_2();
	void init_dict();
	void out_dict();
	void compress();
	void decompress();
	void write_compress_output_file();
};
