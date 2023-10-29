{
    files = {
        "../libraries/npc/src/world.cpp"
    },
    depfiles_gcc = "world.o: ../libraries/npc/src/world.cpp  ../libraries/npc/include/world.hpp ../libraries/npc/include/npc.hpp\
",
    values = {
        "/usr/bin/gcc",
        {
            "-m64",
            "-fPIC",
            "-Wall",
            "-Werror",
            "-O3",
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