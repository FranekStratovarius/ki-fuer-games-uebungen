{
    values = {
        "/usr/bin/gcc",
        {
            "-m64",
            "-fPIC",
            "-Wall",
            "-Werror",
            "-Inpc/include",
            "-DPLATFORM_DESKTOP",
            "-isystem",
            "/home/louis/.xmake/packages/r/raylib/4.5.0/0d0f6226d4fe47279c0da40af2f0a513/include",
            "-isystem",
            "/usr/include/python3.11"
        }
    },
    files = {
        "npc/src/world.cpp"
    },
    depfiles_gcc = "world.o: npc/src/world.cpp npc/include/world.hpp npc/include/npc.hpp\
"
}