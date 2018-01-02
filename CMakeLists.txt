cmake_minimum_required (VERSION 3.7.0 FATAL_ERROR)
project (OglSP)

find_package(OpenGL REQUIRED)
find_package(GLFW3 3.2 REQUIRED)
find_package(GLM 0.9.9 REQUIRED)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# version
set (OglSP_VERSION_MAJOR 0)
set (OglSP_VERSION_MINOR 1)

# path
set (ROOT_PATH "${PROJECT_SOURCE_DIR}")
set (OglSP_SOURCE_PATH "${PROJECT_SOURCE_DIR}/src/starter")

# config file
configure_file ( 
	"${PROJECT_SOURCE_DIR}/src/StarterConfig.h.in" 
	"${PROJECT_BINARY_DIR}/StarterConfig.h"
)

set ( source_files
	src/main.cc
	
	${OglSP_SOURCE_PATH}/Game.cpp
	${OglSP_SOURCE_PATH}/GameImpl.cpp
	${OglSP_SOURCE_PATH}/Renderer.cpp
	${OglSP_SOURCE_PATH}/2DRenderer.cpp
	${OglSP_SOURCE_PATH}/TextRenderer.cpp
	${OglSP_SOURCE_PATH}/SpriteRenderer.cpp
	${OglSP_SOURCE_PATH}/FbRenderer.cpp
	${OglSP_SOURCE_PATH}/PostProcessorManager.cpp
	${OglSP_SOURCE_PATH}/PostProcessorImpl.cpp
	${OglSP_SOURCE_PATH}/GameObject.cpp
	${OglSP_SOURCE_PATH}/ResourceManager.cpp
	${OglSP_SOURCE_PATH}/ResourceImpl.cpp
	${OglSP_SOURCE_PATH}/Shader.cpp
	${OglSP_SOURCE_PATH}/Texture2D.cpp
	${OglSP_SOURCE_PATH}/ParticleGenerator.cpp
	${OglSP_SOURCE_PATH}/Audio.cpp
)

set ( header_files
	${OglSP_SOURCE_PATH}/Game.h
	${OglSP_SOURCE_PATH}/GameImpl.h
	${OglSP_SOURCE_PATH}/Renderer.h
	${OglSP_SOURCE_PATH}/2DRenderer.h
	${OglSP_SOURCE_PATH}/TextRenderer.h
	${OglSP_SOURCE_PATH}/SpriteRenderer.h
	${OglSP_SOURCE_PATH}/FbRenderer.h
	${OglSP_SOURCE_PATH}/PostProcessorManager.h
	${OglSP_SOURCE_PATH}/PostProcessorImpl.h
	${OglSP_SOURCE_PATH}/GameObject.h
	${OglSP_SOURCE_PATH}/ResourceManager.h
	${OglSP_SOURCE_PATH}/ResourceImpl.h
	${OglSP_SOURCE_PATH}/Shader.h
	${OglSP_SOURCE_PATH}/Texture2D.h
	${OglSP_SOURCE_PATH}/ParticleGenerator.h
	${OglSP_SOURCE_PATH}/Audio.h
)

set ( shader_files
	
)

set ( module_source_files
	src/glad/glad.c
)

include_directories("${PROJECT_BINARY_DIR}")

add_executable(OglSP ${source_files} ${header_files} ${module_source_files} ${shader_files})

source_group("Module Source" FILES ${module_source_files})

target_include_directories(OglSP PUBLIC ${OPENGL_INCLUDE_DIR})
target_include_directories(OglSP PUBLIC "${PROJECT_SOURCE_DIR}/modules/glad/include")
target_include_directories(OglSP PUBLIC "${PROJECT_SOURCE_DIR}/modules/stb")
target_include_directories(OglSP PUBLIC ${OPENGL_INCLUDE_DIR})
target_include_directories(OglSP PUBLIC ${GLM_INCLUDE_DIR})
target_include_directories(OglSP PUBLIC ${FREETYPE_INCLUDE_DIRS})
target_link_libraries(OglSP ${OPENGL_gl_LIBRARY})
target_link_libraries(OglSP glfw)
target_link_libraries(OglSP glm)

install (TARGETS OglSP DESTINATION lib)
install (FILES "${PROJECT_BINARY_DIR}/StarterConfig.h" DESTINATION include)