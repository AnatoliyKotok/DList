#pragma once
#include<iostream>
using namespace std;
template<typename T> 
class D_list
{
public:
	D_list() = default;
	bool isEmpty()const;
	void addhead(const T& data);
	void addTeil(const T& data);
	void printL()const;
	void printR()const;
	void dTeil();
	void dHead();
	void insertBefor(const T& serch, const T& newData);
	void insertAfter(const T& serch, const T& newData);
	void redact(const T& serch, const T& newData);
	void dAll();
	struct Node;
	
	class Iterator {
	public:
		Iterator( Node * ptr) :ptr(ptr) {}
		T& operator*() {
			return ptr->data;
		}
		void operator++() {
			ptr = ptr->next;
		}
		bool operator!=(const Iterator& other) {
			return ptr != other.ptr;
		}
	private:
		Node* ptr;
	};
	Iterator begin() {
		return head;
	}
	Iterator end() {
		return tail->next;
	}
	class RIterator {
	public:
		RIterator(Node* ptr=nullptr) :ptr(ptr) {}
		T& operator*() {
			return ptr->data;
		}
		void operator++() {
			
				ptr = ptr->prev;
			
		}
		bool operator!=(const RIterator& other) {
			return ptr != other.ptr;
		}
	private:
		Node* ptr;
	};
	RIterator rbegin() {
		return tail;
	}
	RIterator rend() {
		return RIterator(0);
	}
private:
	auto findNode(const T& serch);
	struct Node {
		T data = T();
		Node* next = nullptr, * prev = nullptr;
	};
	Node* head = nullptr, * tail = nullptr;
	size_t size = 0;
	
	
};

template<typename T>
inline bool D_list<T>::isEmpty() const
{
	return head==nullptr;
}

template<typename T>
inline void D_list<T>::addhead(const T& data)
{
	Node* addNode = new Node{ data };
	if (isEmpty()) {
		head = tail = addNode;
	}
	else {
		addNode->next = head;
		head->prev = addNode;
		head = addNode;
	}
	++size;
}

template<typename T>
inline void D_list<T>::addTeil(const T& data)
{
	Node* addNode = new Node{ data };
	if (isEmpty()) {
		tail = head = addNode;
	}
	else {
		tail->next = addNode;
		tail = addNode;
	}
	++size;
}

template<typename T>
inline void D_list<T>::printL() const
{
	auto tmp = head;
	while (tmp != nullptr) {
		cout << tmp->data << "\t";
		tmp = tmp->next;
	}
	cout << endl;
}

template<typename T>
inline void D_list<T>::printR() const
{
	auto tmp = tail;
	while (tmp != nullptr) {
		cout << tmp->data << "\t";
		tmp = tmp->prev;
	}
	cout << endl;
}

template<typename T>
inline void D_list<T>::dTeil()
{
	if (isEmpty()) 
		return;
	if (head == tail) {
		delete head;
		head = tail = nullptr;
	}
	else{
		tail->prev->next = nullptr;
		Node* tmp = tail;
		tail = tail->prev;
		delete tmp;

	}
	--size;

}
template<typename T>
inline void D_list<T>::dHead()
{
	if (isEmpty()) {
		return;
	}
	if (head == tail) {
		delete head;
		head = tail = nullptr;
	}
	else {
		Node* tmp = head;
		head = head->next;
		delete tmp;
	}
	--size;
}
template<typename T>
inline void D_list<T>::insertBefor(const T& serch,const T& newData)
{
	auto serchNode = findNode(serch);
	if (serchNode == nullptr)
		return;
	if (serchNode == head) {
		addhead(newData);
		return;
	}
	auto insNode = new Node{ newData,serchNode,serchNode->prev };
	serchNode->prev->next = insNode;
	serchNode->prev = insNode;
	++size;
}
template<typename T>
inline void D_list<T>::insertAfter(const T& serch, const T& newData)
{
	auto SerchNode = findNode(serch);
	if (SerchNode == nullptr)
		return;
	if (SerchNode == head) {
		addhead(newData);
		return;
	}
	if (SerchNode == tail) {
		addTeil(newData);
		return;
	}
	auto isNode = new Node{ newData,SerchNode,SerchNode->next };
	SerchNode->next->prev = isNode;
	SerchNode->prev = isNode;
	++size;
}

template<typename T>
inline void D_list<T>::redact(const T& serch, const T& newData)
{
	Node* tmp;
	auto SerchNode = findNode(serch);
	if (SerchNode == nullptr)
		return;
	if (SerchNode == head) {
		tmp = head;
		tmp->data= newData;
		
		return;
	}
	if (SerchNode == tail) {
		tmp = tail;
		tmp->data = newData;
		
		return;
	}
	auto isNode = new Node{ newData,SerchNode };
	tmp = isNode;
	tmp->data = newData;
	
}



template<typename T>
inline void D_list<T>::dAll()
{

	if (isEmpty()) 
		return;
	while (!isEmpty()) {
		dHead();
	}
}
template<typename T>
inline auto D_list<T>::findNode(const T& serch)
{
	auto tmp = head;
	while (tmp != nullptr && tmp->data != serch) 
		tmp = tmp->next;
	return tmp;
	
}
