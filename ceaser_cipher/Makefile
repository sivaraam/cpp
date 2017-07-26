implementation = "ceaser_cipher.cpp"
test_file = "cipher_test.cpp"

gcc_compatible_compiler = "clang++"
opts = "-std=c++11"

all::
	# just compile the implementation
	$(gcc_compatible_compiler) -S $(opts) $(implementation)

build::
	$(gcc_compatible_compiler) $(opts) $(implementation) $(test_file)
