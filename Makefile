FlattenMultiLevelLinkedList: FlattenMultiLevelLinkedList.o
	g++ -g -o FlattenMultiLevelLinkedList.exe FlattenMultiLevelLinkedList.o -pthread    

FlattenMultiLevelLinkedList.o: FlattenMultiLevelLinkedList/FlattenMultiLevelLinkedList.cpp
	g++ -g  -c -pthread FlattenMultiLevelLinkedList/FlattenMultiLevelLinkedList.cpp
