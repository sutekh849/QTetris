include_directories("../Block")
find_package(Qt5Core)
set(EXTRA_LIBS ${EXTRA_LIBS} Block)
set(CMAKE_AUTOMOC true)
add_library(Shape shape.cpp)
target_link_libraries(Shape Block Qt5::Core)

