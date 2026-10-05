cmake_minimum_required(VERSION 3.20)

cmake_policy(SET CMP0072 NEW)

project(nemark LANGUAGES C CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#------------------------
# DIRECTORIES
#------------------------

set(SRC_DIR         "${CMAKE_SOURCE_DIR}/src")
set(ENGINE_DIR      "${SRC_DIR}/nemark_engine")
set(EDITOR_DIR      "${SRC_DIR}/tools/nemark_editor")
set(SANDBOX_DIR     "${SRC_DIR}/sandbox")
set(MAPPER_DIR      "${SRC_DIR}/tools/hinge_mapper")

set(DEPENDENCIES_DIR "${ENGINE_DIR}/dependencies")
set(LIB_DIR          "${DEPENDENCIES_DIR}/lib")
set(INCLUDE_DIR      "${DEPENDENCIES_DIR}/include")

#------------------------
# GLFW
#------------------------

if(WIN32)
    add_library(glfw STATIC IMPORTED)

    set_target_properties(glfw PROPERTIES
        IMPORTED_LOCATION
            "${LIB_DIR}/glfw3.lib"

        INTERFACE_INCLUDE_DIRECTORIES
            "${INCLUDE_DIR}"
    )

    set(GLFW_TARGET glfw)
else()
    find_package(glfw3 REQUIRED)

    if(TARGET glfw)
        set(GLFW_TARGET glfw)
    elseif(TARGET glfw3::glfw)
        set(GLFW_TARGET glfw3::glfw)
    else()
        message(FATAL_ERROR
            "GLFW was found, but no usable GLFW target exists."
        )
    endif()
endif()

#------------------------
# GLAD
#------------------------

set(GLAD_SOURCE "${ENGINE_DIR}/core/glad.c")

if(NOT EXISTS "${GLAD_SOURCE}")
    message(FATAL_ERROR
        "Could not find glad.c at:\n"
        "  ${GLAD_SOURCE}"
    )
endif()

add_library(glad STATIC
    "${GLAD_SOURCE}"
)

target_include_directories(glad
    PUBLIC
        "${INCLUDE_DIR}"
)

#------------------------
# IMGUI
#------------------------

set(IMGUI_DIR "${INCLUDE_DIR}/imgui")

add_library(imgui STATIC
    "${IMGUI_DIR}/imgui.cpp"
    "${IMGUI_DIR}/imgui_draw.cpp"
    "${IMGUI_DIR}/imgui_tables.cpp"
    "${IMGUI_DIR}/imgui_widgets.cpp"
    "${IMGUI_DIR}/imgui_demo.cpp"

    "${IMGUI_DIR}/imgui_impl_glfw.cpp"
    "${IMGUI_DIR}/imgui_impl_opengl3.cpp"
)

target_include_directories(imgui
    PUBLIC
        "${IMGUI_DIR}"
)

target_compile_definitions(imgui
    PRIVATE
        IMGUI_IMPL_OPENGL_LOADER_GLAD
)

target_link_libraries(imgui
    PUBLIC
        ${GLFW_TARGET}
        glad
)

#------------------------
# GLM
#------------------------

set(GLM_DIR "${INCLUDE_DIR}/glm")

if(NOT EXISTS "${GLM_DIR}")
    message(WARNING
        "GLM was not found at:\n"
        "  ${GLM_DIR}\n"
        "Make sure GLM is installed in the dependencies/include directory."
    )
endif()

#------------------------
# ENGINE
#------------------------

file(GLOB_RECURSE ENGINE_SOURCES CONFIGURE_DEPENDS
    "${ENGINE_DIR}/*.cpp"
)

add_library(nemark STATIC
    ${ENGINE_SOURCES}
)

target_include_directories(nemark
    PUBLIC
        "${SRC_DIR}"
        "${DEPENDENCIES_DIR}"
)

if(EXISTS "${GLM_DIR}")
    target_include_directories(nemark
        PUBLIC
            "${INCLUDE_DIR}"
    )
endif()

target_link_libraries(nemark
    PUBLIC
        imgui
        glad
        ${GLFW_TARGET}
)

#------------------------
# EDITOR
#------------------------

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
        nemark
)

#------------------------
# HINGE MAPPER
#------------------------

file(GLOB_RECURSE MAPPER_SOURCES CONFIGURE_DEPENDS
    "${MAPPER_DIR}/*.cpp"
)

add_executable(hinge_mapper
    ${MAPPER_SOURCES}
)

target_include_directories(hinge_mapper
    PRIVATE
        "${SRC_DIR}"
)

target_link_libraries(hinge_mapper
    PRIVATE
        nemark
)

#------------------------
# SANDBOX
#------------------------

file(GLOB_RECURSE SANDBOX_SOURCES CONFIGURE_DEPENDS
    "${SANDBOX_DIR}/*.cpp"
)

add_executable(sandbox
    ${SANDBOX_SOURCES}
)

target_include_directories(sandbox
    PRIVATE
        "${SRC_DIR}"
)

target_link_libraries(sandbox
    PRIVATE
        nemark
)

#------------------------
# COMPILER WARNINGS
#------------------------

if(MSVC)
    target_compile_options(nemark PRIVATE /W4)
    target_compile_options(nemark_editor PRIVATE /W4)
    target_compile_options(hinge_mapper PRIVATE /W4)
    target_compile_options(sandbox PRIVATE /W4)
else()
    target_compile_options(nemark PRIVATE -Wall -Wextra -Wpedantic)
    target_compile_options(nemark_editor PRIVATE -Wall -Wextra -Wpedantic)
    target_compile_options(hinge_mapper PRIVATE -Wall -Wextra -Wpedantic)
    target_compile_options(sandbox PRIVATE -Wall -Wextra -Wpedantic)
endif()
