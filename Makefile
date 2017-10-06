#
#	"src" folder contains the .cpp files
#	"include" folder contains the .h files
#	Scroll down for see the otimization options
#
#	Makefile configs
#

CC := g++ -std=gnu++14 #compilador e diretivas

SRC_PATH := src #pasta com os cpp
SRC_TEXT := cpp	#tipo de arquivo

INC := -I headers #pasta com os headers

OUT_PATH := bin	#pasta para o executável
TARGET := bin/main	#Executável
TARGET_OPT := bin/dist
TARGET_FAST := bin/fast
TARGET_TINY := bin/tiny

SOURCES := $(shell find $(SRC_PATH) -type f -name *.$(SRC_TEXT)) # shellscript para procurar os source files

#
#	Makefile code
#

ALL: build run

build:
	@echo "Building source files..."
	@mkdir -p $(OUT_PATH)
	$(CC) $(SOURCES) $(INC) -o $(TARGET)
	@echo ""

run:
	@echo "Running application..."
	@echo ""
	@./$(TARGET)

clean:
	@echo "Deleting /bin folder..."
	@echo ""
	@rm -r $(TARGET) $(TARGET_FAST) $(TARGET_OPT) $(TARGET_TINY)

dist:
	@echo "build optimized code..."
	@echo ""
	$(CC) $(SOURCES) $(INC) -o $(TARGET_OPT) -O3
	@echo ""

fast:
	@echo "build optimized fast code..."
	@echo ""
	$(CC) $(SOURCES) $(INC) -o $(TARGET_FAST) -Ofast
	@echo ""

tiny:
	@echo "build optimized tiny code..."
	@echo ""
	$(CC) $(SOURCES) $(INC) -o $(TARGET_TINY) -Os
	@echo ""
