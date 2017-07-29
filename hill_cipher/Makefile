implementation = "hill_cipher.cpp"
test_file = "cipher_test.cpp"

gcc_compatible_compiler = "clang++"
opts = "-std=c++14"

all:
	$(gcc_compatible_compiler) $(opts) -S $(implementation)

build:
	$(gcc_compatible_compiler) $(opts) $(implementation) $(test_file)

# TODO: measure performance difference
optimize::
	$(gcc_compatible_compiler) -O3 $(opts) $(implementation) $(test_file)
