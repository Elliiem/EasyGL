#include "EGL.h"

void PrintSError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage){
    GLint success = 0;
    GLchar error[1024] = { 0 };

    if(isProgram)
        glGetProgramiv(shader, flag, &success);
    else
        glGetShaderiv(shader, flag, &success);

    if(success == GL_FALSE)
    {
        if(isProgram)
            glGetProgramInfoLog(shader, sizeof(error), NULL, error);
        else
            glGetShaderInfoLog(shader, sizeof(error), NULL, error);

        std::cerr << errorMessage << ": '" << error << "'" << std::endl;
    }
}

std::string LoadShader(const std::string& fileName){
    std::ifstream file;
    file.open(fileName.c_str());

    std::string output;
    std::string line;

    if(file.is_open())
    {
        while(file.good())
        {
            getline(file, line);
            output.append(line + "\n");
        }
    }
    else
    {
        std::cerr << "Unable to load shader: " << fileName << std::endl;
    }
    return output;
}

GLuint CreateShader(const std::string& code,GLenum shaderType){
    GLuint shader = glCreateShader(shaderType);

    if(shader == 0)
    {
        std::cerr << "Error: shader creation failed" << std::endl;
    }

    const GLchar* shader_source_strings[1];
    GLint shader_source_string_lengths[1];

    shader_source_strings[0] = code.data();
    shader_source_string_lengths[0] = code.length();

    glShaderSource(shader, 1, shader_source_strings, shader_source_string_lengths);
    glCompileShader(shader);

    PrintSError(shader,GL_COMPILE_STATUS, false, "Error: shader compiling has failed");

    return shader;
}


EGL_Shader::EGL_Shader(const std::string& file_name)
{
    program = glCreateProgram();
    shaders[0] = CreateShader(LoadShader(file_name + ".vs"), GL_VERTEX_SHADER);
    shaders[1] = CreateShader(LoadShader(file_name + ".fs"), GL_FRAGMENT_SHADER);

    for(uint8_t i = 0;i<NUM_SHADERS;i++)
        glAttachShader(program, shaders[i]);

    glBindAttribLocation(program,0,"pos");

    glLinkProgram(program);
    PrintSError(program,GL_LINK_STATUS,true,"Error: Program linking failed");

    glValidateProgram(program);
    PrintSError(program,GL_VALIDATE_STATUS,true,"Error: Program linking failed");
}

EGL_Shader::~EGL_Shader()
{
    for(uint8_t i = 0;i<NUM_SHADERS;i++)
    {
        glDetachShader(program,shaders[i]);
        glDeleteShader(shaders[i]);
    }

    glDeleteProgram(program);
}

void EGL_Shader::Bind()
{
    glUseProgram(program);
}