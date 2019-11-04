STB_INCLUDE_PATH = /home/rjacobse/projects/personal/stb
TINY_OBJ_LOADER_INCLUDE_PATH = /home/rjacobse/projects/personal/tinyobjloader

CFLAGS = -std=c++17 -I$(STB_INCLUDE_PATH) -I$(TINY_OBJ_LOADER_INCLUDE_PATH) -O3

LDFLAGS = `pkg-config --static --libs glfw3` -lvulkan

VulkanMonkey: main.cpp
	g++ $(CFLAGS) -o VulkanMonkey main.cpp $(LDFLAGS)

.PHONY: test clean

test: VulkanMonkey
	./VulkanMonkey

clean:
	rm -f VulkanMonkey