#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <OpenGL/glu.h> // This might be Mac only.
#include <GLKit/GLKMatrix4.h>
#include <assert.h>

#include "../inc/Logger.h"
#include "../inc/WaveFrontObject.h"
#include "../inc/Renderer.h"

/**
 * All Legend of Z source code are in Z namespace.
 *
 * Conventions:
 *     Trying to not use "using".
 */
namespace Z {
    void 
    InitOpenGL( SDL_Window *window );
    
    void
    SetupLighting( void );
    
    /**
     * Cross platform gluPerspective function.
     */
    void 
    Perspective( float fovy, float aspect, float zNear, float zFar );
    
    void 
    Render( void );
   
    const std::string TITLE   = "Legend of Z";
    const float SCREEN_WIDTH  = 1024.0f;
    const float SCREEN_HEIGHT = 768.0f;

    static Z::Renderer *renderer = new Z::Renderer();
    static Z::WaveFrontObject *monkeyWfo = new Z::WaveFrontObject( "data/monkey.obj" );

}

void 
Z::InitOpenGL( SDL_Window *window ) {
	//SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 3 );
    //SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, 1 );

    SDL_GL_CreateContext( window );
    Z::SetupLighting();

    glEnable( GL_CULL_FACE );    

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();

    Z::Perspective( 45,
                    SCREEN_WIDTH / SCREEN_HEIGHT,
                    1.0,     // Near
                    500.0 ); // Far
    glTranslatef( 0, 0, -7 );
    
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();

}

void
Z::SetupLighting( void ) {
    glEnable( GL_LIGHTING );
    glEnable( GL_LIGHT0 );
    glEnable( GL_DEPTH_TEST );
    
    GLfloat specular[] = { 0.5, 0.5, 0.5, 1.0 };
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular );
    
    GLfloat ambient[] = { 0.2f, 0.2f, 0.2f, 1.0f};
    glLightfv( GL_LIGHT0, GL_AMBIENT, ambient );
    
    GLfloat diffuseLight[] = { 0.8f, 0.8f, 0.8f, 1.0f };
    glLightfv( GL_LIGHT0, GL_DIFFUSE, diffuseLight );
    
    GLfloat position[] = { -2, 1, 4, 1.0f };
    glLightfv( GL_LIGHT0, GL_POSITION, position );
   
    //glEnable( GL_FOG );
    glFogf( GL_FOG_DENSITY, 2 );
    glFogf( GL_FOG_MODE, GL_EXP );
    glFogf( GL_FOG_START, -10.0 );
    glFogf( GL_FOG_END, 12.0 );
}

void 
Z::Perspective( float fovy, float aspect, float zNear, float zFar ) {
#ifdef __APPLE__
    glMultMatrixf( GLKMatrix4MakePerspective( fovy, aspect, zNear, zFar ).m ); 
#else 
    gluPerspective( fovy,
                    aspect,
                    zNear, 
                    zFar ); 
#endif
}

void 
Z::Render( void ) {
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
     
    glRotatef( 1.0, 1.0, 0.4, 1.0 );
    renderer->RenderWaveFrontObject( monkeyWfo );
}

int
main( int argc, char **argv ) {
    SDL_Init( SDL_INIT_EVERYTHING );
	
    SDL_Window *window;
    window = SDL_CreateWindow( Z::TITLE.c_str(), 
                               SDL_WINDOWPOS_UNDEFINED, 
                               SDL_WINDOWPOS_UNDEFINED,
                               Z::SCREEN_WIDTH, 
                               Z::SCREEN_HEIGHT, 
                               SDL_WINDOW_OPENGL );

    Z::InitOpenGL( window );
	
    bool running = true;
    SDL_Event event;
    while ( running ) {
        while ( SDL_PollEvent( &event ) ) {
            switch ( event.type ) {

               case SDL_KEYDOWN: {
                    const Uint8 *state = SDL_GetKeyboardState( NULL );
                    if ( state[ SDL_SCANCODE_RETURN ] ) {
                        running = false;
                    }
                } break;

                case SDL_QUIT: {
                    running = false;
                } break;
            }
        }

        Z::Render(); 
		SDL_GL_SwapWindow( window );
		SDL_Delay( 30 );
    }

    SDL_DestroyWindow( window );
    SDL_Quit();

    return 0;
}


