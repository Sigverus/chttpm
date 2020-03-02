project(chttpm CXX)
cmake_minimum_required(VERSION 3.2.3)

set(CPP_HTTPLIB
	src/cpp-httplib/httplib.h
)

set(ANGELSCRIPT
	src/angelscript/include/angelscript.h 

	src/angelscript/include/source/as_array.h
	src/angelscript/include/source/as_atomic.cpp
	src/angelscript/include/source/as_atomic.h
	src/angelscript/include/source/as_builder.cpp
	src/angelscript/include/source/as_builder.h
	src/angelscript/include/source/as_bytecode.cpp
	src/angelscript/include/source/as_bytecode.h
	# src/angelscript/include/source/as_callfunc_arm.cpp
	# src/angelscript/include/source/as_callfunc_arm_gcc.S
	# src/angelscript/include/source/as_callfunc_arm_msvc.asm
	# src/angelscript/include/source/as_callfunc_arm_vita.S
	# src/angelscript/include/source/as_callfunc_arm_xcode.S
	src/angelscript/include/source/as_callfunc.cpp
	src/angelscript/include/source/as_callfunc.h
	src/angelscript/include/source/as_callfunc_mips.cpp
	# src/angelscript/include/source/as_callfunc_ppc_64.cpp
	# src/angelscript/include/source/as_callfunc_ppc.cpp
	# src/angelscript/include/source/as_callfunc_sh4.cpp
	src/angelscript/include/source/as_callfunc_x64_gcc.cpp
	src/angelscript/include/source/as_callfunc_x64_mingw.cpp
	# src/angelscript/include/source/as_callfunc_x64_msvc_asm.asm
	src/angelscript/include/source/as_callfunc_x64_msvc.cpp
	src/angelscript/include/source/as_callfunc_x86.cpp
	# src/angelscript/include/source/as_callfunc_xenon.cpp
	src/angelscript/include/source/as_compiler.cpp
	src/angelscript/include/source/as_compiler.h
	src/angelscript/include/source/as_configgroup.cpp
	src/angelscript/include/source/as_configgroup.h
	src/angelscript/include/source/as_config.h
	src/angelscript/include/source/as_context.cpp
	src/angelscript/include/source/as_context.h
	src/angelscript/include/source/as_criticalsection.h
	src/angelscript/include/source/as_datatype.cpp
	src/angelscript/include/source/as_datatype.h
	src/angelscript/include/source/as_debug.h
	src/angelscript/include/source/as_gc.cpp
	src/angelscript/include/source/as_gc.h
	src/angelscript/include/source/as_generic.cpp
	src/angelscript/include/source/as_generic.h
	src/angelscript/include/source/as_globalproperty.cpp
	src/angelscript/include/source/as_map.h
	src/angelscript/include/source/as_memory.cpp
	src/angelscript/include/source/as_memory.h
	src/angelscript/include/source/as_module.cpp
	src/angelscript/include/source/as_module.h
	src/angelscript/include/source/as_namespace.h
	src/angelscript/include/source/as_objecttype.cpp
	src/angelscript/include/source/as_objecttype.h
	src/angelscript/include/source/as_outputbuffer.cpp
	src/angelscript/include/source/as_outputbuffer.h
	src/angelscript/include/source/as_parser.cpp
	src/angelscript/include/source/as_parser.h
	src/angelscript/include/source/as_property.h
	src/angelscript/include/source/as_restore.cpp
	src/angelscript/include/source/as_restore.h
	src/angelscript/include/source/as_scriptcode.cpp
	src/angelscript/include/source/as_scriptcode.h
	src/angelscript/include/source/as_scriptengine.cpp
	src/angelscript/include/source/as_scriptengine.h
	src/angelscript/include/source/as_scriptfunction.cpp
	src/angelscript/include/source/as_scriptfunction.h
	src/angelscript/include/source/as_scriptnode.cpp
	src/angelscript/include/source/as_scriptnode.h
	src/angelscript/include/source/as_scriptobject.cpp
	src/angelscript/include/source/as_scriptobject.h
	src/angelscript/include/source/as_string.cpp
	src/angelscript/include/source/as_string.h
	src/angelscript/include/source/as_string_util.cpp
	src/angelscript/include/source/as_string_util.h
	src/angelscript/include/source/as_symboltable.h
	src/angelscript/include/source/as_texts.h
	src/angelscript/include/source/as_thread.cpp
	src/angelscript/include/source/as_thread.h
	src/angelscript/include/source/as_tokendef.h
	src/angelscript/include/source/as_tokenizer.cpp
	src/angelscript/include/source/as_tokenizer.h
	src/angelscript/include/source/as_typeinfo.cpp
	src/angelscript/include/source/as_typeinfo.h
	src/angelscript/include/source/as_variablescope.cpp
	src/angelscript/include/source/as_variablescope.h

	src/angelscript/include/scriptbuilder/scriptbuilder.cpp
	src/angelscript/include/scriptbuilder/scriptbuilder.h

	src/angelscript/include/scriptstdstring/scriptstdstring.cpp
	src/angelscript/include/scriptstdstring/scriptstdstring.h
)

