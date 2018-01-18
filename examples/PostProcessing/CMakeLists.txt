project (Exp1_PostProcess)

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
	${OglSP_SOURCE_PATH}/GameObject.cpp
	${OglSP_SOURCE_PATH}/ResourceManager.cpp
	${OglSP_SOURCE_PATH}/ResourceImpl.cpp

	${OglSP_SOURCE_PATH}/Renderer/Shader.cpp
	${OglSP_SOURCE_PATH}/Renderer/Texture2D.cpp
	${OglSP_SOURCE_PATH}/Renderer/TextRenderer.cpp
	${OglSP_SOURCE_PATH}/Renderer/Renderer2D.cpp
	${OglSP_SOURCE_PATH}/Renderer/SpriteRenderer.cpp
	${OglSP_SOURCE_PATH}/Renderer/FbRenderer.cpp

	${OglSP_SOURCE_PATH}/Audio/Audio.cpp
	${OglSP_SOURCE_PATH}/Audio/AudioEngine.cpp
	${OglSP_SOURCE_PATH}/Audio/OggReader.cpp

	${OglSP_SOURCE_PATH}/CommonUtilities.cpp
)

add_executable(Exp1_PostProcess ${source_files} ${header_files} ${shader_files})

#source_group("Module Source" FILES ${module_source_files})
source_group("Shader Files" FILES ${shader_files})

target_include_directories(Exp1_PostProcess PUBLIC ${OglSP_INCLUDE_DIR})
target_link_libraries(Exp1_PostProcess OglSP)

install (TARGETS Exp1_PostProcess DESTINATION bin)