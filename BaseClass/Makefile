include Make.defines

.PHONY : usage
usage:
	echo "must input the target !"


EVENT:Event.o
	#$(CXX) $(PUBDEFINES) -c $@ $(PUBLIBS) Event.o;
	$(AR) libMyBaseClass.a Event.o

FTP:ftptranser.o
	$(AR) libftptranser.a ftptranser.o
