implementation = "playfair_cipher.cpp"
dependencies = "playfair_cipher_helpers.cpp"
test_file = "cipher_test.cpp"

c++1z_compiler = "clang++-4.0"
opts = "-std=c++1z"
opts += "-Wall"
opts += "--pedantic"

all:
	$(c++1z_compiler) $(opts) -S $(dependencies) $(implementation)

build:
	$(c++1z_compiler) $(opts) $(dependencies) $(implementation) $(test_file)

debug:
	$(c++1z_compiler) $(opts) -g $(dependencies) $(implementation) $(test_file)

# TODO: measure performance difference
optimize:
	$(c++1z_compiler) $(opts) -O3 $(dependencies) $(implementation) $(test_file)
