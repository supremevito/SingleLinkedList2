#include <iostream>
#include <stdexcept>
#define eleType double
using namespace std;

struct ListNode {
	eleType data;
	ListNode* next;
	ListNode(eleType x) :data(x), next(nullptr){}
};

class LinkedList {
private:
	ListNode* head;
	int size;
public:
	LinkedList():head(nullptr),size(0){}
	~LinkedList();
	void insert(int index, eleType value);
	void remove(int index);
	ListNode* find(eleType value);
	ListNode* get(int index);
	void update(int index, eleType value);
	void print();
};

LinkedList::~LinkedList(){
	ListNode* curr = head;
	while (curr) {
		ListNode* temp = curr;
		curr = curr->next;
		delete temp;
	}
}

void LinkedList::insert(int index,eleType value){
	if (index<0||index>size) {
		throw std::out_of_range("Invalid Position");
	}
	ListNode* newNode = new ListNode(value);
	if (index == 0) {
		newNode->next = head;
		head = newNode;
	}
	else {
		ListNode* curr = head;
		for (int j = 0; j < index - 1; j++) {
			curr = curr->next;
		}
		newNode->next = curr->next;
		curr->next=newNode;
	}
	size++;
}

void LinkedList::remove(int index) {
	if(index<0||index>=size){
		throw std::out_of_range("Invalid Position");
	}
	if (index == 0) {
		ListNode* temp = head;
		head = temp->next;
		delete temp;
	}
	else {
		ListNode* curr = head;
		for (int j = 0; j < index - 1; j++) {
			curr = curr->next;
		}
		ListNode* temp = curr->next;
		curr->next = temp->next;
		delete temp;
	}
	size--;
}

ListNode* LinkedList::find(eleType value) {
	ListNode* curr = head;
	while (curr != nullptr && curr->data!=value) {
		curr = curr->next;
	}
	return curr;
}

ListNode* LinkedList::get(int index) {
	if (index < 0 || index >= size) {
		throw std::out_of_range("Invalid Postition");
	}
	ListNode* curr = head;
	for (int j = 0; j < index; j++) {
		curr = curr->next;
	}
	return curr;
}

void LinkedList::update(int index, eleType value) {
	if (index < 0 || index >= size) {
		throw std::out_of_range("Invalid Position");
	}
	get(index)->data = value;
}

void LinkedList::print() {
	ListNode* curr = head;
	while (curr) {
		cout << curr->data << " ";
		curr = curr->next;
	}
	cout << endl;
}

int main() {
	LinkedList vlist;
	for (int i = 0; i < 10; i++) {
		vlist.insert(i,i*10);
	}

	vlist.print();
	cout << vlist.find(50)->data << endl;
	cout << vlist.get(2)->data << endl;
	vlist.print();
	vlist.update(2, 222);
	vlist.print();
	vlist.remove(4);
	vlist.print();

}