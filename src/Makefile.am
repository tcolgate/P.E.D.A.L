bin_PROGRAMS = pedal
AM_YFLAGS=-d

pedal_SOURCES = \
	nodestructures.h \
	parsepdl.c \
	parsepdl.h \
	lexer.l \
	grammar.y \
	scope.c \
	scope.h \
	symtab.c \
	symtab.h \
	types.c \
	types.h 

pedal_LDFLAGS = -export-dynamic -lm

pedal_INCLUDES = -I../include -I./include
pedal_CFLAGS = -Wall 
YFLAGS = --defines
