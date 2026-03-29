CXX        := c++
CXX_FLAGS  := -std=c++11

TARGET     := build/zynk

SRC_FILES  := $(shell find src -name "*.cpp")
OBJ_FILES  := $(SRC_FILES:src/%.cpp=build/%.o)

all: $(TARGET)
build: $(OBJ_FILES)

clean:
	@rm -rf build $(TARGET)

$(TARGET): $(OBJ_FILES)
	$(CXX) $(CXX_FLAGS) -o $@ $^

build/%.o: src/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXX_FLAGS) -c $< -o $@

.PHONY: all build clean
