set(tsrc
    test.cpp
    test_to_chars.cpp
    test_from_chars.cpp
)

# general test
add_executable(mscharconv-test
    ${tsrc}
)
target_link_libraries(mscharconv-test mscharconv)
set_target_properties(mscharconv-test PROPERTIES FOLDER test)
add_test(NAME mscharconv COMMAND mscharconv-test)

# advanced usage test
add_executable(mscharconv-test-fwd
    ${tsrc}
    charconv_impl.cpp
)
target_link_libraries(mscharconv-test-fwd mscharconv)
target_compile_definitions(mscharconv-test-fwd PRIVATE -DMSCHARCONV_FWD_INCLUDE=1)
set_target_properties(mscharconv-test-fwd PROPERTIES FOLDER test)
add_test(NAME mscharconv-fwd COMMAND mscharconv-test-fwd)

# shared lib test
add_library(mscharconv-test-lib SHARED charconv_impl.cpp)
target_compile_definitions(mscharconv-test-lib PUBLIC -DMSCHARCONV_SHARED=1 -DMSCHARCONV_FWD_INCLUDE=1)
target_link_libraries(mscharconv-test-lib PUBLIC mscharconv)
if(NOT WIN32)
    target_compile_options(mscharconv-test-lib PRIVATE -fvisibility=hidden)
endif()
set_target_properties(mscharconv-test-lib PROPERTIES FOLDER test)

add_executable(mscharconv-test-exe
    ${tsrc}
)
target_link_libraries(mscharconv-test-exe mscharconv-test-lib)
set_target_properties(mscharconv-test-exe PROPERTIES FOLDER test)
add_test(NAME mscharconv-shared COMMAND mscharconv-test-exe)
