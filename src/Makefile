# Compiler and flags
CXX = g++
CXXFLAGS = -I"C:/msys64/ucrt64/include" -Wall -std=c++17
LDFLAGS = -L"C:/msys64/ucrt64/lib" -lsfml-graphics -lsfml-window -lsfml-system

# Source files
SRCS = Main.cpp GameController.cpp Player.cpp Boss.cpp Deck.cpp Hand.cpp Card.cpp Character.cpp Orge.cpp DamageCalculator.cpp Gamemenu.cpp Phoenix.cpp Leviathan.cpp GameLogger.cpp
# Output
TARGET = game.exe

# Default rule
all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET) $(LDFLAGS)

# Clean rule
clean:
	rm -f $(TARGET)