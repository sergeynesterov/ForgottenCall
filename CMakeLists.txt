cmake_minimum_required( VERSION 3.13 )
project( ForgottenCall VERSION 1.0.0 LANGUAGES NONE )

# -----------------------------------------------------------------------------
# Set up project configuration
option( BUILD_SHARED_LIBS "Global flag to create shared libraries if on" ON )
option( BUILD_TESTING "Enable tests" ON )

if( NOT CMAKE_BUILD_TYPE )
   set( CMAKE_BUILD_TYPE Debug
      CACHE STRING "Choose build type: Debug, Release, RelWithDebInfo, MinSizeRel." FORCE
   )
   message( STATUS "Build type not defined. Using default build type 'Debug'." )
endif()

set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )
enable_language( CXX )

include( GNUInstallDirs )
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR} )
set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR} )
# -----------------------------------------------------------------------------

# -----------------------------------------------------------------------------
# Find required packages
set( ENV{PKG_CONFIG_PATH} "$ENV{PKG_CONFIG_PATH}:/usr/local/lib64/pkgconfig" )
find_package( PkgConfig )

find_package( Boost REQUIRED )

pkg_check_modules( DLT REQUIRED automotive-dlt )
add_library( automotive-dlt INTERFACE )
target_link_libraries( automotive-dlt INTERFACE ${DLT_LIBRARIES} )
target_link_options( automotive-dlt INTERFACE -L${DLT_LIBDIR}/static )
target_include_directories( automotive-dlt SYSTEM INTERFACE ${DLT_INCLUDEDIR} )
target_compile_definitions( automotive-dlt INTERFACE ${DLT_CFLAGS_OTHER} )
add_library( Automotive::DLT ALIAS automotive-dlt )

if( BUILD_TESTING )
   enable_testing()
   find_package( GTest REQUIRED )
endif()
# -----------------------------------------------------------------------------

# -----------------------------------------------------------------------------
# Source code
add_subdirectory( src )
if( BUILD_TESTING )
   add_subdirectory( test )
endif()
# -----------------------------------------------------------------------------

# -----------------------------------------------------------------------------
# Game resources
add_subdirectory( resources )
# -----------------------------------------------------------------------------