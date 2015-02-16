#ifndef Z_STRING_UTIL_H
#define Z_STRING_UTIL_H

#include <vector>
#include <string>

namespace Z {
    /**
     * Split string by whitespace.
     */
    std::vector<std::string> 
    Split( const std::string& str );

    std::vector<std::string> 
    Split( const std::string& str, const std::string &delimiter );

    bool 
    StartsWith( const std::string& str, const std::string &pattern );

    bool
    IsInteger( const std::string& str );

    bool
    IsDecimal( const std::string& str );

    std::string
    TrimHead( const std::string &str ); 

    std::string
    TrimTail( const std::string &str );
    
    std::string 
    Trim( const std::string &str );
}

#endif
