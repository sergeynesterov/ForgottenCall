add_executable( ${PROJECT_NAME} main.cpp )
target_link_libraries( ${PROJECT_NAME} FC::Logger FC::ContentLoader Boost::boost )