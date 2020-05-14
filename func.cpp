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
string Program::get_name_in() {
	return name_in;
}
string Program::get_name_out() {
	return name_out;
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

void Program::decom_out() {
	cout << "Getting out file " << name_out << " ..."<<endl;
	cout << "Done";
}
void archive::read_data() {
	fstream in(get_name_in());
	while (!in.eof()) {
		string temp;
		in >> temp;
		data.push_back(temp);
	}
	in.close();
}

void archive::read_data_2() {
	fstream in(get_name_in());
	int i = 0;
	int j = 256;
	char *name = new char [j];
	while (!in.eof()) {
		if (i == 0) {
			in >> name;
			i++;
			set_name_out(name);
		}
		int temp;
		in >> temp;
		output.push_back(temp);
	}
	in.close();
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
void archive::write_compress_output_file() {
	ofstream out(get_name_out());
	for (int i = 0; i < output.size(); i++)
	{
		if (i == 0) {
			out << get_name_in() <<" ";
			continue;
		}
		out << output[i]<<" ";
	}
	out.close();
}
void archive::compress() {
	string p = "", c = "";
	int k = 0;
	p += data[k][0];
	while(k!=data.size())
	{
		
		for (int i = 0; i < data[k].length(); i++) {
			if (i != data[k].length()-1) {
					c += data[k][i + 1];
			}
			if (k!=data.size()-1 && i == data[k].length() - 1) {
				c += " ";
			}
			if (dictionary.find(p + c) != dictionary.end()) {
				p = p + c;
			}
			else {
				
					cout << p << "\t" << dictionary[p] << "\t\t"
						<< p + c << "\t" << code << endl;
					output.push_back(dictionary[p]);
					dictionary[p + c] = code;
					code++;
					p = c;
				
			}
			c = "";
		}
		k++;
		c += data[k][0];
		if (dictionary.find(p + c) != dictionary.end()) {
			p = p + c;
		}
		else {
			if (k != data.size()) {
				cout << p << "\t" << dictionary[p] << "\t\t"
					<< p + c << "\t" << code << endl;
					output.push_back(dictionary[p]);
					dictionary[p + c] = code;
					code++;
					p = c;
			}
		}
		c = "";
		
	}
	cout << p << "\t" << dictionary[p] << endl;
	output.push_back(dictionary[p]);
	write_compress_output_file();
	for (int i = 0; i < output.size(); i++)
	{
		cout << output[i] << " ";
	}
	cout << endl;
}
void archive::decompress() {
	unordered_map<int, string> table;
	for (int i = 0; i <= 255; i++) {
		string ch = "";
		ch += char(i);
		table[i] = ch;
	}
	int old = output[0], n;
	string s = table[old];
	string c = "";
	string str;
	c += s[0];
	str += s;
	int count = 256;
	for (int i = 0; i < output.size() - 1; i++) {
		n = output[i + 1];
		if (table.find(n) == table.end()) {
			s = table[old];
			s = s + c;
		}
		else {
			s = table[n];
		}
		str += s;
		c = "";
		c += s[0];
		table[count] = table[old] + c;
		count++;
		old = n;
	}
	string name = get_name_out();
	ofstream out(name);
	for (int i = 0; i < str.size(); i++) {
		out << str[i];
	}
	out.close();
}