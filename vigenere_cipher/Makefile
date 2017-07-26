implementations = "vigenere_cipher.cpp"
implementations += "../ceaser_cipher/ceaser_cipher.cpp"
test_file = "cipher_test.cpp"

all:
	# just compile the implementation
	g++ -S -std=c++14 $(implementations)
build:
	g++ $(implementations) $(test_file)

# TODO: try optimizing the source
optimize::
	g++ -O3 $(implementations)
