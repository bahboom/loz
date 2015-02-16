#include "../inc/Renderer.h"

#include <OpenGL/GL.h>
#include <assert.h>

#include "../inc/Logger.h"

void 
Z::Renderer::RenderWaveFrontObject( Z::WaveFrontObject* wfo ) {
    std::vector<Z::Face> faces = wfo->GetFaces();
    std::vector<Z::Vertex> vertices = wfo->GetVertices();
    std::vector<Z::Normal> normals = wfo->GetNormals();

    for ( std::vector<Z::Face>::iterator it = faces.begin(); it != faces.end(); it++ ) {
        std::vector<int> vVec = it->vVec;
        std::vector<int> vnVec = it->vnVec;
        int numVertices = vVec.size();

        // NOTE: TODO: Probably not the most efficent to set Shape on every face!
        assert( numVertices >= 3 );
        if ( numVertices < 3 ) {
            Z_WARN ( "Unable to draw Face with less than 3 vertices!" );
            continue;
        } else if ( numVertices == 3 ) {
            glBegin( GL_TRIANGLES );
        } else if ( numVertices == 4 ) {
            glBegin( GL_QUADS );
        } else {
            glBegin( GL_POLYGON );
        }

        for ( int i = 0; i < numVertices; i++ ) {
            Z::Vertex vertex = vertices.at( vVec.at( i ) - 1 ); // Wavefront index starts from 1, our index starts from 0.
            Z::Normal normal = normals.at( vnVec.at( i ) - 1 );
            glNormal3f( normal.x, normal.y, normal.z );
            glVertex3f( vertex.x, vertex.y, vertex.z );
        }

        glEnd();
    }
}


