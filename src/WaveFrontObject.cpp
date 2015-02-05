#include "../inc/WaveFrontObject.h"

#include <string>
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
                //Z_INFO( "Parsing vertex: " << line );
            } else if ( splitStr.at( 0 ) == "vn" ) {
            
            } else {
                Z_WARN( "Cannot parse line: " << line ); 
            }
        }
        wfoFile.close();
    } else {
        Z_ERROR( "Can't open file: [" << objFile << "]!" );
    }

}
