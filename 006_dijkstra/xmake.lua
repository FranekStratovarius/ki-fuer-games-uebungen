add_requires("raylib")

add_rules(
	"mode.debug",
	"mode.release"
)

includes("../libraries/xmake.lua")

target("006_dijkstra") do
	set_kind("binary")
	set_warnings("all", "error")

	add_files("src/**.cpp")
	add_includedirs("include")

	add_deps("path_finding")
	add_packages("raylib")
	add_defines("PLATFORM_DESKTOP")
end