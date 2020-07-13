#pragma once
#if defined(__APPLE__)
#include <OpenGL/gl.h>
#else//__APPLE__
#include <GL/gl.h>
#endif//__APPLE__
#include <string>
#include <vector>
namespace glfreetype {

    // NEHE tutorial

    // This Holds All Of The Information Related To Any
    // FreeType Font That We Want To Create. 
    struct font_data {
        float h;                      // Holds The Height Of The Font.
        std::vector<GLuint> textures; // Holds The Texture Id's
        GLuint list_base;             // Holds The First Display List Id
        bool hasInit=false;

        // The Init Function Will Create A Font With
        // The Height h From The File fname.
        void init(const char * fname, unsigned int h);

        // Free All The Resources Associated With The Font.
        void clean();
    };

    // The Flagship Function Of The Library - This Thing Will Print
    // Out Text At Window Coordinates X, Y, Using The Font ft_font.
    // The Current Modelview Matrix Will Also Be Applied To The Text.
    void print(font_data const & ft_font, float x, float y,  
               std::string const & text);

}