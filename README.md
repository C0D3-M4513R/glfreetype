# glfreetype
Another OpenGL FreeType library

I needed to display text in OpenGL. Other libraries were simply too massive for my needs/there were no clear examples. I discovered FreeType and the following NeHe tutorial:

http://nehe.gamedev.net/tutorial/freetype_fonts_in_opengl/24001/

The repository here is basically a simple amalgamation of those ideas. The end result is that you can use arbitrary .ttf fonts, e.g. using Arial.ttf which on my mac is located under /Library/fonts/:

![Image of test example](https://github.com/C0D3-M4513R/glfreetype/blob/master/wintest.png)

Assuming a cmake build system, clone or submodule this repository into your source tree and add the following lines to your CMakeLists.txt file:

```
ADD_SUBDIRECTORY(glfreetype)
include_directories(glfreetype/include)
target_link_libraries(yourProjectName glfreetype)
```

This will add this Project as a dependency of your Project/Executable/Library.
If you use `add_subdirectory(glfreetype)`, the test binary won't be built!.

## Please check out the test binary (build from the source root with):

```
mkdir build
cd build
cmake ..
make
```
