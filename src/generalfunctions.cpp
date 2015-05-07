#include "../incl/generalfunctions.h"

void explode(string str, string delim, vector<string> &results) {
    int cutAt;
    while( (cutAt = str.find_first_of(delim)) != str.npos ) {
        if(cutAt > 0) {
            results.push_back(str.substr(0,cutAt));
        }
        str = str.substr(cutAt+1);
    }
    if(str.length() > 0) {
        results.push_back(str);
    }
}


string stripSpace( string str ) {
    for (int i = 0; i < str.length(); i++) {
        if (str.at(i) == ' ') {
            str.erase(i, 1);
            i--;   
        }
    }
    return str;   
}

string trim( string str ) {
    str = ltrim( str );
    str = rtrim( str );
    return str;   
}

string ltrim( string str ) {
    while (str.length() > 0) {
        if (str.at(0) == ' ') {
            str.erase(0, 1);       
        }
        else {
            break;
        }
    }
    return str;   
}

string rtrim( string str ) {
    while (str.length() > 0) {
        int end = str.length() - 1;
        if (str.at(end) == ' ') {
            str.erase(end, 1);               
        }
        else {
            break; // Stop for non-space
        }  
    }   
    return str;
}

string str_first_to_upper( string sent ) {
    if (sent.at(0) >= 'a' && sent.at(0) <= 'z') {
        sent.at(0) = toupper(sent.at(0));
    }
    return sent;
}

string strWrap( string str, int maxLen ) {
    int offset = 0;
    int scan = 0;
    int seeker = scan;
    int currInterval = 0;
    
    if (str.size() < maxLen) {
        return str;
    }
    else {      
        while( str.length() - offset > maxLen && scan < str.size() ) {
            if (str[seeker] != '\n') {
                if (currInterval == maxLen) {
                    while (isspace(str[seeker]) == false && seeker >= 0 ) {
                        seeker--;
                    }
                    //str[seeker] = '\n';
                    str.replace(seeker, 1, "\n");
                    offset = seeker;
                }
            }
            else {
                offset = seeker;
            }
            scan++;
            seeker = scan;
            currInterval = scan - offset;
        }
        return str;
    }
}
