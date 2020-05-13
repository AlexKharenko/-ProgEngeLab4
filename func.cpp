#include "func.h"

void Program::set_name_func(char* argv) {
	name_func = argv;
}
void Program::set_name_in(char* name) {
	name_in += name;
}
void Program::set_name_out(char* name) {
	name_out += name;
}
string Program::get_name_func() {
	return name_func;
}
void Program::out_f_in_out() {
	cout << name_func << " " << name_in << " " << name_out << endl;
}
void Program::set_work(int argc){
	if (argc < 3 ) {
		work = false;
		cout << "Error!" << endl;
	}
	work = true;
}
bool Program::get_work() {
	return work;
}
void Program::read_data() {
	fstream out(name_out);
	int i = 0;
	while (!out.eof()) {
		out >> data[i];
		i++;
	}
	for (int j=0 ;j< data.size();j++)
	{
		cout << data[j] << " ";
	}
	cout << endl;
}
vector<string> Program::get_data() {

}
void archive::init_dict() {
	for (int i = 0; i <= 255; i++) {
		string ch = "";
		ch += char(i);
		dictionary[ch] = i;
	}
}
void archive::out_dict() {
	for (int i = 0; i <= size; i++) {
		string ch = "";
		ch += char(i);
		cout << dictionary[ch] << " , ";
	}
	cout << endl;
}
void archive::compress() {
	
}