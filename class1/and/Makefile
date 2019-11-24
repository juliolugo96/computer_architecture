##########################################################################
# POR FAVOR, INDIQUE A CONTINUACIÓN SU CONFIGURACIÓN PARA LA COMPILACIÓN

# Versión de SYSTEMC
	VERSION = systemc-2.3.3
# Especifique los archivos .cpp
	SRCS = main.cpp testbench.cpp and_gate.cpp
# Nombre del ejecutable
	TARGET = test
# Arquitectuda de su computadora (64 o 32)
	ARQ = 64

##########################################################################


# Por favor, no modifique el resto de la configuración del make
#--------------------------------- INICIO ---------------------------------

CC      = g++
X64     = 

ifeq ($(ARQ),64)
	X64 = 64
endif

ifeq ($(VERSION),systemc-2.3.1)
	CC = g++ -std=c++98
endif

SYSTEMC = /usr/local/$(VERSION)
INCDIR  = -I. -I.. -I$(SYSTEMC)/include
LIBDIR  = -L. -L.. -L$(SYSTEMC)/lib-linux$(X64)/
LIBS    = -lm -lsystemc


CFLAGS = -g -Wno-deprecated -Wall
OBJS   = $(SRCS:.cpp=.o)

.SUFFIXES: .cpp .o

$(TARGET): $(OBJS) $(SRCH)
	$(CC) $(CFLAGS) $(INCDIR) $(LIBDIR) -o $@ $(OBJS) $(LIBS) 2>&1 | c++filt

all: $(TARGET)

.cpp.o:
	$(CC) $(CFLAGS) $(INCDIR) -c $<

clean:
	rm -f $(OBJS) *~ $(TARGET) *.bak $(TARGET).stackdump *.vcd

#---------------------------------- FIN -----------------------------------
