#you touched your makefile oh no!
CC       =  g++
CCFLAGS  =  -O2 -march=core2 -Wall
DEBUG    =  -g -D=_DEBUG_
INCLUDES =  -I/usr/include
LDPATH   =  -L/usr/lib64
LIBS     =  
NAME     =  airena

SRC=src/
DST=bin/

HEADERS  =  $(SRC)event.h   \
            $(SRC)point.h   \
            $(SRC)vector.h  \
            $(SRC)entity.h  \
            $(SRC)zombie.h  \


OBJS     =  main.o          \
            point.o         \
            vector.o        \
            entity.o        \
            zombie.o        \

all: $(NAME)

debug: CCFLAGS += $(DEBUG)
debug: $(NAME)

$(NAME): $(OBJS) Makefile
	$(CC) $(OBJS) $(LDPATH) $(LIBS) -o $@

$(OBJS): %.o: ./src/%.cpp $(HEADERS)
	$(CC) $(CFLAGS) $(CCFLAGS) $(DEFINES) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(NAME) $(OBJS)