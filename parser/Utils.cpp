//
// Created by Miki Mints on 2019-06-17.
//

#include "Utils.h"

bool Utils::isAssignable(int assignee, int rvalue) const {
    return assignee == rvalue || (assignee == INT && (int_convertables.find(rvalue) != int_convertables.end()));
}

Utils::Utils() {
    // Initialize type conversion map
    int_convertables.insert(INT);
    int_convertables.insert(BYTE);
    int_convertables.insert(NUM);

    // Initialize type->string converter
    type_to_string.insert(pair<int, string>(VOID, "VOID"));
    type_to_string.insert(pair<int, string>(INT, "INT"));
    type_to_string.insert(pair<int, string>(BOOL, "BOOL"));
    type_to_string.insert(pair<int, string>(BYTE, "BYTE"));
    type_to_string.insert(pair<int, string>(STRING, "STRING"));
}

const string &Utils::typeToString(int type) const {
    return type_to_string.at(type);
}

bool Utils::isNumber(const std::string& s) const {
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

string Utils::intToString(int n) const {
    stringstream s;
    s << n;
    return s.str();
}
