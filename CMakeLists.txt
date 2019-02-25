cmake_minimum_required(VERSION 3.1.0)
set_property(GLOBAL PROPERTY USE_FOLDERS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project(nctest)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT BUILD_TYPEINFO_IMPL_RTTI)
  if(MSVC)
    add_compile_options(/GR-)
  else()
    add_compile_options(-fno-rtti)
  endif()
endif()

# enable all warnings
if(MSVC)
  add_compile_options(/W4)
else()
  add_compile_options(-Wall -Wextra -Wpedantic)

  # fix the code for this
  add_compile_options(-Wno-unused-parameter)
  add_compile_options(-Wno-ignored-qualifiers)
endif()

# force visual studio and the like to only have debug and release builds
if(CMAKE_CONFIGURATION_TYPES)
  set(CMAKE_CONFIGURATION_TYPES Debug Release)
  set(CMAKE_CONFIGURATION_TYPES "${CMAKE_CONFIGURATION_TYPES}"
    CACHE STRING "Reset the configurations to what we need" FORCE)
endif()

set(CURSES_NEED_NCURSES True)
find_package(Curses REQUIRED)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(SYSTEM ${CMAKE_CURRENT_BINARY_DIR})
include_directories(SYSTEM ${CURSES_INCLUDE_DIR})

add_executable(app main.cc)

target_link_libraries(app ${CURSES_LIBRARIES})