set(CHTTPM_SOURCE
	src/chttpm/main.cpp

	src/chttpm/request.cpp
	src/chttpm/request.h

	src/chttpm/scripting/bindrequest.cpp
	src/chttpm/scripting/bindrequest.h
	src/chttpm/scripting/scriptingservice.cpp
	src/chttpm/scripting/scriptingservice.h
)


##############################################################
#                                                            #
# The following segments were copied from angel script cmake #
# The contents have been slightly edited.                    #
#                                                            #
##############################################################

if(MSVC AND CMAKE_CL_64)
	enable_language(ASM_MASM)
	if(CMAKE_ASM_MASM_COMPILER_WORKS)
		set(ANGELSCRIPT ${ANGELSCRIPT} 
			src/angelscript/include/source/as_callfunc_x64_msvc_asm.asm
		)
	else()
		message(FATAL ERROR "MSVC x86_64 target requires a working assembler")
	endif()
endif()

if(${CMAKE_SYSTEM_PROCESSOR} MATCHES "^arm")
	enable_language(ASM)
	if(CMAKE_ASM_COMPILER_WORKS)
		set(ANGELSCRIPT ${ANGELSCRIPT} 
			src/angelscript/include/source/as_callfunc_arm.cpp 
			src/angelscript/include/source/as_callfunc_arm_gcc.S
		)
		set_property(SOURCE 
			src/angelscript/include/source/as_callfunc_arm_gcc.S APPEND PROPERTY COMPILE_FLAGS " -Wa,-mimplicit-it=always"
		)
	else()
		message(FATAL ERROR "ARM target requires a working assembler")
	endif()
endif()

if(MSVC)
	set(CMAKE_DEBUG_POSTFIX "d")  
endif()


######################################################
#                                                    #
# End of segment copied from angel script cmake file #
#                                                    #
######################################################

find_package(Threads)

add_executable(chttpm
	${CPP_HTTPLIB}
	${ANGELSCRIPT}
	${CHTTPM_SOURCE}
)

#############################################################
# Another short segment copied from angel script cmake file #
#############################################################
if(MSVC)
	target_compile_definitions(chttpm PRIVATE -D_CRT_SECURE_NO_WARNINGS)    
endif()

target_compile_definitions(chttpm PRIVATE -DANGELSCRIPT_EXPORT -D_LIB)

if(AS_NO_EXCEPTIONS)
	target_compile_definitions(chttpm PRIVATE AS_NO_EXCEPTIONS)
endif()

# Fix x64 issues on Linux
if("${CMAKE_SYSTEM_PROCESSOR}" STREQUAL "x86_64" AND UNIX AND NOT APPLE)
	target_compile_options(chttpm PRIVATE -fPIC)
endif()


if(MSVC)
	set_target_properties(chttpm PROPERTIES COMPILE_FLAGS "/MP")
endif()

#############################################################
#############################################################

target_link_libraries(chttpm
	Threads::Threads
)

set_target_properties(chttpm
	PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRE ON
	ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
	LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
	RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

target_include_directories(
	chttpm PUBLIC
	src/cpp-httplib
	src/angelscript/include
)