implementation = "hill_cipher.cpp"
dependencies = "hill_cipher_helpers.cpp"
test_file = "cipher_test.cpp"

gcc_compatible_compiler = "clang++"
opts = "-std=c++14"
opts += "-Wall"
opts += "--pedantic"

all:
	$(gcc_compatible_compiler) $(opts) -S $(dependencies) $(implementation) 

build:
	$(gcc_compatible_compiler) $(opts) $(dependencies) $(implementation) $(test_file)

debug:
	$(gcc_compatible_compiler) $(opts) -g $(dependencies) $(implementation) $(test_file)

# TODO: measure performance difference
optimize:
	$(gcc_compatible_compiler) $(opts) -O3 $(dependencies) $(implementation) $(test_file)
