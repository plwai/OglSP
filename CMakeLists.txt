cmake_minimum_required (VERSION 3.7.0 FATAL_ERROR)
project (OglSP)

find_package(OpenGL REQUIRED)
find_package(GLFW3 3.2 REQUIRED)
find_package(GLM 0.9.9 REQUIRED)
find_package(freetype REQUIRED)
find_library(OpenAL NAMES OpenAL32 HINTS "$ENV{OPENAL_DIR}/libs/Win64")
find_library(LibOgg NAMES libogg_static HINTS "$ENV{LIBOGG_DIR}/win32/lib")
find_library(LibVorbis NAMES libvorbis_static HINTS "$ENV{LIBVORBIS_DIR}/win32/lib")
find_library(LibVorbisFile NAMES libvorbisfile_static HINTS "$ENV{LIBVORBIS_DIR}/win32/lib")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

option(OglSP_EXAMPLE "Build the OglSP example programs" OFF)

# version
set (OglSP_VERSION_MAJOR 0)
set (OglSP_VERSION_MINOR 1)

# path
set (OGLSP_ROOT_PATH "${CMAKE_CURRENT_SOURCE_DIR}")
set (OglSP_SOURCE_PATH "${PROJECT_SOURCE_DIR}/src/starter")
set (OglSP_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/src/starter")
set (OglSP_SHADER_PATH "${PROJECT_SOURCE_DIR}/src/shaders")

# config file
configure_file ( 
	"${PROJECT_SOURCE_DIR}/src/StarterConfig.h.in" 
	"${PROJECT_BINARY_DIR}/StarterConfig.h"
)

set ( source_files
	${OglSP_SOURCE_PATH}/GameObject.cpp
	${OglSP_SOURCE_PATH}/ResourceManager.cpp
	${OglSP_SOURCE_PATH}/ResourceImpl.cpp

	${OglSP_SOURCE_PATH}/Renderer/Shader.cpp
	${OglSP_SOURCE_PATH}/Renderer/Texture2D.cpp
	${OglSP_SOURCE_PATH}/Renderer/TextRenderer.cpp
	${OglSP_SOURCE_PATH}/Renderer/Renderer2D.cpp
	${OglSP_SOURCE_PATH}/Renderer/SpriteRenderer.cpp
	${OglSP_SOURCE_PATH}/Renderer/FbRenderer.cpp

	${OglSP_SOURCE_PATH}/Audio/AudioEngine.cpp
	${OglSP_SOURCE_PATH}/Audio/Audio.cpp
	${OglSP_SOURCE_PATH}/Audio/OggReader.cpp

	${OglSP_SOURCE_PATH}/CommonUtilities.cpp
)

set ( header_files
	${OglSP_SOURCE_PATH}/GameObject.h
	${OglSP_SOURCE_PATH}/ResourceManager.h
	${OglSP_SOURCE_PATH}/ResourceImpl.h

	${OglSP_SOURCE_PATH}/Renderer/Shader.h
	${OglSP_SOURCE_PATH}/Renderer/Texture2D.h
	${OglSP_SOURCE_PATH}/Renderer/TextRenderer.h
	${OglSP_SOURCE_PATH}/Renderer/Renderer2D.h
	${OglSP_SOURCE_PATH}/Renderer/SpriteRenderer.h
	${OglSP_SOURCE_PATH}/Renderer/FbRenderer.h

	${OglSP_SOURCE_PATH}/Audio/AudioEngine.h
	${OglSP_SOURCE_PATH}/Audio/Audio.h
	${OglSP_SOURCE_PATH}/Audio/Decoder.h
	${OglSP_SOURCE_PATH}/Audio/OggReader.h

	${OglSP_SOURCE_PATH}/CommonUtilities.h
)

set ( shader_files
	${OglSP_SHADER_PATH}/sprite.vert
	${OglSP_SHADER_PATH}/text.vert

	${OglSP_SHADER_PATH}/sprite.frag
	${OglSP_SHADER_PATH}/text.frag
)

set ( module_source_files
	src/glad/glad.c
)

include_directories("${PROJECT_BINARY_DIR}")

add_library(OglSP ${source_files} ${module_source_files} ${shader_files})

source_group("Module Source" FILES ${module_source_files})
source_group("Shader Files" FILES ${shader_files})

target_include_directories(OglSP PUBLIC ${OPENGL_INCLUDE_DIR})
target_include_directories(OglSP PUBLIC "${PROJECT_SOURCE_DIR}/modules/glad/include")
target_include_directories(OglSP PUBLIC "${PROJECT_SOURCE_DIR}/modules/stb")
target_include_directories(OglSP PUBLIC ${OPENGL_INCLUDE_DIR})
target_include_directories(OglSP PUBLIC ${GLM_INCLUDE_DIR})
target_include_directories(OglSP PUBLIC ${FREETYPE_INCLUDE_DIRS})
target_include_directories(OglSP PUBLIC "$ENV{OPENAL_DIR}/include")
target_include_directories(OglSP PUBLIC "$ENV{LIBOGG_DIR}/include")
target_include_directories(OglSP PUBLIC "$ENV{LIBVORBIS_DIR}/include")
target_link_libraries(OglSP ${FREETYPE_LIBRARIES})
target_link_libraries(OglSP ${OPENGL_gl_LIBRARY})
target_link_libraries(OglSP glfw)
target_link_libraries(OglSP glm)
target_link_libraries(OglSP ${OpenAL})
target_link_libraries(OglSP ${LibOgg})
target_link_libraries(OglSP ${LibVorbis})
target_link_libraries(OglSP ${LibVorbisFile})

install (TARGETS OglSP DESTINATION lib)

if(OglSP_EXAMPLE)
	add_subdirectory(examples)
endif()

install (FILES "${PROJECT_BINARY_DIR}/StarterConfig.h" DESTINATION include)