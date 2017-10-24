implementation = "railfence.cpp"
implementation += "railfence_helpers.cpp"
test_file = "cipher_test.cpp"

opts = "-std=c++14"

all:
	g++ $(opts) -c $(implementation)

build:
	g++ $(opts) $(implementation) $(test_file)
