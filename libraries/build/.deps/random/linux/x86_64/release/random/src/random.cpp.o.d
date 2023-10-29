{
    depfiles_gcc = "random.o: random/src/random.cpp random/include/random.hpp\
",
    files = {
        "random/src/random.cpp"
    },
    values = {
        "/usr/bin/gcc",
        {
            "-m64",
            "-fPIC",
            "-Wall",
            "-Werror",
            "-Irandom/include"
        }
    }
}