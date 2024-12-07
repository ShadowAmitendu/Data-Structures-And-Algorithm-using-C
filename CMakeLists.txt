cmake_minimum_required(VERSION 3.30)
project(Data_Structures_And_Algorithm_using_C C)

set(CMAKE_C_STANDARD 11)

include_directories(doublyLinkedList)
include_directories(linkedLists)
include_directories(Matrix)
include_directories(Searching)
include_directories(Sorting)

add_executable(Data_Structures_And_Algorithm_using_C
    doublyLinkedList/mainMenuDDL.c
    linkedLists/countNodes.c
    linkedLists/delete.c
    linkedLists/display.c
    linkedLists/insert.c
    linkedLists/isNull.c
    linkedLists/linkedlist.h
    linkedLists/sorting.c
    Matrix/sparceMatrix.c
    Searching/binarySearch.c
    Searching/linearSearch.c
    "Sorting/bubbleSort - Modified.c"
    Sorting/bubbleSort.c
    Sorting/selectionSort.c
    "circularLinkedList - Sir.c"
    "doublyLinkedList - Sir.c"
    mainMenu.c
    "singlyLinkedList - Sir.c"
    "sLL - EleminateDuplicate.c"
    "sLL - Reverse.c"
    "sLL - SoringinASC.c")
