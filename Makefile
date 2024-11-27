# Makefile

CXX = g++
CXXFLAGS = -std=c++11 -I./include -Wall -Wextra -pthread
LDFLAGS = -pthread

SRC_DIR = src
OBJ_DIR = obj
TEST_DIR = tests
COV_DIR = coverage

SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

TEST_SRCS = $(wildcard $(TEST_DIR)/*.cpp)
TEST_OBJS = $(patsubst $(TEST_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(TEST_SRCS))

all: cardGame

cardGame: $(OBJS) $(OBJ_DIR)/main.o
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

testGame: $(OBJS) $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) $^ -lgtest -o $@ $(LDFLAGS)
	./testGame

$(OBJ_DIR)/%.o: $(TEST_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

memcheck-game: cardGame
	valgrind --leak-check=full ./cardGame

memcheck-test: testGame
	valgrind --leak-check=full ./testGame

coverage: CXXFLAGS += -fprofile-arcs -ftest-coverage
coverage: LDFLAGS += -lgcov
coverage: testGame
	./testGame
	lcov --capture --directory . --output-file $(COV_DIR)/coverage.info
	genhtml $(COV_DIR)/coverage.info --output-directory $(COV_DIR)

style:
	cpplint $(SRCS) $(TEST_SRCS)

static:
	cppcheck --enable=all --inconclusive --std=c++11 --verbose $(SRC_DIR) $(TEST_DIR)

docs:
	doxygen Doxyfile

clean:
	rm -rf $(OBJ_DIR) cardGame testGame $(COV_DIR) *.gcno *.gcda docs

.PHONY: all cardGame testGame memcheck-game memcheck-test coverage style static docs clean
