#include "../inc/StringUtil.h"

#include <cctype>

std::vector<std::string> 
Z::SplitString( const std::string &str ) {
    std::vector<std::string> results;
    
    int elementFoundAt = -1;

    for ( int i = 0; i < str.length(); i++ ) {
        if ( elementFoundAt == -1 ) {
            // Look for starting index (elementFoundAt).
            if ( !isspace( str.at( i ) ) ) {
                elementFoundAt = i;
            }

        } else { // Found starting index (elementFoundAt). 
            if ( isspace( str.at( i ) ) || i == str.length() - 1 ) {
                results.push_back( str.substr( elementFoundAt, i - elementFoundAt ) );
                elementFoundAt = -1; // Reset.
            }
        }
    }

    if ( elementFoundAt != -1 ) {
        results.push_back( str.substr( elementFoundAt, str.length() ) );
    } 
    return results;
}
std::vector<std::string> 
Z::SplitString( const std::string &str, const std::string &delimiter ) {
    std::vector<std::string> results;
    
    int elementFoundAt = -1;

    for ( int i = 0; i < str.length(); i++ ) {
        if ( elementFoundAt == -1 ) {
            // Look for starting index (elementFoundAt).
            if ( str.substr( i, delimiter.length() ) != delimiter ) {
                elementFoundAt = i;
            }

        } else { // Found starting index (elementFoundAt). 
            if ( str.substr( i, delimiter.length() ) == delimiter || i == str.length() - 1 ) {
                results.push_back( str.substr( elementFoundAt, i - elementFoundAt ) );
                elementFoundAt = -1; // Reset.
            }
        }
    }

    if ( elementFoundAt != -1 ) {
        results.push_back( str.substr( elementFoundAt, str.length() ) );
    } 
    return results;
}


bool 
Z::StringStartsWith( const std::string &str, const std::string &pattern ) {
    return str.substr( 0, pattern.length() ) == pattern;
}

std::string
Z::TrimStringHead( const std::string &str ) {
    for ( int i = 0; i <= str.length(); i++ ) {
        if ( i == str.length() ) { // This whole string contains only whitespace.
            return "";
        }
        if ( !isspace( str.at( i ) ) ) {
            return str.substr( i, str.length() - i );
        }
    }
    return str;
}


std::string
Z::TrimStringTail( const std::string &str ) {
    for ( int i = str.length() - 1; i >= -1; i-- ) {
        
        if ( i == -1 ) { // This whole string contains only whitespace.
            return "";
        }

        if ( !isspace( str.at( i ) ) ) {
            return str.substr( 0, i );
        }
    }
    
    return str;
}

std::string 
Z::TrimString( const std::string &str ) {
    return Z::TrimStringHead( Z::TrimStringTail( str ) );
}

