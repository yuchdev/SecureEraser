# Parent project does not export its library target, so this CML implicitly
# depends on being added from it, i.e. the testing is done only from the build
# tree and is not feasible from an install location

project(FunctionalTests LANGUAGES CXX)

# ---- Tests ----

add_executable(functional_test functional_test/functional_test.cpp)
target_compile_features(functional_test PRIVATE cxx_std_17)
add_test(NAME functional_test COMMAND functional_test)

# ---- End-of-file commands ----

add_folders(Test)
