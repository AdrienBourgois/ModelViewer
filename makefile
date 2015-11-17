TARGET = out

SRC = main.cpp \
	System.cpp\
	Device.cpp\
	Window.cpp\
	SceneManager.cpp\
	maths/Matrix.cpp\
	maths/tools.cpp\
	Vector.cpp\
	Material.cpp\
	MeshObj.cpp\
	Triforce.cpp\
	Shader.cpp\
	Driver.cpp\
	Parser_JSON.cpp\
	Parseur.cpp\
	Log.cpp\
	ImGuiImpl.cpp\
	imgui.cpp\
	imgui_draw.cpp\

LIBS = SDL2 SDL2_image GL GLEW GLU  

BIN_DIR = bin/
OBJ_DIR = obj/
SRC_DIR = src/
INC_DIR = include/ /usr/include/SDL2/

OBJ = $(patsubst %.cpp,$(OBJ_DIR)%.o,$(SRC))
DEPENDENCIES = $(OBJ:.o=.d)
ARBO = $(sort $(dir $(DEPENDENCIES) $(OBJ_DIR)))
INCLUDES = $(addprefix -I,$(INC_DIR))
LIBRARIES = $(addprefix -l,$(LIBS))
CXXFLAGS = -MMD -W -Wall -Werror -g3
LDFLAGS = -W -Wall -Werror -g3
CXX = g++ -std=c++14

.PHONY: all clean fclean re

release: CXXFLAGS += -O3
release: LDFLAGS += -O3
release: all

debug: CXXFLAGS += -O0 -g3
debug: LDFLAGS += -O0 -g3
debug: all

all: $(TARGET)

$(TARGET): $(BIN_DIR)$(TARGET) | $(ARBO)

$(BIN_DIR)$(TARGET): $(OBJ) | $(BIN_DIR)
	$(CXX) $(LDFLAGS) -o $@ $(OBJ) $(LIBRARIES)

$(OBJ): | $(ARBO)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(ARBO):
	mkdir -p $@

-include $(DEPENDENCIES)

clean:
	$(RM) $(OBJ)
	$(RM) $(DEPENDENCIES)
	$(RM) -r $(ARBO)
	$(RM) .*.swp

fclean: clean
	$(RM) $(TARGET)

re: fclean all

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $< $(INCLUDES)
