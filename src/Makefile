# Compiler
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g

# Target executable
TARGET = demonshand

# Source files
SRCS = \
		game.cpp \
		Deck.cpp \
		Card.cpp \
		Hand.cpp \
		Boss.cpp \
		DamageCalculator.cpp \
		welcome_display.cpp \
		display_game_status.cpp \
		view_options.cpp \
		select_cards.cpp

# Header files (for dependency tracking, optional)
HEADERS = \
		Deck.h \
		Hand.h \
		Boss.h \
		DamageCalculator.h

# Object files
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(TARGET)

# Link object files to create executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile each cpp file to object
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean