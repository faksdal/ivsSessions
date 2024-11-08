#
#
#	Makefile
#	
#	target: prerequisites prerequisites ...
#		<tab>command
#		<tab>command
#
#	$@	=	target name
#	$?	=	all prerequisites newer than target
#	$<	=	first prerequisites
#	$^	=	all prerequisites
#
#	The @ in front of the echo command, prevents the actual command from being printed to screen
#
#	$(patsubst PATTERN,REPLACEMENT,TEXT)
####################################################################################################
TARGET = ivs-sessions
CXX = g++
CPPFLAGS = -Iinc -I. -g -Wall

INCDIR = inc
SRCDIR = src
OBJDIR = obj
BINDIR = bin

SOURCES = $(wildcard *.cpp $(SRCDIR)/*.cpp)
OBJFILES = $(patsubst %.cpp, $(OBJDIR)/%.o, $(notdir $(SOURCES)))

$(TARGET): $(OBJFILES)
	$(CXX) $(CPPFLAGS) -o $(BINDIR)/$(TARGET) $(OBJFILES)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp	
	$(CXX) $(CPPFLAGS) -c -o $@ $^

$(OBJDIR)/$(TARGET).o: $(TARGET).cpp
	@echo $(OBJFILES)
	$(CXX) $(CPPFLAGS) -c -o $@ $<

$(OBJDIR)/sessions.o: sessions.cpp	
	$(CXX) $(CPPFLAGS) -c -o $(OBJDIR)/sessions.o sessions.cpp

clean:
	rm $(BINDIR)/$(TARGET) $(OBJDIR)/*
