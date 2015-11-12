#include "Shader.h"

namespace id {

Shader::Shader(std::string const& name)
{
    vs_id = loadShader(name,GL_VERTEX_SHADER);
    SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION,"vs_id");
    fs_id = loadShader(name,GL_FRAGMENT_SHADER);
    prg_id = loadProgram();
}

GLint Shader::loadShader(std::string const& name, GLint shader_type)
    {
        std::string path;
        if (shader_type == GL_VERTEX_SHADER)
            path = "./assets/shader/" + name + "_vs.glsl";
        if (shader_type == GL_FRAGMENT_SHADER)
            path = "./assets/shader/" + name + "_fs.glsl";
        std::string source_code;
        std::ifstream file;
        file.open(path, std::ios::binary);
        SDL_assert(file.is_open());

    SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION,"file open");
        file.seekg (0, std::ios::end);
        auto file_len = file.tellg();
        file.seekg(0, std::ios::beg);
        source_code.resize(file_len);
        file.read(&source_code[0], file_len);
        file.close();

    SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION,"file close");
        auto vs_id = glCreateShader(shader_type);

    SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION,"shader create");
        char const* c_source = source_code.c_str();
        int const source_len = source_code.size();

    SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION,"var insantiate");
        glShaderSource(vs_id, 1, &c_source, &source_len);
        glCompileShader(vs_id);

    SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION,"shader compil");
        GLint status;
        glGetShaderiv(vs_id, GL_COMPILE_STATUS, &status);
        if (status == GL_FALSE)
        {
            GLint len;
            glGetShaderiv(vs_id, GL_INFO_LOG_LENGTH, &len);

            auto infolog = new char[len];
            glGetShaderInfoLog(vs_id, len, &len, infolog);
            std::cerr << "shader [" << path << "] compile error : " << infolog << std::endl;
            SDL_assert(false);
        }
        else
            std::cout << "Shader [" << path << "] compilation success" << std::endl;

        return vs_id;
    }

GLint Shader::loadProgram()
    {
        auto prg_id = glCreateProgram();

        glAttachShader(prg_id, vs_id);
        glAttachShader(prg_id, fs_id);

        glLinkProgram(prg_id);

        GLint status;
        glGetProgramiv(prg_id, GL_LINK_STATUS, &status);
        if (status == GL_FALSE)
        {
            GLint len;
            glGetProgramiv(prg_id, GL_INFO_LOG_LENGTH, &len);

            auto infolog = new char[len];
            glGetProgramInfoLog(prg_id, len, &len, infolog);
            std::cerr << "Program link error : " << infolog << std::endl;
            SDL_assert(false);
        }
        else
            std::cout << "Program linkage success" << std::endl;

        glDetachShader(prg_id, vs_id);
        glDetachShader(prg_id, fs_id);

        glDeleteShader(vs_id);
        glDeleteShader(fs_id);

        return prg_id;
    }

    GLint Shader::locate(std::string const& name)
    {
        GLint loc = glGetUniformLocation(prg_id,name.c_str());
        SDL_assert(loc >= 0);
        return loc;
    }


    /*GLint makeAndUseProgram(std::string const& name)
    {
        auto vs_id = loadShader(name, GL_VERTEX_SHADER);
        auto fs_id = loadShader(name, GL_FRAGMENT_SHADER);
        auto prg_id = loadProgram();

        glUseProgram(prg_id);

        return prg_id;
    }*/
}
