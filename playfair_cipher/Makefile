implementation = "playfair_cipher.cpp"
dependencies = "playfair_cipher_helpers.cpp"
test_file = "cipher_test.cpp"

c++1z_compiler = "clang++-4.0"
opts = "-std=c++1z"
opts += "-Wall"
opts += "--pedantic"

# Variables related to boost and MTL
# which are required for this program
boost_root_dir = "/mnt/Source/cpp/boost_1_65_0/"
mtl_root_dir = "/mnt/Source/cpp/mtl_root"

lib_opts += -I$(boost_root_dir)
lib_opts += -I$(mtl_root_dir)

all:
	$(c++1z_compiler) $(opts) $(lib_opts) -S $(dependencies) $(implementation)

build:
	$(c++1z_compiler) $(opts) $(lib_opts) $(dependencies) $(implementation) $(test_file)

debug:
	$(c++1z_compiler) $(opts) $(lib_opts) -g $(dependencies) $(implementation) $(test_file)

# TODO: measure performance difference
optimize:
	$(c++1z_compiler) $(opts) $(lib_opts) -O3 $(dependencies) $(implementation) $(test_file)
