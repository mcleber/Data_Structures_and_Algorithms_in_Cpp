cmake_minimum_required(VERSION 3.20)

project(DataStructures)

add_executable(DataStructures
    #"simple_search.cpp"
    #"binary_search.cpp"
    #"stack.cpp"
    #"queue.cpp"
    #"bubble_sort.cpp"
    #"insertion_sort.cpp"
    #"selection_sort.cpp"
    #"quick_sort.cpp"
    #"shell_sort.cpp"
    #"merge_sort.cpp"
    #"sequential_list_operations.cpp"
    "linked_list_operations.cpp"
)

set_target_properties(DataStructures PROPERTIES CXX_STANDARD 23)
