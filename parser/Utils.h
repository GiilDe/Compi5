//
// Created by Miki Mints on 2019-06-17.
//

#ifndef COMPI5_UTILS_H
#define COMPI5_UTILS_H

#include <set>
#include <map>
#include <string>
#include <sstream>
#include "../parser.tab.hpp"
#include "../source.hpp"

using namespace std;

#define FOR_EACH(iter, ds, name) \
    for (ds::iterator iter = name.begin(); iter != name.end(); iter++)

#define FOR_EACH_CONST(iter, ds, name) \
    for (ds::const_iterator iter = name.begin(); iter != name.end(); iter++)


#define WRAP_ERROR(exp) \
    do { \
        exp; \
        exit(1); \
    } while (0)

class Utils {

    set<int> int_convertables;
    map<int, string> type_to_string;

public:

    Utils();

    /**
     * Checks whether an r-value type is assignable to an l-value type
     * @param assignee The l-value type
     * @param rvalue The r-value type
     * @return true is assignable, false otherwise
     */
    bool isAssignable(int assignee, int rvalue) const;

    const string& typeToString(int type) const;

    bool isNumber(const std::string& s) const;

    string intToString(int n) const;

};


#endif //COMPI5_UTILS_H
