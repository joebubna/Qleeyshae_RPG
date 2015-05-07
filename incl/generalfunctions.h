// File generalFunctions.h
#ifndef GENERALFUNCTIONS_H
#define GENERALFUNCTIONS_H

#include <string>
#include <cctype>
#include <vector>

using namespace std;

void explode(string str, string delim, vector<string> &results);

// Striping whitespace throughout a string
string stripSpace( string str );

// Removes leading and trailing whitespace
string trim( string str );
string ltrim( string str );
string rtrim( string str );

// Makes first character uppercase
string str_first_to_upper( string );

// Takes a string and splits it into a new line at a given length.
// Is careful not to split the middle of a word.
string strWrap( string str, int maxLen );

#endif
