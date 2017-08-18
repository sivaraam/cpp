implementation = "pipe_joiner.cpp"
test_file = "test.cpp"

gcc_compatible_compiler = "g++"
opts = "-std=c++11"

all:
	# just compile the implementation
	$(gcc_compatible_compiler) -S $(opts) $(implementation)

build:
	$(gcc_compatible_compiler) $(opts) $(implementation) $(test_file)
