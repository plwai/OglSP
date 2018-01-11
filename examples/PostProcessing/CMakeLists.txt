cmake_minimum_required (VERSION 3.7.0 FATAL_ERROR)
project (Exp1_PostProcess)

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

# path
set (ROOT_PATH "${PROJECT_SOURCE_DIR}")
set (PARENT_PATH "${PROJECT_SOURCE_DIR}/../../")

set ( source_files
	Game.cpp
	GameImpl.cpp
	PostProcessor.cpp
	BoxObject.cpp

	main.cc
)

set ( header_files
	Game.h
	GameImpl.h
	PostProcessor.h
	BoxObject.h
)

set ( shader_files
	postProcess.vert
	
	postProcess.frag
)

set ( module_source_files
	${PARENT_PATH}/src/glad/glad.c
)

set ( lib_files
	${OglSP_SOURCE_PATH}/TextRenderer.cpp
	${OglSP_SOURCE_PATH}/Renderer2D.cpp
	${OglSP_SOURCE_PATH}/SpriteRenderer.cpp
	${OglSP_SOURCE_PATH}/FbRenderer.cpp
	${OglSP_SOURCE_PATH}/GameObject.cpp
	${OglSP_SOURCE_PATH}/ResourceManager.cpp
	${OglSP_SOURCE_PATH}/ResourceImpl.cpp
	${OglSP_SOURCE_PATH}/Shader.cpp
	${OglSP_SOURCE_PATH}/Texture2D.cpp

	${OglSP_SOURCE_PATH}/Audio.cpp
	${OglSP_SOURCE_PATH}/AudioEngine.cpp
	${OglSP_SOURCE_PATH}/OggReader.cpp

	${OglSP_SOURCE_PATH}/CommonUtilities.cpp
)

include_directories("${PROJECT_BINARY_DIR}")

add_executable(Exp1_PostProcess ${source_files} ${header_files} ${module_source_files} ${shader_files})

source_group("Module Source" FILES ${module_source_files})
source_group("Shader Files" FILES ${shader_files})

target_include_directories(Exp1_PostProcess PUBLIC ${OPENGL_INCLUDE_DIR})
target_include_directories(Exp1_PostProcess PUBLIC "${PARENT_PATH}/modules/glad/include")
target_include_directories(Exp1_PostProcess PUBLIC "${PARENT_PATH}/modules/stb")
target_include_directories(Exp1_PostProcess PUBLIC ${OPENGL_INCLUDE_DIR})
target_include_directories(Exp1_PostProcess PUBLIC ${GLM_INCLUDE_DIR})
target_include_directories(Exp1_PostProcess PUBLIC ${FREETYPE_INCLUDE_DIRS})
target_include_directories(Exp1_PostProcess PUBLIC "$ENV{OPENAL_DIR}/include")
target_include_directories(Exp1_PostProcess PUBLIC "$ENV{LIBOGG_DIR}/include")
target_include_directories(Exp1_PostProcess PUBLIC "$ENV{LIBVORBIS_DIR}/include")
target_link_libraries(Exp1_PostProcess ${FREETYPE_LIBRARIES})
target_link_libraries(Exp1_PostProcess ${OPENGL_gl_LIBRARY})
target_link_libraries(Exp1_PostProcess glfw)
target_link_libraries(Exp1_PostProcess glm)
target_link_libraries(Exp1_PostProcess ${OpenAL})
target_link_libraries(Exp1_PostProcess ${LibOgg})
target_link_libraries(Exp1_PostProcess ${LibVorbis})
target_link_libraries(Exp1_PostProcess ${LibVorbisFile})

include_directories(${OPENGL_INCLUDE_DIR})
include_directories("${PARENT_PATH}/modules/glad/include")
include_directories("${PARENT_PATH}/modules/stb")
include_directories(${OPENGL_INCLUDE_DIR})
include_directories(${GLM_INCLUDE_DIR})
include_directories(${FREETYPE_INCLUDE_DIRS})
include_directories("$ENV{OPENAL_DIR}/include")
include_directories("$ENV{LIBOGG_DIR}/include")
include_directories("$ENV{LIBVORBIS_DIR}/include")
link_libraries(${FREETYPE_LIBRARIES})
link_libraries(${OPENGL_gl_LIBRARY})
link_libraries(glfw)
link_libraries(glm)
link_libraries(${OpenAL})
link_libraries(${LibOgg})
link_libraries(${LibVorbis})
link_libraries(${LibVorbisFile})
add_library(OglSPLib ${lib_files})

target_include_directories(Exp1_PostProcess PUBLIC "${PARENT_PATH}/src/starter")
target_link_libraries(Exp1_PostProcess OglSPLib)

install (TARGETS OglSPLib DESTINATION lib)
install (TARGETS Exp1_PostProcess DESTINATION bin)