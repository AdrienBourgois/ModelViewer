TARGET = out

SRC = main.cpp \
	  maths/Matrix.cpp \
	  Device.cpp \
	  Shader.cpp \
	  Scene.cpp \
	  SceneNode.cpp \
	  Driver.cpp \
	  Window.cpp\
	  Mesh.cpp\
	  CameraSceneNode.cpp\
	  MeshSceneNode.cpp\


LIBS = SDL2 GL GLEW

BIN_DIR = bin/
OBJ_DIR = obj/
SRC_DIR = src/
INC_DIR = include/ /usr/include/SDL2/

OBJ = $(patsubst %.cpp,$(OBJ_DIR)%.o,$(SRC))
DEPENDENCIES = $(OBJ:.o=.d)
ARBO = $(sort $(dir $(DEPENDENCIES) $(OBJ_DIR)))
INCLUDES = $(addprefix -I,$(INC_DIR))
LIBRARIES = $(addprefix -l,$(LIBS))
CXXFLAGS = -MMD -W -Wall -Werror
LDFLAGS = -W -Wall -Werror
CXX = g++ -std=c++14

.PHONY: all clean fclean re

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
