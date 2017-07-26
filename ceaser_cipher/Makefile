implementation = "ceaser_cipher.cpp"
test_file = "cipher_test.cpp"
opts = "-std=c++11"

all::
	# just compile the implementation
	clang++ -S $(opts) $(implementation)

build::
	clang++ $(opts) $(implementation) $(test_file)
