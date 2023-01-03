# Chapter 1
add_executable(IsUnique chapt1/isunique.cpp)
add_executable(CheckPermutation chapt1/checkpermutation.cpp)
add_executable(URLify chapt1/urlify.cpp)
add_executable(PalindromePermutation chapt1/palindrome.cpp)
add_executable(OneAway chapt1/oneaway.cpp)
add_executable(StringCompression chapt1/stringcompression.cpp)
add_executable(RotateMatrix chapt1/rotatematrix.cpp)
add_executable(ZeroMatrix chapt1/zeromatrix.cpp)
add_executable(StringRotation chapt1/stringrotation.cpp)

# Chapter 2
#Add lib files
add_subdirectory(lib)

# Add executable with the linkedlist library from 'lib' folder


add_executable(RemoveDuplicates chapt2/removedups.cpp)
add_executable(KthFromLast chapt2/kthfromlast.cpp)
add_executable(DeleteMiddleNode chapt2/deletemiddlenode.cpp)
add_executable(Partition chapt2/partition.cpp)
add_executable(SumLists chapt2/sumlists.cpp)
add_executable(Palindrome chapt2/palindrome.cpp)
add_executable(Intersection chapt2/intersection.cpp)
add_executable(LoopDetection chapt2/loopdetection.cpp)

target_link_libraries(RemoveDuplicates CTCILIB)
target_link_libraries(KthFromLast CTCILIB)
target_link_libraries(DeleteMiddleNode CTCILIB)
target_link_libraries(Partition CTCILIB)
target_link_libraries(SumLists CTCILIB)
target_link_libraries(Palindrome CTCILIB)
target_link_libraries(Intersection CTCILIB)
target_link_libraries(LoopDetection CTCILIB)

add_executable(StackMin chapt3/stackmin.cpp)
add_executable(StackOfPlates chapt3/stackofplates.cpp)
add_executable(QueueViaStacks chapt3/stackqueues.cpp)
add_executable(SortStack chapt3/sortstack.cpp)

target_link_libraries(StackMin CTCILIB)
target_link_libraries(StackOfPlates CTCILIB)
target_link_libraries(QueueViaStacks CTCILIB)
target_link_libraries(SortStack CTCILIB)