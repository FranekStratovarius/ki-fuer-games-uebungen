add_requires("raylib")

target("library") do
	set_kind("shared")
	set_warnings("all", "error")
	
	add_files("src/**.cpp")
	add_includedirs("include", {public = true})

	add_packages("raylib")
	add_defines("PLATFORM_DESKTOP")
end