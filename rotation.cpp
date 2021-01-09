#include <word_puzzle_map.h>

void rotation(const vector<string> &orig, vector<string> &rotated) {
    int dimension = orig.size();

    // resize rotated
    rotated.clear();
    rotated.resize(dimension);
    for (int i = 0; i < dimension; ++i) {
	for (int j = 0; j < dimension; ++j) {
	    rotated[j] += orig[i][j];
	}
    }
    return;
}
