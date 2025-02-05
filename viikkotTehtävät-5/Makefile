CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

TARGET = notifikaattori
SOURCES = main.cpp notifikaattori.cpp seuraaja.cpp
OBJECTS = $(SOURCES:.cpp=.o)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: clean 