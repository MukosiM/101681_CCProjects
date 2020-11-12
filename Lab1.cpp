#include <iterator>
#include <iostream>
#include <string>
#include <regex>
#include <list>
#include <map>

using namespace std;

int main(){

    string str = " if while name = mukosi101";

    // define list of patterns
    map<string,string> patterns {
        { "[0-9]+" ,   "INTEGER" },
        { "[a-z]+" ,   "IDENTIFIER" },
        { "[=], [+], [*]",  "OPERATORS" },
        { "[if], [while],[for]", "KEYWORD" }
    };

    // storage for results
    map< size_t, pair<string,string> > matches;

    for ( auto pat = patterns.begin(); pat != patterns.end(); ++pat )
    {
        regex r(pat->first);
        auto words_begin = sregex_iterator( str.begin(), str.end(), r );
        auto words_end   = sregex_iterator();

        for ( auto it = words_begin; it != words_end; ++it )
            matches[ it->position() ] = make_pair( it->str(), pat->second );
    }

    for ( auto match = matches.begin(); match != matches.end(); ++match )
        cout<< match->second.first << " " << match->second.second << endl;
}
