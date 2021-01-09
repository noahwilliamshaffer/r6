#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

string get_vow(string str) 
{
	string vow;
	for (size_t i = 0; i < str.length(); ++i) {
		if (str[i] == 'a' || str[i] == 'e' || \
				str[i] == 'o' || str[i] == 'i' || \
				str[i] == 'u') {
			vow.push_back(str[i]);
		}
	}
	return vow;
}

int main() 
{
	int str_count;
	int list_count = 1;

	typedef map<string, vector<string> > MAP;

	cout.setf(ios::left);
	// read in one list of strings
	while (cin >> str_count) {
		MAP a_map;
		string str;
		size_t str_len = 0;

		for (int i = 0; i < str_count; i++) {
			cin >> str;
			string vow = get_vow(str);
			a_map[vow].push_back(str);
			if (str_len < str.length()) {
				str_len = str.length();
			}
		}

		str_len += 2;
		cout << "List #" << list_count << endl;
		MAP::iterator iter = a_map.begin();
		int line = 0;
		while (iter != a_map.end()) {
			vector<string>::iterator iter2 = (*iter).second.begin();
			vector<string>::iterator iter3 = (*iter).second.end();
			sort(iter2, iter3);
			while (iter2 != (*iter).second.end()) {
				line += str_len;
				if (line > 80) {
					cout << endl;
					line = str_len;
				}
				cout.width(str_len);
				cout << (*iter2);
				++iter2;
			}
			++iter;
		}
		cout << endl << endl;
		++list_count;
	}
}
