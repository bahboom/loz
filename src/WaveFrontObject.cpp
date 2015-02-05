#include "../inc/WaveFrontObject.h"

#include <string>
#include <iostream>
#include <fstream>
#include <vector>

#include "../inc/Logger.h"
#include "../inc/StringUtil.h"

Z::WaveFrontObject::WaveFrontObject( const char *objFile ) {
    std::ifstream wfoFile( objFile );

    if ( wfoFile.is_open() ) {
        while ( !wfoFile.eof() ) {
            std::string line;
            std::getline(wfoFile, line);

            std::vector<std::string> splitStr = Z::SplitString( line );
        
            if ( splitStr.empty() ) {
                continue; // Ignore empty lines.OB
            }
            
            if ( Z::StringStartsWith( splitStr.at( 0 ), "#" ) ) {
                // Comment. Do Nothing.
            } else if ( splitStr.at( 0 ) == "v" ) {
                std::cout << "Parsing vertex: " << line << std::endl;
            } else {
                std::cout << "Cannot parse line: " << line << std::endl;
            }
        }
        wfoFile.close();
    } else {
        Z_ERROR( "Can't open file: [" << objFile << "]!" );
    }

}
