{
    depfiles_gcc = "option_text_output.o: src/option_text_output.cpp  include/option/option_text_output.hpp include/option.hpp\
",
    values = {
        "/usr/bin/gcc",
        {
            "-m64",
            "-fvisibility=hidden",
            "-fvisibility-inlines-hidden",
            "-O3",
            "-std=gnu++23",
            "-Iinclude",
            "-DPLATFORM_DESKTOP",
            "-isystem",
            "/home/louis/.xmake/packages/r/raylib/4.5.0/0d0f6226d4fe47279c0da40af2f0a513/include",
            "-isystem",
            "/usr/include/python3.11",
            "-DNDEBUG"
        }
    },
    files = {
        "src/option_text_output.cpp"
    }
}