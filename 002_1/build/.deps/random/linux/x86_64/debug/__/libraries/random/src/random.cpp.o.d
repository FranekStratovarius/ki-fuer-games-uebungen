{
    files = {
        "../libraries/random/src/random.cpp"
    },
    depfiles_gcc = "random.o: ../libraries/random/src/random.cpp  ../libraries/random/include/random.hpp\
",
    values = {
        "/usr/bin/gcc",
        {
            "-m64",
            "-fPIC",
            "-g",
            "-Wall",
            "-Werror",
            "-O0",
            "-I../libraries/random/include"
        }
    }
}