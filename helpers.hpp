// Lucas Saldyt
// 1213399809
// 6:00pm M/W class
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector> // Instructions did not say if this was allowed. So, I'm assuming it is.

using std::string;
using std::vector;

// Shorthand for printing any type
template <typename T>
void print(T t) 
{
    std::cout << t << "\n"; // Don't flush
}

// Printing for any type w/ multiple arguments.. fancy stuff :) - LSaldyt
template <typename T, typename... Args>
void print(T first, Args... args) 
{
    print(first);
    print(args...);
    //std::cout << "\n"; // Don't flush
}

// Read the rows (lines) of a file into a std::vector of std::strings. 
// Very clean, but I recognize that this would be memory-inefficient for a large amount of data.
// If the assignment mentioned processing large files, I would open the file in chunks.
vector<string> readFile(string filename)
{
    vector<string> content; // Vector of lines

    std::ifstream infile(filename.c_str());
    //print("Input file open");
    string line;
    while (getline(infile, line)) // Implicitly by \n characters
    {
        content.push_back(line);
    }
    infile.close();
    //print("input file closed");

    return content;
}

// Write lines into a given filename, more or less safely
// Very clean, but I recognize that this would be memory-inefficient for a large amount of data.
// If the assignment mentioned processing large files, I would open the file in chunks.
void writeFile(vector<string> content, string filename)
{
    std::ofstream file;
    file.open(filename.c_str());
    //print("Output file open");
    for (string line : content)
    {
        file << (line + "\n");
    }
    file.close();
    //print("Output file closed");
}
