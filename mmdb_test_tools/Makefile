#mafie about test tools for mmdb which is a memorize database.
#created by sfzhao
 
TESRCPATH = /u1/te/src 
CXX = g++
DEFINES = -g -pipe -o2 -DLINUX -DMOM_NODBG -DDFS_Q -DTE_DEBUG -I./ -I/u1/te/src//include -I/u1/te/src//dbapi_include/ -I/u1/te/src//BaseClass/  -I/u1/te/src//DataStruct/ -I/u1/te/src//TAPSPublic/ -I/u1/te/src//TAPSTable/
LIBS = -lpthread -L/u1/te/lib -lTAPSBaseClass -lTAPSTable -lmmdb_client -lswpf_mom_client -lsq2
CXXFLAGS = ${DEFINES}
LDFLAGS = ${LIBS}

BIN = test
OBJECT = datatestbase.o testtools.o test.o
all:veryclean $(BIN)

$(BIN):$(OBJECT)
	${CXX} $(DEFINES) -o $@ $(OBJECT) ${LIBS}

clean:
	rm -f *.o

veryclean:clean
	rm -f $(BIN)
 

 

