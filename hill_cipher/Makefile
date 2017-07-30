implementation = "hill_cipher.cpp"
test_file = "cipher_test.cpp"

gcc_compatible_compiler = "clang++"
opts = "-std=c++14"
opts += "-Wall"
opts += "--pedantic"

all:
	$(gcc_compatible_compiler) $(opts) -S $(implementation)

build:
	$(gcc_compatible_compiler) $(opts) $(implementation) $(test_file)

debug:
	$(gcc_compatible_compiler) $(opts) -g $(implementation) $(test_file)

# TODO: measure performance difference
optimize::
	$(gcc_compatible_compiler) -O3 $(opts) $(implementation) $(test_file)
