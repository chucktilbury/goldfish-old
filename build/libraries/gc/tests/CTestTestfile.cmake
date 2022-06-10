# CMake generated Testfile for 
# Source directory: /home/chuck/Src/goldfish/libraries/gc/tests
# Build directory: /home/chuck/Src/goldfish/build/libraries/gc/tests
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(gctest "/home/chuck/Src/goldfish/bin/gctest")
set_tests_properties(gctest PROPERTIES  _BACKTRACE_TRIPLES "/home/chuck/Src/goldfish/libraries/gc/tests/CMakeLists.txt;27;ADD_TEST;/home/chuck/Src/goldfish/libraries/gc/tests/CMakeLists.txt;0;")
add_test(hugetest "/home/chuck/Src/goldfish/bin/hugetest")
set_tests_properties(hugetest PROPERTIES  _BACKTRACE_TRIPLES "/home/chuck/Src/goldfish/libraries/gc/tests/CMakeLists.txt;31;ADD_TEST;/home/chuck/Src/goldfish/libraries/gc/tests/CMakeLists.txt;0;")
add_test(leaktest "/home/chuck/Src/goldfish/bin/leaktest")
set_tests_properties(leaktest PROPERTIES  _BACKTRACE_TRIPLES "/home/chuck/Src/goldfish/libraries/gc/tests/CMakeLists.txt;35;ADD_TEST;/home/chuck/Src/goldfish/libraries/gc/tests/CMakeLists.txt;0;")
add_test(middletest "/home/chuck/Src/goldfish/bin/middletest")
set_tests_properties(middletest PROPERTIES  _BACKTRACE_TRIPLES "/home/chuck/Src/goldfish/libraries/gc/tests/CMakeLists.txt;39;ADD_TEST;/home/chuck/Src/goldfish/libraries/gc/tests/CMakeLists.txt;0;")
add_test(realloc_test "/home/chuck/Src/goldfish/bin/realloc_test")
set_tests_properties(realloc_test PROPERTIES  _BACKTRACE_TRIPLES "/home/chuck/Src/goldfish/libraries/gc/tests/CMakeLists.txt;43;ADD_TEST;/home/chuck/Src/goldfish/libraries/gc/tests/CMakeLists.txt;0;")
add_test(smashtest "/home/chuck/Src/goldfish/bin/smashtest")
set_tests_properties(smashtest PROPERTIES  _BACKTRACE_TRIPLES "/home/chuck/Src/goldfish/libraries/gc/tests/CMakeLists.txt;47;ADD_TEST;/home/chuck/Src/goldfish/libraries/gc/tests/CMakeLists.txt;0;")
