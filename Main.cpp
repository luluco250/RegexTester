#include <iostream>
#include <string>
#include <regex>

using namespace std;

void print_usage_and_quit();

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);

	if (argc < 3)
		print_usage_and_quit();
	
	regex expr = regex(argv[1]);
	string str = argv[2];

	smatch sm;
	int index = 0;

	if (regex_match(str, sm, expr)) {
		for (const string& match : sm) {
			cout << index << ": {" << match << "}\n";
			++index;
		}
	} else {
		cout << "No match.\n";
		return 1;
	}

	return 0;
}

void print_usage_and_quit() {
	cerr << "Usage: regex [expression] [string]\n";
	exit(-1);
}
