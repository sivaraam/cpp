implementation = "s_des.cpp"
test = "test.cpp"

c++_std = "1z"
opts = "-std=c++$(c++_std)"

all:
	g++ $(opts) -c $(implementation)

build:
	g++ $(opts) $(implementation) $(test)
