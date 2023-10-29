add_requires(
	"raylib",
	"raygui"
)

add_rules(
	"mode.debug",
	"mode.release"
)

includes("../libraries/xmake.lua")

target("uebung_002_2") do
	set_kind("binary")
	set_warnings("all", "error")

	add_files("src/**.cpp")
	add_includedirs("include")

	add_deps("random")
	add_packages(
		"raylib",
		"raygui"
	)
	add_defines(
		"PLATFORM_DESKTOP",
		"RAYGUI_IMPLEMENTATION"
	)
end