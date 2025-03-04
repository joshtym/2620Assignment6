# For Makefiles, lines preceded with # are comment lines
# Remember, Makefiles are your friends. You do not want to be compiling
# files individually.
#
# Makefile for myInttion project
#
# Author: Arie
# Sep. 15, 2011
#

# some settings...
# use the gnu C++ compiler
CCC=g++
# list all warnings
CCCFLAGS = -Wall -g -std=c++11 -Wno-reorder

# all is called a target, after the colon you have dependencies
# ie. "the target all is dependent on the executables
all : perm select

# the target <excecutable1> is dependent on the list of dependencies
# the line following  is the required executable (don't need to adjust it)
# Note: executable lines, ie. $(CCC) ..., always begin with a tab.
# $^ = this target
# $@ = this/these dependencies
prob2 : BST.o prob2.o
	$(CCC) $(CCCFLAGS) $^ -o $@
	
perm : perm.cc
	$(CCC) $(CCCFLAGS) $^ -o $@
	
select : select.cc
	$(CCC) $(CCCFLAGS) $^ -o $@

# if 2 or more problems in assignment, you can compile them all with extra 
# executable targets and dependencies.
#<executable2 : <executable2 dependencies spaces between> (usually .o files)
#	$(CCC) $(CCCFLAGS) $^ -o $@

# default rule compiling .cc to .o
# all .o file targets are dependent on the corresponding .cc files
# $< = the corresponding .cc file
%.o : %.cc
	$(CCC) -c $(CCCFLAGS) $<

# Don't need next lines b/c of the above default rule but no harm including them
# In the following lines, make knows that the .cc file is required in the
# current dependency so you can leave it out.  You can also leave out the
# corresponding executable line
BST.o : BST.h
prob2.o : BST.h

clean:
	rm -f *.o *~ *% *# .#*

clean-all: clean
	rm -f perm select prob2
