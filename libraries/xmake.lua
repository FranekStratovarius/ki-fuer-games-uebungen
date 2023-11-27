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

	add_deps("player")
	add_deps("options")
	add_deps("reasoners")
	add_packages("raylib")
	add_defines("PLATFORM_DESKTOP")
end

target("reasoners") do
	set_kind("shared")
	set_warnings("all", "error")
	
	add_files("reasoners/src/**.cpp")
	add_includedirs("reasoners/include", {public = true})

	add_deps("options")
	add_deps("blackboard")
	add_packages("raylib")
	add_defines("PLATFORM_DESKTOP")
end

target("options") do
	set_kind("shared")
	set_warnings("all", "error")
	
	add_files("options/src/**.cpp")
	add_includedirs("options/include", {public = true})

	add_deps("math")
	add_deps("blackboard")
	add_deps("random")
	add_packages("raylib")
	add_defines("PLATFORM_DESKTOP")
end

target("player") do
	set_kind("shared")
	set_warnings("all", "error")

	add_files("player/src/**.cpp")
	add_includedirs("player/include", {public = true})

	add_deps("blackboard")
	add_deps("options")
	add_packages("raylib")
	add_defines("PLATFORM_DESKTOP")
end

target("blackboard") do
	set_kind("shared")
	set_warnings("all", "error")

	add_files("blackboard/src/**.cpp")
	add_includedirs("blackboard/include", {public = true})

	add_packages("raylib")
	add_defines("PLATFORM_DESKTOP")
end

target("math") do
	set_kind("shared")
	set_warnings("all", "error")

	add_files("math/src/**.cpp")
	add_includedirs("math/include", {public = true})

	add_packages("raylib")
	add_defines("PLATFORM_DESKTOP")
end