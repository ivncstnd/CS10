#include "HuffmanCoding.h"

using namespace std;

int main(int argc, char* argv[]) {

    if (argc != 2) {
        cerr << "Usage error: expected <executable> <input>" << endl;
        exit(1);
    }

    ifstream ifs(argv[1]);
    if (!ifs) {
        cerr << "Input file not found." << endl;
        exit(1);
    }

    HuffmanCoding test(ifs);
    ifs.close();
    cout << endl;
    return 0;
}