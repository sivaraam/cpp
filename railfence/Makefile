implementation = "railfence.cpp"
implementation += "railfence_helpers.cpp"
test_file = "cipher_test.cpp"

opts = "-std=c++14"
opts += "-Wall"
opts += "-pedantic"

all:
	clang++ $(opts) -c $(implementation)

build:
	clang++ $(opts) $(implementation) $(test_file)
