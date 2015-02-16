#ifndef WAVE_FRONT_OBJECT_H
#define WAVE_FRONT_OBJECT_H

#include <vector>

namespace Z {
    struct Vertex {
        float x, y, z, 
              w; // Optional
    };

    struct Normal {
        float x, y, z;
    };

    struct TextureCoordinate {
        float u, v, 
              w; // Optional
    };

    struct Face {
        std::vector<int> vVec, 
                         vtVec, vnVec; // Optional
    };

    class WaveFrontObject {
        public:
            WaveFrontObject( const char *objFile );
            
            std::vector<Z::Vertex> 
            GetVertices( void ) const; // These methods does not modify this class.

            std::vector<Z::Normal>
            GetNormals( void ) const;
            
            std::vector<Z::Face> 
            GetFaces( void ) const;
            
            std::string 
            ToString( void ) const;
        private:
            static Z::Vertex 
            ParseVertex( const std::vector<std::string>& lineElements );
            
            static Z::Normal 
            ParseNormal( const std::vector<std::string>& lineElements );
            
            static Z::TextureCoordinate 
            ParseTextureCoordinate( const std::vector<std::string>& lineElements );
            
            static Z::Face 
            ParseFace( const std::vector<std::string>& lineElements );

            std::vector<Z::Vertex> vertices;
            std::vector<Z::Normal> normals;
            std::vector<TextureCoordinate> textureCoordinates;
            std::vector<Face> faces;
    };

}
#endif
