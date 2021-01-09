/*************************************
 * An example program to solve the puzzle problem using set
 *
 * COP 4530
 * FSU Department of Computer Science
 */

#include <word_puzzle_set.h>

using namespace std;

main(int argc, char *argv[]) {
    set<string> words;
    vector<string> puzzle, puzzle_rotated;
    typedef set<string>::iterator ITR;

    ifstream wf;
    string one_word;
    string one_line;
    string token;
    int dimension;

    // check parameters
    if (argc > 2) {
	cout << argv[0] << " [word_file]" << endl;
	exit(1);
    }

    // one parameter
    if (argc == 2) {
	// a word file is given.
	wf.open(argv[1]);

	if (!wf) {
	    cout << "word file not opened" << endl;
	    // we continue our program even if the word file cannot be loaded.
	} else {
	    while (wf >> one_word) {
		words.insert(one_word);
	    }
	    wf.close();
	}
    }

    // cout << word_list.size() << endl;

    // load in a new word file or a puzzle file
    while (getline(cin, one_line)) {
	// parsing line using stringstream
	istringstream ss(one_line);
	ss >> token;

	if (token == "q") {
	    // exit the program
	    break;
	} else if (token == "l") {
	    // load a new word file
	    
	    ss >> token;
	    wf.open(token.c_str());

	    if (!wf) {
		cout << "word file not opened" << endl;
	    } else {
		// delete old word list first
		words.clear();
		while (wf >> one_word) {
		    words.insert(one_word);
		}
		wf.close();
	    }
	} else if (token == "p") {
	    puzzle.clear();
	    ss >> token;
	    //cerr << "file name: " << token << endl;
	    
	    wf.open(token.c_str());
	    if (!wf) {
		cout << "puzzle file not opened" << endl;
	    } else {
		getline(wf, one_line);
		istringstream st(one_line);
		st >> dimension;
		while (wf >> one_line) {
		    puzzle.push_back(one_line);
		}
		
		cout << "valid words in the puzzle:" << endl;
		// horizontal (bidirectional)
		for (int i = 0; i < dimension; ++i) {
		    for (int j = 0; j < dimension; ++j) {
			for (int k = j; k < dimension; ++k) {
			    // left to right
			    one_word = puzzle[i].substr(j, k-j+1);
			    // cout << one_word << endl;
			    if (words.find(one_word) != words.end()) {
				cout << "  " << one_word << endl;
			    }
			    
			    // right to left
			    if (one_word.length() > 1) {
				reverse(one_word.begin(), one_word.end());
				if (words.find(one_word) != words.end()) {
				    cout << "  " << one_word << endl;
				}
			    }
			}
		    }
		}

		// vertical (bidirectional)
		rotation(puzzle, puzzle_rotated);
		for (int i = 0; i < dimension; ++i) {
		    for (int j = 0; j < dimension; ++j) {
			for (int k = j; k < dimension; ++k) {
			    // left to right
			    one_word = puzzle_rotated[i].substr(j, k-j+1);
			    // cout << one_word << endl;
			    if (words.find(one_word) != words.end()) {
				cout << "  " << one_word << endl;
			    }
			    
			    // right to left
			    if (one_word.length() > 1) {
				reverse(one_word.begin(), one_word.end());
				if (words.find(one_word) != words.end()) {
				    cout << "  " << one_word << endl;
				}
			    }
			}
		    }
		}

		// diagonal (bidirectional)
		// top left to bottom right; and top right to bottom left
		string str1, str2;
		for (int i = 0; i < dimension; ++i) {
		    str1 += puzzle[i][i];
		    str2 += puzzle[i][(dimension-1)-i];
		}
		// cout << str1 << " " << str2 << endl;
		
		for (int i = 0; i < str1.length(); ++i) {
		    for (int j = i; j < str1.length(); ++j) {
			one_word = str1.substr(i, j-i+1);
			// cout << one_word << endl;
			if (words.find(one_word) != words.end()) {
			    cout << "  " << one_word << endl;
			}
			
			if (one_word.length() > 1) {
			    reverse(one_word.begin(), one_word.end());
			    if (words.find(one_word) != words.end()) {
				cout << "  " << one_word << endl;
			    }
			}

		
			one_word = str2.substr(i, j-i+1);
			// cout << one_word << endl;
			if (words.find(one_word) != words.end()) {
			    cout << "  " << one_word << endl;
			}
			
			if (one_word.length() > 1) {
			    reverse(one_word.begin(), one_word.end());
			    if (words.find(one_word) != words.end()) {
				cout << "  " << one_word << endl;
			    }
			}
		    }
		}
	    }
	} else if (token == "d") {
	    // display current word list
	    for (ITR itr = words.begin(); itr != words.end();
		 ++itr) {
		cout << *itr << endl;
	    }
	} else {
	    cout << "invalid commands" << endl;
	}
    }
}

