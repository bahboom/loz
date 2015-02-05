#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <GL/glu.h>

#include "../inc/WaveFrontObject.h"

#define TITLE         "Legend of Z"
#define SCREEN_WIDTH  1024.0f
#define SCREEN_HEIGHT 768.0f


/**
 * All Legend of Z source code are in Z namespace.
 */
namespace Z {
    void InitOpenGL( SDL_Window *window );
    void Render( void );
}

void Z::InitOpenGL( SDL_Window *window ) {
	//SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 3 );
    //SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, 1 );

    SDL_GL_CreateContext( window );
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();

    // TODO: Deprecated.
    gluPerspective( 45,
                    SCREEN_WIDTH / SCREEN_HEIGHT,
                    1.0,     // Near
                    500.0 ); // Far
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();

    Z::WaveFrontObject *monkeyWfo = new Z::WaveFrontObject( "data/monkey.obj" );

}

void Z::Render( void ) {
    glClear( GL_COLOR_BUFFER_BIT );
    glRotatef( 1.0, 0.0, 0.0, 1.0 );
    glBegin( GL_TRIANGLES );
        glColor3f( 1.0, 0, 0 );
        glVertex3f( 0.0, 2.0, -50.0 );
        glColor3f ( 0, 1.0, 0 );
        glVertex3f( -2.0, -2.0, -50.0 );
        glColor3f( 0, 0, 1.0 );
        glVertex3f( 2.0, -2.0, -50.0 );
    glEnd();
}

int main(int argc, char **argv) {
    SDL_Init( SDL_INIT_EVERYTHING );
	
    SDL_Window *window;
    window = SDL_CreateWindow( TITLE, 
                               SDL_WINDOWPOS_UNDEFINED, 
                               SDL_WINDOWPOS_UNDEFINED,
                               SCREEN_WIDTH, 
                               SCREEN_HEIGHT, 
                               SDL_WINDOW_OPENGL );

    Z::InitOpenGL( window );
	
    bool running = true;
    SDL_Event event;
    while ( running ) {
        while ( SDL_PollEvent( &event ) ) {
            switch ( event.type ) {
                case SDL_QUIT:
                    running = false;
                    break;
            }
        }
        Z::Render(); 
		SDL_GL_SwapWindow( window );
		SDL_Delay( 33 );
    }

    SDL_DestroyWindow( window );
    SDL_Quit();

    return 0;
}
