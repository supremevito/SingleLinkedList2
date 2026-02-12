#include <iostream>
#include <stdexcept>
#define eleType double
using namespace std;

struct ListNode {
	eleType data;
	eleType* next;
	ListNode(eleType x) :data(x), next(nullptr){}
};

class LinkedList {
private:

};