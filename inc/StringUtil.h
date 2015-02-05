#ifndef Z_STRING_UTIL_H
#define Z_STRING_UTIL_H

#include <vector>
#include <string>

namespace Z {
    /**
     * Split string by whitespace.
     */
    std::vector<std::string> 
    SplitString( const std::string &str );

    bool 
    StringStartsWith( const std::string &str, const std::string &pattern );

    std::string
    TrimStringHead( const std::string &str ); 

    std::string
    TrimStringTail( const std::string &str );
    
    std::string 
    TrimString ( const std::string &str );
}

#endif
