add_executable( UT_example UT_example.cpp )
target_link_libraries( UT_example GTest::GTest GTest::Main )

gtest_discover_tests( UT_example )