find_package(Qt5Core)
find_package(Qt5Widgets)
add_library (Block block.cpp)
target_link_libraries(Block Qt5::Widgets Qt5::Core)
