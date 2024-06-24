cmake_minimum_required(VERSION 3.25)


project(fireballs VERSION 1.0)

# Configuration options
set(SFML_ROOT "/home/nivk/Lib/SFML-2.6.1")

set(SFML_STATIC_LIBRARIES FALSE CACHE BOOL "Use static SFML librares")

# General compiler options
if (SFML_STATIC_LIBRARIES)
	add_definitions(-DSFML_STATIC)
endif()

# Specific compiler options - set C++11 flag for g++ and clang
if(CMAKE_COMPILER_IS_GNUCXX)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
	
	# Mac OS X: clang uses libc++ standard library
	if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
	endif()
endif()

#####################################################################################################################################

# Add directory containing FindSFML.cmake to module path
set (CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMake/;${CMAKE_MODULE_PATH}")

# Find SFML
# Note: SFML_STATIC_LIBRARIES determines which libraries are found by find_package()
find_package(SFML 2 COMPONENTS audio graphics window system network)

# If found, include and link; otherwise output error message
if(SFML_FOUND)
	message("### sfml found")
	include_directories(${SFML_INCLUDE_DIR})
else()
	set(SFML_ROOT "" CACHE PATH "SFML top-level directory")
	message("\n-> SFML directory not found. Set SFML_ROOT to SFML's top-level path (containing \"include\" and \"lib\" directories).")
	message("-> Make sure the SFML libraries with the same configuration (Release/Debug, Static/Dynamic) exist.\n")
endif()

######################################################################################################################################

include_directories("include")
file(GLOB SRC_FILES src/*.cpp)
add_executable(${PROJECT_NAME} src/Main.cpp ${SRC_FILES})

# Build static or shared libraries? Set chapter-specific DLL import macro
if(SFML_STATIC_LIBRARIES)
	set_target_properties(${PROJECT_NAME} PROPERTIES COMPILE_DEFINITIONS "SFML_STATIC")
else()
	# copy all dll files
	file(GLOB DLL_FILES ${SFML_ROOT}/bin/*.dll)
	file(COPY ${DLL_FILES} DESTINATION /)
endif()

# Link SFML. For versions < 2.2, SFML_DEPENDENCIES is not defined, and we do not need to link dependencies
if(SFML_VERSION_MINOR LESS 2)
    set(SFML_DEPENDENCIES "")
endif()

target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})

# copy media files
# file(GLOB MEDIA_FOLDER Media)
# file(COPY ${MEDIA_FOLDER} DESTINATION /)