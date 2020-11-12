add_library(glew32 glew32.dll)
add_library(assimp assimp-vc140-mt.dll)


set_target_properties(glew32 PROPERTIES LINKER_LANGUAGE C)
set_target_properties(assimp PROPERTIES LINKER_LANGUAGE C)