SRC_DIR=src
BUILD_DIR=build
GPP=g++
FLAGS=$(pkg-config --cflags --libs sdl2)

.PHONY: clean all open-window

clean:
	rm -rf $(BUILD_DIR)
	mkdir $(BUILD_DIR)

all:
	$(GPP) open-window/main.cpp -o build/open-window $(FLAGS)

open-window:
	$(GPP) open-window/main.cpp -o build/open-window $(FLAGS)
