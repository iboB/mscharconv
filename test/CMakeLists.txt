add_executable(mscharconv-test
    test.cpp
    test_to_chars.cpp
    test_from_chars.cpp
)
target_link_libraries(mscharconv-test mscharconv)
set_target_properties(mscharconv-test PROPERTIES FOLDER test)
add_test(NAME mscharconv COMMAND mscharconv-test)
