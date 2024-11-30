# Makefile for Old Maid game

CC = g++
CFLAGS = -std=c++11 -I./include
SRC = src/main.cpp \
      src/OldMaid.cpp \
      src/OldMaidUI.cpp \
      src/OldMaidDeck.cpp \
      src/Player.cpp \
      src/Card.cpp \
      src/Deck.cpp \
      src/Game.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = oldmaid

# Build target: the default action
$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

# Compile each source file into an object file
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up the compiled files
clean:
	rm -f $(OBJ) $(EXEC)

