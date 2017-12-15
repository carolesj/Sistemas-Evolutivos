CFLAGS = -g -o0
OBJECTS = animal.o chromossome.o config.o environment.o population.o tournament.o util.o main.o
DEPENDENCES = animal.h chromossome.h config.h environment.h population.h tournament.h util.h
OUTPUT_NAME = NATUREISBEAUTIFUL

all: $(OBJECTS) $(DEPENDENCES)
	gcc $(CFLAGS) $(OBJECTS) -o $(OUTPUT_NAME)

allclang: $(OBJECTS) $(DEPENDENCES)
	clang $(CFLAGS) $(OBJECTS) -o $(OUTPUT_NAME)
	
run:
	./$(OUTPUT_NAME)
	
clean:
	rm -rf *.o
