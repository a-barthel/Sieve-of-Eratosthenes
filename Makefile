CC=gcc

all: clean partA partB partC

partA:
	$(CC) -g -lm -o partA partA.c
partB:
	$(CC) -g -lm -o partB partB.c
partC:
	$(CC) -g -lm -o partC partC.c
clean:
	rm -rf partA partB partC
