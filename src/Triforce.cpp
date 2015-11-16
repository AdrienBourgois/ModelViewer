#include "Triforce.h"
#include "Shader.h"

namespace id
{
	Triforce::Triforce(Window* win)
	{
		SDL_Init(SDL_INIT_EVERYTHING);
		this->win = win;
	}

	Triforce::~Triforce()
	{
	}
	GLuint Triforce::loadShader(std::string const& name, GLint shader_type)
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

	        return vs_id;
	}
	GLuint Triforce::loadProgram()
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

	        return prg_id;
	}

	void Triforce::load()
	{
		this->vs_id = this->loadShader("triforce", GL_VERTEX_SHADER);
	        this->fs_id = this->loadShader("triforce", GL_FRAGMENT_SHADER);
        	this->prg_id = this->loadProgram();

//	        glUseProgram(this->prg_id);
	}
	void Triforce::update()
	{
		this->world = maths::Matrix4x4::rotateY(this->angle);
	        this->view = maths::Matrix4::translate(0.f, 0.f, 5.f).inverse();
        	this->proj = maths::Matrix4::perspective(rad(90.f), 1.f, 0.1f, 1000.f);
  	        this->angle += 1.f;
	}

	void Triforce::draw()
	{
		this->world_loc = glGetUniformLocation(this->getPrg(),"world");
	        this->view_loc = glGetUniformLocation(this->getPrg(), "view");
        	this->proj_loc = glGetUniformLocation(this->getPrg(), "proj");

	        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

        	glUniformMatrix4fv(this->world_loc, 1, GL_TRUE, this->world.val);
	        glUniformMatrix4fv(this->view_loc, 1, GL_TRUE, this->view.val);
        	glUniformMatrix4fv(this->proj_loc, 1, GL_TRUE, this->proj.val);

		glDrawArrays(GL_TRIANGLES, 0, 54);
	}
}
