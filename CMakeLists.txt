cmake_minimum_required(VERSION 2.6)
project(Marco_Minganna_Graphics_and_Computational_Programming)
	
include_directories(
  	${PROJECT_SOURCE_DIR}/contrib/msvc-windows-x86/ASSIMP/include
	${PROJECT_SOURCE_DIR}/contrib/msvc-windows-x86/GLEW/include
	${PROJECT_SOURCE_DIR}/contrib/msvc-windows-x86/GLFW/include
	${PROJECT_SOURCE_DIR}/contrib/msvc-windows-x86/GLM
)
add_subdirectory(${PROJECT_SOURCE_DIR}/contrib/msvc-windows-x86/bin)

link_directories(
  	${PROJECT_SOURCE_DIR}/contrib/msvc-windows-x86/GLEW/lib/Release/Win32
	${PROJECT_SOURCE_DIR}/contrib/msvc-windows-x86/GLFW/lib-vc2019
	${PROJECT_SOURCE_DIR}/contrib/msvc-windows-x86/ASSIMP/lib
)

add_executable(shadowMapping
  src/Camera.cpp
  src/DirectionalLight.cpp
  src/Game.cpp
  src/Light.cpp
  src/Material.cpp
  src/Mesh.cpp
  src/Model.cpp
  src/MyWindow.cpp
  src/OmniShadowMap.cpp
  src/PointLight.cpp
  src/Shader.cpp
  src/ShadowMap.cpp
  src/SpotLight.cpp
  src/Texture.cpp
  src/main.cpp

  src/Camera.h
  src/DirectionalLight.h
  src/Game.h
  src/Light.h
  src/Material.h
  src/Mesh.h
  src/Model.h
  src/MyWindow.h
  src/OmniShadowMap.h
  src/PointLight.h
  src/Shader.h
  src/ShadowMap.h
  src/SpotLight.h
  src/Texture.h
  src/stb_image.h
  src/CommonValues.h
  
)


target_link_libraries(shadowMapping glew32 assimp)