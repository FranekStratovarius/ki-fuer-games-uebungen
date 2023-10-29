add_requires("raylib")

target("random") do
	set_kind("shared")
	set_warnings("all", "error")
	
	add_files("random/src/**.cpp")
	add_includedirs("random/include", {public = true})
end

target("npc") do
	set_kind("shared")
	set_warnings("all", "error")

	add_files("npc/src/**.cpp")
	add_includedirs("npc/include", {public = true})

	add_packages("raylib")
	add_defines("PLATFORM_DESKTOP")
end