#include "shader.h"

#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>

Shader::Shader(const std::string& vertexFilePath, const std::string& fragmentFilePath)
:   programId           (0)
{
    // Create relevant variables
    std::string vertexCode;
    std::string fragmentCode;

    std::ifstream vShaderFile;
    std::ifstream fShaderFile;

    // Get the ifstreams to explain when they cry if something doesn't go their way
    vShaderFile.exceptions(std::ifstream::badbit);
    fShaderFile.exceptions(std::ifstream::badbit);

    try {
        // open that shit up
        vShaderFile.open(vertexFilePath);
        fShaderFile.open(fragmentFilePath);
        std::stringstream vShaderStream, fShaderStream;

        // place buffer into stream
        vShaderStream << vShaderFile.rdbuf();
        fShaderStream << fShaderFile.rdbuf();

        // close handlers
        vShaderFile.close();
        fShaderFile.close();

        // convert those streams of tears into strings
        vertexCode = vShaderStream.str();
        fragmentCode = fShaderStream.str();

    } catch(std::ifstream::failure e) {
        std::cout << "Error: The shaders weren't loaded properly :(" << std::endl;
    }
 	const GLchar* vShaderCode = vertexCode.c_str();       // openGL takes in GLchar not std::string
    const GLchar* fShaderCode = fragmentCode.c_str();

 	/*giveToOpenGl(vertexShaderId, vertexSource);
 	//giveToOpenGl(fragmentShaderId, fragmentSource)

 	if (isError(vertexShaderId)) {
        std::cout << "WUT" << std::endl; // Not being called :(
        return;
 	}
 	if (isError(fragmentShaderId))
    {
        std::cout << "WUT" << std::endl;
        return;
    }*/

    // Define the variables
    GLuint vertex, fragment;
    GLint success;
    GLchar infoLog[512];

    // Compile vertex shader
    vertex = glCreateShader(GL_VERTEX_SHADER);          // Make vertex shader
    glShaderSource(vertex, 1, &vShaderCode, NULL);      // link the source code the the vertex ID together
    glCompileShader(vertex);                            // COMPILE THAT SHIT WOOOO
    glGetShaderiv(vertex, GL_COMPILE_STATUS, &success); // Find if the compilation went well, and set success according so

    if (!success) {
        glGetShaderInfoLog(vertex, 512, NULL, infoLog);                     // Generate error as infoLog
        std::cout << "Vertex Compilation Error: " << infoLog << std::endl;  // Display
    }

    // Compile fragment shader
    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fShaderCode, NULL);
    glCompileShader(fragment);
    glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);

    if (!success) {
        glGetShaderInfoLog(fragment, 512, NULL, infoLog);
        std::cout << "Fragment Compilation Error: " << infoLog << std::endl;
    }
//can i do something quick

    programId = glCreateProgram();

    glAttachShader( programId, vertex);
    glAttachShader( programId, fragment);
    glLinkProgram ( programId);

    glGetProgramiv(programId, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(programId, 512, NULL, infoLog);
        std::cout << "Shader Link Compilation Error: \n" << infoLog << std::endl;
    }

    glDetachShader(programId, vertexShaderId);
 	glDetachShader(programId, fragmentShaderId);
}

Shader::~Shader()
{
    glDeleteShader(vertexShaderId);
 	glDeleteShader(fragmentShaderId);
 	glDeleteProgram(programId);
}


std::string Shader::readShaderFile(const std::string filePath)
{
    std::string line;
 	std::string source;
 	std::fstream file(filePath);

 	if (file) {
        while(std::getline(file, line)) {
            source.append(line);
            source += "\n";
        }
 	}
    else {
        std::cerr << "Could not open " << filePath << " \n";
        return "";
    }
    file.close();
    return source;
}

void Shader::giveToOpenGl(GLuint& id, std::string& source)
{
    const char* sourceChar = source.c_str();
    glShaderSource(id, 1, &sourceChar, NULL);
    glCompileShader(id);
}

bool Shader::isError(GLuint& id)
{
    GLint result = GL_FALSE;
 	int infoLogLength;

 	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
 	glGetShaderiv(id, GL_INFO_LOG_LENGTH, &infoLogLength);
 	if ( infoLogLength > 0 ){

 		std::vector<char> errorMessage(infoLogLength+1);
 		glGetShaderInfoLog(id, infoLogLength, NULL, &errorMessage[0]);
 		std::cout << errorMessage[0] << std::endl;
 		return false;
 	}
 	else {
        return true;
 	}
}
