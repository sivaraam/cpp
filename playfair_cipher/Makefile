implementation = "playfair_cipher.cpp"
dependencies = "playfair_cipher_helpers.cpp"
test_file = "cipher_test.cpp"

gcc_compatible_compiler = "clang++"
opts = "-std=c++14"
opts += "-Wall"
opts += "--pedantic"

# Variables related to boost and MTL
# which are required for this program
boost_root_dir = "/mnt/Source/cpp/boost_1_65_0/"
mtl_root_dir = "/mnt/Source/cpp/mtl_root"

lib_opts += -I$(boost_root_dir)
lib_opts += -I$(mtl_root_dir)

all:
	$(gcc_compatible_compiler) $(opts) $(lib_opts) -S $(dependencies) $(implementation)

build:
	$(gcc_compatible_compiler) $(opts) $(lib_opts) $(dependencies) $(implementation) $(test_file)

debug:
	$(gcc_compatible_compiler) $(opts) $(lib_opts) -g $(dependencies) $(implementation) $(test_file)

# TODO: measure performance difference
optimize:
	$(gcc_compatible_compiler) $(opts) $(lib_opts) -O3 $(dependencies) $(implementation) $(test_file)
