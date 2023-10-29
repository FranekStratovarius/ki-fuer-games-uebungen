{
    files = {
        "src/main.cpp"
    },
    depfiles_gcc = "main.o: src/main.cpp ../libraries/npc/include/option.hpp  ../libraries/npc/include/npc.hpp include/option/option_text_output.hpp\
",
    values = {
        "/usr/bin/gcc",
        {
            "-m64",
            "-fvisibility=hidden",
            "-fvisibility-inlines-hidden",
            "-Wall",
            "-Werror",
            "-O3",
            "-Iinclude",
            "-I../libraries/npc/include",
            "-DPLATFORM_DESKTOP",
            "-isystem",
            "/home/louis/.xmake/packages/r/raylib/4.5.0/0d0f6226d4fe47279c0da40af2f0a513/include",
            "-isystem",
            "/usr/include/python3.11",
            "-DNDEBUG"
        }
    }
}