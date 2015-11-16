#include "Shader.h"
#include <fstream>
#include <new>

namespace id
{
	Shader::Shader()
	{
	}
	Shader::~Shader()
	{
	}
	GLint Shader::loadShader(std::string const& name, GLint shader_type)
	{
		std::string filename("./assets/shader/"+ name);
        	if (shader_type == GL_VERTEX_SHADER)
                	filename += "_vs.glsl";

        	else
                	filename += "_fs.glsl";

	        std::ifstream file;
	        std::string source_code;
	        file.open(filename, std::ios::binary);
	        SDL_assert(file.is_open());

        	file.seekg(0, std::ios::end);
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

	                auto infolog = new char [len];
        	        glGetShaderInfoLog(vs_id, len , &len, infolog);
                	std::cerr << "Shader [ "<< filename <<"] compile error: " << infolog <<std::endl;
	                SDL_assert(false);
        	}
	        else
        	        std::cout << "Shader [ " << filename <<" ] compilation success " << std::endl;
		SDL_assert(vs_id);
        	return vs_id;
	}

	void Shader::loadProgram()
	{
		auto prg_id = glCreateProgram();

        	glAttachShader(prg_id, this->vs_id);
	        glAttachShader(prg_id, this->fs_id);
        	glLinkProgram(prg_id);

	        GLint status;
        	glGetProgramiv(prg_id, GL_LINK_STATUS, &status);

	       if (status == GL_FALSE)
	        {
                	GLint len;
        	        glGetShaderiv(prg_id, GL_INFO_LOG_LENGTH, &len);
	
	                auto infolog = new char [len];
        	        glGetProgramInfoLog(prg_id, len , &len, infolog);
	                std::cerr << "Program link error: " << infolog <<std::endl;
                	SDL_assert(false);
        	}
	        else
                	std::cout << "Program linkage success " << std::endl;

        	glDetachShader(prg_id, this->vs_id);
	        glDetachShader(prg_id, this->fs_id);
        	glDeleteShader(this->vs_id);
	        glDeleteShader(this->fs_id);
		SDL_assert(prg_id);
        	this->prg_id = prg_id;
	}
	
	void Shader::load_model()
	{
		this->vs_id = loadShader("simple", GL_VERTEX_SHADER);
        	this->fs_id = loadShader("simple", GL_FRAGMENT_SHADER);
	        this->loadProgram();
		std::cout<<prg_id<<std::endl;
	}
}
