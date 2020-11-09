

###############################################################################
# File management.  This is where the source, header, and object files are
# defined

#
# source files
srcfiles        := $(wildcard *.cpp) $(wildcard src/*.cpp)

#
# object files
objects         := $(patsubst %.cpp, %.o, $(srcfiles))
###############################################################################

CXX      = g++ 
CXXFLAGS = -O2 
INCLUDE  = -I./include 

target = ./parte2.exe 

all: $(objects) 
	@echo "Linking ..." 
	@$(CXX) -o $(target) $(CXXFLAGS) $(objects) $(LDFLAGS)
	@echo "***************************************************************"
	@echo " "             
	@$(target)
	@echo " "
	@echo "***************************************************************"
	@echo "* Done  " $(notdir $(target))
	@echo " "
	@rm  $(objects) $(target)

###############################################################################
%.o : %.cpp
	@echo "Compiling C++ (in "$(mode)" mode) "$<"..."
	@$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@
