CC = clang++
CXXFLAGS = -I$(SCITERSDK)/include -std=c++14 -Wno-inconsistent-missing-override
LDFLAGS = -framework AppKit -framework Cocoa -framework Foundation
RESOURCES = $(shell find ui/ -type f -name '*')
PROGRAM = hello-cpp

$(PROGRAM): main.o sciter-osx-main.o
	$(CC) $(LDFLAGS) $^ -o $@

main.o: resources.cpp

resources.cpp: $(RESOURCES)
	$(SCITERSDK)/bin/macosx/packfolder ui resources.cpp -v "resources"

sciter-osx-main.o: sciter-osx-main.mm
	$(CC) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -rf *.o $(PROGRAM) resources.cpp
	