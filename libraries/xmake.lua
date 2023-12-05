add_requires("raylib")

target("library") do
	set_kind("shared")
	set_warnings("all", "error")
	
	add_files("library/src/**.cpp")
	add_includedirs("library/include", {public = true})

	add_deps("math")
	add_deps("noise")
	add_deps("random")
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

target("noise") do
	set_kind("shared")
	set_warnings("all", "error")
	
	add_files("noise/src/**.cpp")
	add_includedirs("noise/include", {public = true})

	add_deps("random")
	add_packages("raylib")
	add_defines("PLATFORM_DESKTOP")
end

target("random") do
	set_kind("shared")
	set_warnings("all", "error")
	
	add_files("random/src/**.cpp")
	add_includedirs("random/include", {public = true})

	add_packages("raylib")
	add_defines("PLATFORM_DESKTOP")
end