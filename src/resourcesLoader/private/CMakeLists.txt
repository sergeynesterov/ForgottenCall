add_library( loader OBJECT EXCLUDE_FROM_ALL ContentLoader.cpp)
target_include_directories( loader PUBLIC ${PROJECT_SOURCE_DIR}/src )
target_link_libraries( loader stdc++fs FC::Logger )

add_library( FC::ContentLoader ALIAS loader )