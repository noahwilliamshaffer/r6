#include <iostream>
#include <map>
#include <cstring>
#include <cstdlib>

using std::cout;
using std::endl;
using std::map;

struct ltstr {
    bool operator() (const char *s1, const char *s2) const {
	return strcmp(s1, s2) < 0;
    }
};

int main() {
    typedef map<const char*, int, ltstr> MAP;    
    typedef MAP::iterator ITR;

    MAP months;

    months["january"] = 31;
    months["february"] = 28;
    months["march"] = 31;
    months["april"] = 30;
    months["may"] = 31;
    months["june"] = 30;
    months["july"] = 31;
    months["august"] = 31;
    months["september"] = 30;
    months["october"] = 31;
    months["november"] = 30;
    months["december"] = 31;

    for (ITR itr = months.begin(); itr != months.end(); ++itr) {
    	cout << itr->first << ": " << itr->second << endl;
    }

    cout << "june: " << months["june"] << endl;

    ITR cur = months.find("june");
    ITR prev = cur;
    ITR next = cur;
    --prev;
    ++next;
    
    cout << "Previous (in alphabetical order) is " << (*prev).first 
	 << ": " << (*prev).second << endl;
    cout << "Next (in alphabetical order) is " << next->first 
	 << ": " << next->second << endl;
    return(EXIT_SUCCESS);
}
