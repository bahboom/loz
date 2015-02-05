#ifndef WAVE_FRONT_OBJECT_H
#define WAVE_FRONT_OBJECT_H
namespace Z {
    struct Vertex {
        float x, y, z;
    };

    struct Face {
    };


    class WaveFrontObject {
        public:
            WaveFrontObject( const char *objFile );
    };

}
#endif
