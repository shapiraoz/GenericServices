######################################################################
# Simple make file 
#
# GenericServiceUT
#######################################################################

CC=g++
AR=/usr/bin/ar
RL=/urs/bin/ranlib
LD=/usr/bin/ld

SRCDIR := .
INCDIR := .
OBJDIR := .

SRC :=  	$(SRCDIR)/Utils/Types.cpp \
		$(SRCDIR)/Utils/UtilsFunctions.cpp \
		$(SRCDIR)/Elements/AElement.cpp \
		$(SRCDIR)/Serialization/XMLSerializer.cpp \
		$(SRCDIR)/UT/ElementsUT.cpp 
					

EXE := GenericServiceUT_EXE

OBJ := $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SRC))

CFLAGS := -c $(addprefix -I, $(INCDIR)) -O2 -Wall

DBGFLAGS := -g3 -rdynamic -DPROFILER #-pg

LDFLAGS := 
			   

all: $(EXE) $(SIMPLE) 

debug: $(EXED) $(SIMPLED) 

build: clean all
install: clean all

$(OBJDIR)/%.o : $(SRCDIR)/%.cpp
		$(CC) $(CFLAGS) -MD -o $@ $<
		@cp $(OBJDIR)/$*.d $(OBJDIR)/$*.P; \
		sed -e 's/#.*//' -e 's/^[^:]*: *//' -e 's/ *\\$$//' \
		-e '/^$$/ d' -e 's/$$/ :/' < $(OBJDIR)/$*.d >> $(OBJDIR)/$*.P; \
		rm -f $(OBJDIR)/$*.d


$(EXE) : $(OBJ)
	$(CC) -o $@ $(OBJ) $(CFLGS) $(LDFLAGS)

clean:
	rm -f $(EXE) $(OBJ) $(OBJ:.o=.P)

-include $(OBJ:.o=.P)


