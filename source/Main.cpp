#include <iostream>
#include <string>
#include <regex>

using std::string;
using std::regex;
using std::cout;
using std::cerr;
using std::smatch;

void print_usage_and_quit();
void print_cheatsheet_and_quit();

int main(int argc, char** argv) {
	//we won't be using stdio
	//desyncing it can improve performance
	std::ios_base::sync_with_stdio(false);

	//if there are only two arguments
	//we'll check if the user wants
	//to see the cheatsheet
	if (argc == 2) {
		string temp_str = argv[1];

		if (temp_str == "cheatsheet") {
			print_cheatsheet_and_quit();
		}
	}

	//the number of arguments should be three
	//which include the regex expression and the string
	if (argc != 3)
		print_usage_and_quit();
	
	//get regex expression from argument #1
	regex expr;
	try {
		expr = regex(argv[1]);
	} catch(...) {
		cerr << "Invalid regex expression!\n";
		return 2;
	}

	//get string from argument #2
	string str = argv[2];

	//regex matcher
	smatch match;
	int match_index = 0;
	int group_index = 0;

	//keep searching until no more matches are found
	while (regex_search(str, match, expr)) {
		//parse through each group in the match
		for (const auto& group : match) {
			//e.g. "Match 0: Group 0: {string}"
			cout << "Match " << match_index << ": Group " << group_index << ": {" << group.str() << "}\n";
			++group_index;
		}
		group_index = 0;

		++match_index;
		str = match.suffix(); //remove matched substring
	}

	//match_index should at least be 1
	//if there were any matches therefore
	//0 means there was no match
	if (match_index == 0)
		cout << "No match.\n";

	return 0;
}

void print_usage_and_quit() {
	cerr << "Usage: regex \"[expression]\" \"[string]\"\n"
			"Or: \"regex cheatsheet\" for a quick regex reference taken from \"https://regexone.com/\".\n";
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
