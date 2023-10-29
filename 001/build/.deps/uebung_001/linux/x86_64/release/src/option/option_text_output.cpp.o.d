{
    files = {
        "src/option/option_text_output.cpp"
    },
    depfiles_gcc = "option_text_output.o: src/option/option_text_output.cpp  include/option/option_text_output.hpp  ../libraries/npc/include/option.hpp\
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