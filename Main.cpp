#include <iostream>
#include <string>
#include <regex>

using namespace std;

void print_usage_and_quit();
void print_cheatsheet_and_quit();

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);

	string temp_str;

	if (argc == 2) {
		temp_str = argv[1];

		if (temp_str == "cheatsheet") {
			print_cheatsheet_and_quit();
		}
	}

	if (argc != 3)
		print_usage_and_quit();
	
	regex expr;
	
	try {
		expr = regex(argv[1]);
	} catch(...) {
		cerr << "Invalid regex expression!\n";
		return 2;
	}

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
	cerr << "Usage: regex [[other] | [expression] [string]]\n"
	        "Other:\n"
			"\tcheatsheet    Invoke a cheatsheet for help. (source: https://regexone.com/)\n";
	exit(-1);
}

void print_cheatsheet_and_quit() {
	cout << "Cheatsheet (source: https://regexone.com/):\n\n"
			"abc...    Letters\n"
			"123...    Digits\n"
			"\\d        Any digit\n"
			"\\D        Any non-digit character\n"
			".         Any character\n"
			"\\.        Period\n"
			"[abc]     Only a, b or c\n"
			"[^abc]    Not a, b nor c\n"
			"[a-z]     Characters a to z\n"
			"[0-9]     Numbers 0 to 9\n"
			"\\w        Any alphanumeric character\n"
			"\\W        Any non-alphanumeric character\n"
			"{m}       m repetitions\n"
			"{m, n}    m to n repetitions\n"
			"*         Zero or more repetitions\n"
			"+         One or more repetitions\n"
			"?         Optional character\n"
			"\\s        Any whitespace\n"
			"\\S        Any non-whitespace character\n"
			"^...$     Starts and ends\n"
			"(...)     Character group\n"
			"(a(bc))   Capture sub-group\n"
			"(.*)      Capture all\n"
			"(abc|def) Matches abc or def\n";
	exit(-2);
}
