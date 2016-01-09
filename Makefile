# FlyCapture2Test makefile
# To compile the debug verison need to overwrite CXXFLAGS variable to include -ggdb

CC = g++
OUTPUTNAME = testconsole
INCLUDE = -I.
LIBS =

OBJS = testconsole.o

${OUTPUTNAME}: ${OBJS}
	${CC} -o ${OUTPUTNAME} ${OBJS} ${LIBS}

%.o: %.cpp
	${CC} ${CFLAGS} ${INCLUDE} -c $*.cpp
	
clean_obj:
	rm -f ${OBJS}	@echo "all cleaned up!"

clean:
	rm -f ${OUTDIR}/${OUTPUTNAME} ${OBJS}	@echo "all cleaned up!"





