cmake_minimum_required (VERSION 3.0)
include("GNUInstallDirs")

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(PluginName "BinaryInfo")

find_package(Qt5 5.0.0 REQUIRED Widgets)

add_library(${PluginName} SHARED
	BinaryInfo.cpp
	BinaryInfo.h
	demangle.h
	DialogHeader.cpp
	DialogHeader.h
	DialogHeader.ui
	ELF32.cpp
	ELF64.cpp
	ELFXX.cpp
	OptionsPage.cpp
	OptionsPage.h
	OptionsPage.ui
	PE32.cpp
	PE32.h
	symbols.cpp
	symbols.h
)

target_link_libraries(${PluginName} Qt5::Widgets PE ELF)

set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR})
install (TARGETS ${PluginName} DESTINATION ${CMAKE_INSTALL_LIBDIR}/edb)

set_property(TARGET ${PluginName} PROPERTY CXX_EXTENSIONS OFF)
set_property(TARGET ${PluginName} PROPERTY CXX_STANDARD 14)

add_subdirectory(libELF)
add_subdirectory(libPE)
