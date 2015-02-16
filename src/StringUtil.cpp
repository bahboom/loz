#include "../inc/StringUtil.h"

#include <cctype>

std::vector<std::string> 
Z::Split( const std::string& str ) {
    std::vector<std::string> results;
    std::string trimmedStr = Z::Trim( str );
    int elementFoundAt = 0;

    for ( int i = 0; i < trimmedStr.length(); i++ ) {

        if ( isspace( str.at( i ) )  ) {
            results.push_back( str.substr( elementFoundAt, i - elementFoundAt ) );
            elementFoundAt = i + 1; 
         }
    }

    if ( elementFoundAt < trimmedStr.length() ) {
        results.push_back( trimmedStr.substr( elementFoundAt, trimmedStr.length() ) );
    } 
    return results;
}

std::vector<std::string> 
Z::Split( const std::string& str, const std::string& delimiter ) {
    std::vector<std::string> results;
    
    int elementFoundAt = 0; // Finding first element is easy.

    for ( int i = 0; i < str.length(); i++ ) {
        if ( str.substr( i, delimiter.length() ) == delimiter ) {
            results.push_back( str.substr( elementFoundAt, i - elementFoundAt ) );
            elementFoundAt = i + delimiter.length();
            i += delimiter.length() - 1; // We can skip testing up to the length of the delimiter.
        }
    }

    if ( elementFoundAt < str.length() ) 
        results.push_back( str.substr( elementFoundAt, str.length() ) );
    return results;
}

bool 
Z::StartsWith( const std::string& str, const std::string& pattern ) {
    return str.substr( 0, pattern.length() ) == pattern;
}

bool
Z::IsInteger( const std::string& str ) {
    const std::string trimmedStr = Z::Trim( str );
    if ( trimmedStr == "" ) {
        return false;
    }

    for ( int i = 0; i < trimmedStr.length(); i++ ) {
        if ( !isdigit( trimmedStr.at( i ) ) ) 
            return false;
    }
    return true;
}

bool
Z::IsDecimal( const std::string& str ) {
    if ( Z::Trim( str ) == "" ) {
        return false;
    }

    bool foundDecimal = false;

    for ( std::string::const_iterator it = str.cbegin(); it != str.cend(); it++ ) {
        if ( isdigit( *it ) ) {
            if ( *it == '.' ) {
                if ( !foundDecimal ) {
                    foundDecimal = true;
                } else {
                    return false; // Found more than 1 decimals.
                }
            } else {
                return false; // Not a digit nor a decimal.
            }
        } 
    }

    return true;
}

std::string
Z::TrimHead( const std::string& str ) {
    for ( int i = 0; i <= str.length(); i++ ) {
        if ( i == str.length() ) { // This whole string contains only whitespace.
            return "";
        }
        if ( !isspace( str.at( i ) ) ) {
            return str.substr( i, str.length() ); // Get string starting from index i to the end of the the string.
        }
    }
    return str;
}


std::string
Z::TrimTail( const std::string &str ) {
    for ( int i = str.length() - 1; i >= -1; i-- ) {
        
        if ( i == -1 ) { // This whole string contains only whitespace.
            return "";
        }

        if ( !isspace( str.at( i ) ) ) {
            return str.substr( 0, i + 1 );
        }
    }
    
    return str;
}

std::string 
Z::Trim( const std::string &str ) {
    return Z::TrimHead( Z::TrimTail( str ) );
}

