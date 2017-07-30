implementation = "vigenere_cipher.cpp"
dependency = "../ceaser_cipher/ceaser_cipher.cpp"
test_file = "cipher_test.cpp"

gcc_compatible_compiler = "g++"
opts = "-std=c++11"

all:
	# just compile the implementation
	$(gcc_compatible_compiler) $(opts) -S $(dependency) $(implementation)

build:
	$(gcc_compatible_compiler) $(opts) $(dependency) $(implementation) $(test_file)

# TODO: measure performance difference
optimize::
	$(gcc_compatible_compiler) $(opts) -O3 $(dependency) $(implementation) $(test_file)
