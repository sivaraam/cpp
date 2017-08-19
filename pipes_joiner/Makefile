implementation = "pipe_joiner.cpp"
test_file = "main.cpp"

gcc_compatible_compiler = "clang++"
opts = "-std=c++11"
opts += "-pthread" # option for asynchronous execution

all:
	# just compile the implementation
	$(gcc_compatible_compiler) -c $(opts) $(implementation)

build:
	$(gcc_compatible_compiler) $(opts) $(implementation) $(test_file)
