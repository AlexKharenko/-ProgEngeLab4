#include "func.h"

void Program::set_name_func(char* argv) {
	name_func = argv;
}
void Program::set_name_in(char* name) {
	name_in = name;
}
void Program::set_name_out(char* name) {
	name_out = name;
}
void Program::out_f_in_out() {
	cout << name_func << " " << name_in << " " << name_out << endl;
}
void Program::set_work(int argc){
	if (argc == 4) {
		work = 1;
		return;
	}
	cout << "Error!" << endl;
	work = 0;
}
bool Program::get_work() {
	return work;
}

