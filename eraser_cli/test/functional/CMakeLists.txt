# Parent project does not export its library target, so this CML implicitly
# depends on being added from it, i.e. the testing is done only from the build
# tree and is not feasible from an install location
set(TARGET eraser_functional_test)

find_package(Boost ${BOOST_MIN_VERSION} COMPONENTS unit_test_framework date_time REQUIRED) 

file(GLOB SOURCES functional_test.cpp)
 
include_directories(
    ${Boost_INCLUDE_DIRS}
)

add_executable(${TARGET} ${SOURCES})
target_link_libraries(${TARGET} 
PRIVATE 
    ${Boost_LIBRARIES} 
)

add_test(NAME ${TARGET} COMMAND ${TARGET})
set_property(TARGET ${TARGET} PROPERTY FOLDER "UnitTests")
