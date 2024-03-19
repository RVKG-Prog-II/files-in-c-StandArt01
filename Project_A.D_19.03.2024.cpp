#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

using std::string;

void countAndWriteDigitsPerLine(string filename, string outputFilename) {
    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Error: cannot open the file " << filename << endl;
        return;
    }

    ofstream outputFile(outputFilename);
    if (!outputFile.is_open()) {
        cerr << "Error: cannot open the file " << outputFilename << endl;
        return;
    }

    string line;
    while (getline(inputFile, line)) {

        int digitCount = std::count_if(line.begin(), line.end(), ::isdigit);
        outputFile << digitCount << endl;
    }

    inputFile.close();
    outputFile.close();
}

unsigned int countMaxDigits(string filename) {
    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Error: cannot open the file " << filename << endl;
        return 0;
    }

    unsigned int maxDigits = 0;

    string line;
    while (getline(inputFile, line)) {
        int digitCount = std::count_if(line.begin(), line.end(), ::isdigit);

        if (digitCount > maxDigits) {
            maxDigits = digitCount;
        }
    }

    inputFile.close();

    return maxDigits;
}

int main() {
    string inputFilename = "C:\\Users\\RVKG\\source\\repos\\Project_A.D_19.03.2024\\Project_A.D_19.03.2024\\Numbers.txt";
    string outputFilename = "number_rows.txt";

    countAndWriteDigitsPerLine(inputFilename, outputFilename);

    unsigned int maxDigits = countMaxDigits(inputFilename);
    std::cout << "max digit count in the file: " << maxDigits << std::endl;

    return 0;
}