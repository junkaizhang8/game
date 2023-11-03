APP = Main
COMPILER = g++
INCLUDE_PATHS = -I include
FRAMEWORKS = -framework Cocoa -framework OpenGL -framework IOKit
LIBRARY_PATHS = -L lib/GLFW
LINKER_FLAGS = -l glfw3
COMPILER_FLAGS = -std=c++11 -Wall -O0 -g -Wno-deprecated-declarations
CPP_FILES = $(wildcard src/*.cpp)
HPP_FILES = $(wildcard src/*.hpp)

$(APP): $(CPP_FILES) $(HPP_FILES)
	$(COMPILER) $(COMPILER_FLAGS) $(INCLUDE_PATHS) $(FRAMEWORKS) $(LIBRARY_PATHS) $(LINKER_FLAGS) $(CPP_FILES) -o $@

clean:
	rm -f $(APP)
.PHONY: clean