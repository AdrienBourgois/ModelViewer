#include "shader.h"

namespace shader {

    GLuint loadShader(std::string const& name, GLint shader_type)
    {
        std::string filename = "assets/shader/";
        filename += name;
        if (shader_type == GL_VERTEX_SHADER)
            filename += "_vs.glsl";
        if (shader_type == GL_FRAGMENT_SHADER)
            filename += "_fs.glsl";

        std::string source_code;

        std::ifstream file;
        file.open(filename, std::ios::binary);
        SDL_assert(file.is_open());

        file.seekg (0, std::ios::end);
        auto file_len = file.tellg();
        file.seekg(0, std::ios::beg);

        source_code.resize(file_len);
        file.read(&source_code[0], file_len);
        file.close();

        auto vs_id = glCreateShader(shader_type);

        char const* c_source = source_code.c_str();
        int const source_len = source_code.size();
        glShaderSource(vs_id, 1, &c_source, &source_len);

        glCompileShader(vs_id);

        GLint status;
        glGetShaderiv(vs_id, GL_COMPILE_STATUS, &status);
        if (status == GL_FALSE)
        {
            GLint len;
            glGetShaderiv(vs_id, GL_INFO_LOG_LENGTH, &len);

            auto infolog = new char[len];
            glGetShaderInfoLog(vs_id, len, &len, infolog);
            std::cerr << "shader [" << filename << "] compile error : " << infolog << std::endl;
            SDL_assert(false);
        }
        else
            std::cout << "Shader [" << filename << "] compilation success" << std::endl;

        return vs_id;
    }

    GLuint loadProgram(GLuint vs_id, GLuint fs_id)
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

    GLuint makeAndUseProgram(std::string const& name)
    {
        auto vs_id = shader::loadShader(name, GL_VERTEX_SHADER);
        auto fs_id = shader::loadShader(name, GL_FRAGMENT_SHADER);
        auto prg_id = shader::loadProgram(vs_id, fs_id);

        glUseProgram(prg_id);

        return prg_id;
    }
}
