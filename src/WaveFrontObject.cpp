#include "../inc/WaveFrontObject.h"

#include <string>
#include <fstream>
#include <vector>

#include "../inc/Logger.h"
#include "../inc/StringUtil.h"

Z::WaveFrontObject::WaveFrontObject( const char* objFile ) {

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
                Z::Vertex v = { std::stof( splitStr.at( 1 ) ),
                                std::stof( splitStr.at( 2 ) ), 
                                std::stof( splitStr.at( 3 ) )  };

                vertices.push_back( v );
            } else if ( splitStr.at( 0 ) == "vn" ) {
                Z::Normal vn = { std::stof( splitStr.at( 1 ) ),
                                 std::stof( splitStr.at( 2 ) ), 
                                 std::stof( splitStr.at( 3 ) )  };

                normals.push_back( vn );
            } else if ( splitStr.at( 0 ) == "f" ) {
                //Z_INFO( Z::SplitString( splitStr.at( 1 ), "/" ).at( 0 ) );
            } else {
                Z_WARN( "Cannot parse line: " << line ); 
            }
        }

        Z_INFO( "Loaded " << vertices.size() << " vertices!" );
        Z_INFO( "Loaded " << normals.size() << " normals!" );
         
        wfoFile.close();
    } else {
        Z_ERROR( "Can't open file: [" << objFile << "]!" );
    }

}

Z::Vertex Z::WaveFrontObject::ParseVertex( const std::vector<std::string>& strs ) {
    Vertex v;
    return v;
}
