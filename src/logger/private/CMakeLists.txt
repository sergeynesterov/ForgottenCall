add_library( logger OBJECT EXCLUDE_FROM_ALL Logger.cpp CDltLoggerContext.cpp )
target_include_directories( logger PUBLIC ${PROJECT_SOURCE_DIR}/src )
target_link_libraries( logger PUBLIC Automotive::DLT )

add_library( FC::Logger ALIAS logger )
