cmake_minimum_required(VERSION 3.20)

cmake_policy(SET CMP0072 NEW)

project(nemark LANGUAGES C CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SRC_DIR "${CMAKE_SOURCE_DIR}/src")

set(ENGINE_DIR "${SRC_DIR}/nemark_engine")
set(EDITOR_DIR "${SRC_DIR}/tools/nemark_editor")
#set(MAPPER_DIR "${SRC_DIR}/tools/mapper")

set(DEPENDENCIES_DIR "${ENGINE_DIR}/dependencies")
set(LIB_DIR "${DEPENDENCIES_DIR}/lib")
set(INCLUDE_DIR "${DEPENDENCIES_DIR}/include")


#------------------------
# DEPENDENCIES
#------------------------

#--GLFW--

if(WIN32)
    add_library(glfw STATIC IMPORTED)

    set_target_properties(glfw PROPERTIES 
        IMPORTED_LOCATION
            "${LIB_DIR}/glfw3.lib"
        INTERFACE_INCLUDE_DIRECTORIES 
            "${INCLUDE_DIR}"
    )
    set(OPENGL_GLFW_TARGET glfw)
else()
    find_package(glfw3 REQUIRED)

    if(TARGET glfw)
        set(OPENGL_GLFW_TARGET glfw)
    else()
        set(OPENGL_GLFW_TARGET glfw3::glfw)
    endif()
endif()

#--ImGui--

add_library(imgui STATIC
    ${INCLUDE_DIR}/imgui/imgui.cpp
    ${INCLUDE_DIR}/imgui/imgui_draw.cpp
    ${INCLUDE_DIR}/imgui/imgui_tables.cpp
    ${INCLUDE_DIR}/imgui/imgui_widgets.cpp
    ${INCLUDE_DIR}/imgui/imgui_demo.cpp

    ${INCLUDE_DIR}/imgui/imgui_impl_glfw.cpp
    ${INCLUDE_DIR}/imgui/imgui_impl_opengl3.cpp
)

target_include_directories(imgui PUBLIC
    ${INCLUDE_DIR}/imgui
)
target_compile_definitions(imgui PRIVATE
    IMGUI_IMPL_OPENGL_LOADER_GLAD
)
target_link_libraries(imgui PUBLIC ${OPENGL_GLFW_TARGET})

#--Glad--

if(EXISTS "${ENGINE_DIR}/core/glad.c")
    add_library(glad STATIC "${ENGINE_DIR}/core/glad.c")
else()
    message(FATAL_ERROR "Could not find glad.c in 'src/nemark_engine/core/glad.c', please make sure glad.c is located there :]")
endif()

target_include_directories(glad
    PUBLIC
        "${INCLUDE_DIR}"
)

#--GLM--

##WHAT THE FICKL

#------------------------
# ENGINE
#------------------------

file(GLOB_RECURSE ENGINE_SOURCES CONFIGURE_DEPENDS
    "${ENGINE_DIR}/*.cpp"
)

add_library(nemark_engine STATIC
    ${ENGINE_SOURCES}
)

target_include_directories(nemark_engine
    PUBLIC
        "${DEPENDENCIES_DIR}"
)

target_link_libraries(nemark_engine
    PUBLIC
        imgui
        glad
        glfw
        #glm
)

#------------------------
# EXECUTABLES
#------------------------

#--Editor

file(GLOB_RECURSE EDITOR_SOURCES CONFIGURE_DEPENDS
    "${EDITOR_DIR}/*.cpp"
)

add_executable(nemark_editor
    ${EDITOR_SOURCES}
)

target_include_directories(nemark_editor
    PRIVATE
        "${SRC_DIR}"
)

target_link_libraries(nemark_editor
    PRIVATE
        nemark_engine
)

#--Mapper