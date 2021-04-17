add_executable(mscharconv-test test.cpp)
target_link_libraries(mscharconv-test mscharconv)
set_target_properties(mscharconv-test PROPERTIES FOLDER test)
add_test(NAME mscharconv COMMAND mscharconv-test)
