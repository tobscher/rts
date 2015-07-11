#ifndef DIOPTRE_GRAPHICS_OPENGL_ERROR_H_
#define DIOPTRE_GRAPHICS_OPENGL_ERROR_H_

#include <string>
#include <iostream>

using std::string;
using std::cerr;
using std::endl;

void _check_gl_error(const char *file, int line);

#define check_gl_error() _check_gl_error(__FILE__, __LINE__)

#endif // DIOPTRE_GRAPHICS_OPENGL_ERROR_H_

