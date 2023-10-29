{
    depfiles_gcc = "main.o: src/main.cpp ../libraries/random/include/random.hpp\
",
    files = {
        "src/main.cpp"
    },
    values = {
        "/usr/bin/gcc",
        {
            "-m64",
            "-g",
            "-Wall",
            "-Werror",
            "-O0",
            "-Iinclude",
            "-I../libraries/random/include",
            "-DPLATFORM_DESKTOP",
            "-DRAYGUI_IMPLEMENTATION",
            "-isystem",
            "/home/louis/.xmake/packages/r/raygui/3.2/44dc89ee0e514ddd81c34c2525e568e1/include",
            "-isystem",
            "/home/louis/.xmake/packages/r/raylib/4.5.0/0d0f6226d4fe47279c0da40af2f0a513/include",
            "-isystem",
            "/usr/include/python3.11"
        }
    }
}