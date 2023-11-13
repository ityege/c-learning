#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
	using namespace std;
	vector<int> tokens;
	ifstream input;
	ofstream output;
	input.open("abc.txt");
	output.open("abc_new.txt");

	string tmp;
	while (getline(input, tmp, '\n')) {
		stringstream ss(tmp);
		string tmp1;
		while (getline(ss, tmp1, ',')) {
			tmp1.erase(0, tmp1.find_first_not_of(" \n\r\t"));//去除字符串头部的空格
			tmp1.erase(tmp1.find_last_not_of(" \n\r\t") + 1);//去除字符串尾部的空格
			tokens.push_back(stoi(tmp1));
			output << stoi(tmp1) << endl;
		}
	}

	cout << "==================================" << endl;

	for (auto token : tokens) {

		cout << token << endl;
	}

	cout << "==================================" << endl;

	for_each(tokens.begin(), tokens.end(), [](auto token) {
		cout << token << endl;
		});
	output.close();
	input.close();


	return 0;
}
