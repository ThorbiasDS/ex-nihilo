# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/thorbias/Área de Trabalho/ex-nihilo"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/thorbias/Área de Trabalho/ex-nihilo"

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start "/home/thorbias/Área de Trabalho/ex-nihilo/CMakeFiles" "/home/thorbias/Área de Trabalho/ex-nihilo//CMakeFiles/progress.marks"
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start "/home/thorbias/Área de Trabalho/ex-nihilo/CMakeFiles" 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named program

# Build rule for target.
program: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 program
.PHONY : program

# fast build rule for target.
program/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/program.dir/build.make CMakeFiles/program.dir/build
.PHONY : program/fast

src/Musica.o: src/Musica.cpp.o
.PHONY : src/Musica.o

# target to build an object file
src/Musica.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/program.dir/build.make CMakeFiles/program.dir/src/Musica.cpp.o
.PHONY : src/Musica.cpp.o

src/Musica.i: src/Musica.cpp.i
.PHONY : src/Musica.i

# target to preprocess a source file
src/Musica.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/program.dir/build.make CMakeFiles/program.dir/src/Musica.cpp.i
.PHONY : src/Musica.cpp.i

src/Musica.s: src/Musica.cpp.s
.PHONY : src/Musica.s

# target to generate assembly for a file
src/Musica.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/program.dir/build.make CMakeFiles/program.dir/src/Musica.cpp.s
.PHONY : src/Musica.cpp.s

src/Playlist.o: src/Playlist.cpp.o
.PHONY : src/Playlist.o

# target to build an object file
src/Playlist.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/program.dir/build.make CMakeFiles/program.dir/src/Playlist.cpp.o
.PHONY : src/Playlist.cpp.o

src/Playlist.i: src/Playlist.cpp.i
.PHONY : src/Playlist.i

# target to preprocess a source file
src/Playlist.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/program.dir/build.make CMakeFiles/program.dir/src/Playlist.cpp.i
.PHONY : src/Playlist.cpp.i

src/Playlist.s: src/Playlist.cpp.s
.PHONY : src/Playlist.s

# target to generate assembly for a file
src/Playlist.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/program.dir/build.make CMakeFiles/program.dir/src/Playlist.cpp.s
.PHONY : src/Playlist.cpp.s

src/main.o: src/main.cpp.o
.PHONY : src/main.o

# target to build an object file
src/main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/program.dir/build.make CMakeFiles/program.dir/src/main.cpp.o
.PHONY : src/main.cpp.o

src/main.i: src/main.cpp.i
.PHONY : src/main.i

# target to preprocess a source file
src/main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/program.dir/build.make CMakeFiles/program.dir/src/main.cpp.i
.PHONY : src/main.cpp.i

src/main.s: src/main.cpp.s
.PHONY : src/main.s

# target to generate assembly for a file
src/main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/program.dir/build.make CMakeFiles/program.dir/src/main.cpp.s
.PHONY : src/main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... program"
	@echo "... src/Musica.o"
	@echo "... src/Musica.i"
	@echo "... src/Musica.s"
	@echo "... src/Playlist.o"
	@echo "... src/Playlist.i"
	@echo "... src/Playlist.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

