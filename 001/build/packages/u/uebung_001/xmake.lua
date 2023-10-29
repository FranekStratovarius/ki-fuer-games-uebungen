package("uebung_001")
    set_description("The uebung_001 package")
    add_deps("npc")

    on_load(function (package)
        package:set("installdir", path.join(os.scriptdir(), package:plat(), package:arch(), package:mode()))
    end)

    on_fetch(function (package)
        return {program = path.join(package:installdir("bin"), "add_deps("npc")")}
    end)
