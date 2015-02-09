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
        int v, 
            vt, vn; // Optional
    };


    class WaveFrontObject {
        public:
            WaveFrontObject( const char *objFile );
        private:
            Z::Vertex ParseVertex( const std::vector<std::string>& strs );
            Z::Normal ParseNormal();
            Z::TextureCoordinate ParseTextureCoordinate();
            Z::Face ParseFace();

            std::vector<Z::Vertex> vertices;
            std::vector<Z::Normal> normals;
            std::vector<TextureCoordinate> textureCoordinates;
            std::vector<Face> faces;
    };

}
#endif
