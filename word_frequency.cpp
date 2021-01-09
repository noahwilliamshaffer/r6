/**********************************
 * a simple program to count word frequency
 * a word is defined as a sequence of characters separated by a space. 
 *
 * COP 4530, 
 * Department of Computer Science, Florida State University.
 */
#include <iostream>
#include <string>
#include <cctype>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main() {
    map<string, int> word_map;
    typedef map<string, int>::iterator ITR;

    string word;
    
    while (cin >> word) {
	++word_map[word];
    }

    cout << "Number of words: " << word_map.size() << endl;

    // print words and frequency
    for (ITR itr = word_map.begin(); itr != word_map.end();
	 ++itr) {
	cout << itr->first << ": " << itr->second << endl;
    }
    return(EXIT_SUCCESS);
}
