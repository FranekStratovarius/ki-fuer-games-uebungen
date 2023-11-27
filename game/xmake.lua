add_requires("raylib")

add_rules(
	"mode.debug",
	"mode.release"
)

includes("../libraries/xmake.lua")

target("uebung_001") do
	set_kind("binary")
	set_warnings("all", "error")

	add_files("src/**.cpp")
	add_includedirs("include")

	add_deps("npc")
	add_deps("player")
	add_packages("raylib")
	add_defines("PLATFORM_DESKTOP")

	-- copy assets after build
	after_build(function (target)
		os.cp(path.join("assets"), path.join("$(buildir)", "$(os)", "$(arch)", "$(mode)"))
	end)
end