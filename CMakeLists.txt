cmake_minimum_required (VERSION 3.8)

project ("CppEngine2D")

enable_testing()

#//Use shared (DLL) run-time lib even when Google Test is built
#// as static lib.
#gtest_force_shared_crt:BOOL=ON
#se the above option in "CMakeCache.txt" to on to make tests work
#TODO
#find a better way to do this

set(FROGGER_HEADERS
	#including in hierarchy order
	#dependencies
	"dependencies/stb_image.h"
	#folders inside engine folder
	##gfx folder
	"src/engine/gfx/image_info.hpp"
	"src/engine/gfx/renderer.hpp"
	"src/engine/gfx/sprite.hpp"
	"src/engine/gfx/texture.hpp"
	##physics folder
	"src/engine/physics/bounding_box.hpp"
	"src/engine/physics/collision_info.hpp"
	"src/engine/physics/rigid_body.hpp"
	#engine folder
	"src/engine/draw_manager.hpp"
	"src/engine/event.hpp"
	"src/engine/game_clock.hpp"
	"src/engine/game_object.hpp"
	"src/engine/input.hpp"
	"src/engine/physics_manager.hpp"
	"src/engine/texture_manager.hpp"
	"src/engine/update_manager.hpp"
	#folders inside frogger folder
	##actors
	"src/frogger/actors/background.hpp"
	"src/frogger/actors/bg_water.hpp"
	"src/frogger/actors/obstacle.hpp"
	"src/frogger/actors/player.hpp"
	"src/frogger/actors/wood_log.hpp"
	#frogger folder
	"src/frogger/game.hpp"
	"src/frogger/map.hpp"
	#math folder
	"src/math/vector2.hpp"
	#utilities folder
	"src/utilities/timer.hpp"
	"src/utilities/types.hpp"
)

set(FROGGER_SOURCES
	
	${FROGGER_HEADERS}
	#including in hierarchy order
	#dependencies
	"dependencies/stb_image.h"
	#folders inside engine folder
	##gfx folder
	"src/engine/gfx/image_info.cpp"
	"src/engine/gfx/renderer.cpp"
	"src/engine/gfx/sprite.cpp"
	"src/engine/gfx/texture.cpp"
	##physics folder
	"src/engine/physics/bounding_box.cpp"
	"src/engine/physics/rigid_body.cpp"
	#engine folder
	"src/engine/draw_manager.cpp"
	"src/engine/event.cpp"
	"src/engine/game_clock.cpp"
	"src/engine/game_object.cpp"
	"src/engine/input.cpp"
	"src/engine/physics_manager.cpp"
	"src/engine/texture_manager.cpp"
	"src/engine/update_manager.cpp"
	#folders inside frogger folder
	##actors
	"src/frogger/actors/background.cpp"
	"src/frogger/actors/bg_water.cpp"
	"src/frogger/actors/obstacle.cpp"
	"src/frogger/actors/player.cpp"
	"src/frogger/actors/wood_log.cpp"
	#frogger folder
	"src/frogger/game.cpp"
	"src/frogger/map.cpp"
	#math folder
	"src/math/vector2.cpp"
	#utilities folder
	"src/utilities/timer.cpp"
)

add_executable(FroggerExecutable "src/main.cpp")

add_library(FroggerLib STATIC ${FROGGER_SOURCES})


target_link_libraries(FroggerLib PUBLIC SDL2main SDL2)
target_include_directories(FroggerLib PUBLIC SDL2main SDL2)

target_link_libraries(FroggerExecutable PRIVATE FroggerLib)
target_include_directories(FroggerExecutable PRIVATE FroggerLib)

add_dependencies(FroggerExecutable FroggerLib)

add_subdirectory(dependencies)
#add_subdirectory(test)

add_custom_command(TARGET FroggerExecutable POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_if_different
		${PROJECT_BINARY_DIR}/_deps/sdl2-build/SDL2d.dll #<--- copy this file
		${PROJECT_BINARY_DIR}/) #<--- into this path

add_custom_command(TARGET FroggerExecutable PRE_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_directory
		${CMAKE_CURRENT_SOURCE_DIR}/assets #<--- copy files in this folder
		${PROJECT_BINARY_DIR}/assets/) #<--- into this path
