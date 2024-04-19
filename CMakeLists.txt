# Minimum required version of CMake
cmake_minimum_required(VERSION 3.12)

# Project name
project(Calculatrice_Matrice)

# Set C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find the gtkmm package
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM REQUIRED gtkmm-3.0)

# Ajouter les chemins d'inclusion de gtkmm
include_directories(${GTKMM_INCLUDE_DIRS})

# Ajouter les chemins de bibliothèques de gtkmm
link_directories(${GTKMM_LIBRARY_DIRS})

# Ajouter les drapeaux de compilation de gtkmm
add_definitions(${GTKMM_CFLAGS_OTHER})

# Set the source files
set(SOURCES
    sources/main.cpp
    sources/matrice.cpp
    sources/interface.cpp
)

# Set the header files
set(HEADERS
    headers/matrice.h
    headers/interface.h
)

# Add executable for your main code
add_executable(calculatriceMatrice_CPP ${SOURCES} ${HEADERS})

# Specify the include directories and link libraries for the main executable
target_include_directories(calculatriceMatrice_CPP PRIVATE ${GTKMM_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR}/headers)
target_link_libraries(calculatriceMatrice_CPP PRIVATE ${GTKMM_LIBRARIES})
target_compile_options(calculatriceMatrice_CPP PRIVATE ${GTKMM_CFLAGS_OTHER})