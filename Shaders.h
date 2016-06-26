#ifndef SHADERS_H
#define SHADERS_H

#include <GL/glew.h>

#include <iostream>
using namespace std;

class Shaders
{
    public:
        Shaders();
        ~Shaders();
        void compileShaders(const string&, const string&);
        void linkShaders();

    private:
        GLuint programID;
        GLuint vertexShaderID;
        GLuint fragmentShaderID;
};

#endif // SHADERS_H
