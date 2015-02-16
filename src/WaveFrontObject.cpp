#include "../inc/WaveFrontObject.h"

#include <string>
#include <fstream>
#include <vector>
#include <assert.h>

#include "../inc/Logger.h"
#include "../inc/StringUtil.h"

Z::WaveFrontObject::WaveFrontObject( const char* objFile ) {

    std::ifstream wfoFile( objFile );

    if ( wfoFile.is_open() ) {
        while ( !wfoFile.eof() ) {
            std::string line;
            std::getline(wfoFile, line);

            std::vector<std::string> lineElements = Z::Split( line );
           

            if ( lineElements.empty() ) {
                continue; // Ignore empty lines.
            }
           
            std::string cmdStr = lineElements.at( 0 );
            if ( Z::StartsWith( cmdStr, "#" ) ) {
                // Comment. Do Nothing.
            } else if ( cmdStr == "v" ) {
                vertices.push_back( Z::WaveFrontObject::ParseVertex( lineElements ) );
            } else if ( cmdStr == "vn" ) {
                normals.push_back( Z::WaveFrontObject::ParseNormal( lineElements ) );
            } else if ( cmdStr == "f" ) {
                faces.push_back( Z::WaveFrontObject::ParseFace( lineElements ) );
            } else {
//                Z_WARN( "Cannot parse line: " << line ); 
            }
        }

        Z_INFO( "Loaded " << vertices.size() << " vertices!" );
        Z_INFO( "Loaded " << normals.size() << " normals!" );
         
        wfoFile.close();
    } else {
        Z_ERROR( "Can't open file: [" << objFile << "]!" );
    }
}

Z::Vertex 
Z::WaveFrontObject::ParseVertex( const std::vector<std::string>& lineElements ) {
    Z::Vertex v = { std::stof( lineElements.at( 1 ) ),
                    std::stof( lineElements.at( 2 ) ), 
                    std::stof( lineElements.at( 3 ) )  };
    
    if ( lineElements.size() >= 5 ) 
        v.w = std::stof( lineElements.at( 4 ) );
    
    return v;
}

Z::Normal 
Z::WaveFrontObject::ParseNormal( const std::vector<std::string>& lineElements ) {
    Z::Normal n = { std::stof( lineElements.at( 1 ) ),
                    std::stof( lineElements.at( 2 ) ), 
                    std::stof( lineElements.at( 3 ) )  };

    return n;
}


Z::Face 
Z::WaveFrontObject::ParseFace( const std::vector<std::string>& lineElements ) {
    Z::Face face;
    assert( lineElements.size() >= 4 );
    for ( int i = 1; i < lineElements.size(); i++ ) {
        std::vector<std::string> faceComponents = Z::Split( lineElements.at( i ), "/" );
        int numComponents = faceComponents.size();
        std::string vStr = numComponents  >= 1 ? faceComponents.at( 0 ) : "", 
                    vtStr = numComponents >= 2 ? faceComponents.at( 1 ) : "", 
                    vnStr = numComponents >= 3 ? faceComponents.at( 2 ) : "";

        if ( Z::IsInteger( vStr ) ) 
            face.vVec.push_back( std::stoi( vStr ) ); 
        if ( Z::IsInteger( vtStr ) )
            face.vtVec.push_back( std::stoi( vtStr ) );
        if ( Z::IsInteger( vnStr ) )
            face.vnVec.push_back( std::stoi( vnStr ) );
    }
 
    return face;
}

std::vector<Z::Vertex> 
Z::WaveFrontObject::GetVertices( void ) const {
    return vertices;
}

std::vector<Z::Normal>
Z::WaveFrontObject::GetNormals( void ) const {
    return normals;
}

std::vector<Z::Face> 
Z::WaveFrontObject::GetFaces( void ) const {
    return faces;
}


