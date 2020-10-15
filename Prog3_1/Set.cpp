#define _CRT_SECURE_NO_WARNINGS
#include "Set.h"

namespace Prog3_1 {

	Set::Set() : size(0) {
		std::cout << "constructor for " << this << std::endl;
		for (int i = 0; i < size; this->arr[i] = 32 + i, i++);
	}

	Set::Set(int size) {
		std::cout << "constructor for " << this << std::endl;
		this->checkSize(size);
		this->size = size;
		for (int i = 0; i < size; this->arr[i] = 32 + i, i++);
	}

	Set::Set(const char* arr) : size(0) {
		std::cout << "constructor for " << this << std::endl;
		for (int i = 0; arr[i];
			!this->find_el(arr[i]) ? this->arr[i] = arr[i] : throw std::invalid_argument("Duplicate an element"),
			i++, this->size = i);
	}

	//Set::Set(const Set& other) {
	//	std::cout << "copy for   " << this << std::endl;
	//	this->size = other.size;
	//	for (int i = 0; other.arr[i]; this->arr[i] = other.arr[i], i++);
	//}



	void Set::setSize(int size) {
		this->checkSize(size);
		this->size = size;
	}

	void Set::setARR(char* arr) {
		this->size = 0;
		for (int i = 0; arr[i];
			!this->find_el(arr[i]) ? this->arr[i] = arr[i] : throw std::invalid_argument("Duplicate an element"),
			i++, this->size = i);
	}



	Set& summ(Set& left, Set& right)
	{
		//Set Str(left);
		Set Str;
		Str.size = left.size;
		for (int i = 0; left.arr[i]; Str.arr[i] = left.arr[i], i++);


		for (int i = 0; i < right.size;
			!Str.find_el(right.arr[i]) ? Str.arr[Str.size] = right.arr[i], Str.size += 1, i++ : i++);
		return Str;
	}

	Set& multiplication(Set& left, Set& right) {
		Set Str;
		int j, i;
		for (i = 0, j = 0; i < right.size;
			left.find_el(right.arr[i]) ? Str.arr[j] = right.arr[i], j++, i++ : i++);
		Str.size = j;
		return Str;
	}

	Set& subtraction(Set& left, Set& right) {
		int i, j;
		Set Str;
		for (i = 0, j = 0; i < left.size;
			!right.find_el(left.arr[i]) ? Str.arr[j] = left.arr[i], j++, i++ : i++);
		Str.size = j;
		return Str;
	}

	void Set::push() {
		try {
			char a[100];
			std::cin >> a;
			this->setARR(a);
		}
		catch (std::exception& ex) {
			std::cout << ex.what();
		}
	}



	int Set::add_el(const char el) {
		int i;
		for (i = 0; i < this->size; !this->find_el(el) ? i++ : throw std::invalid_argument("Duplicate an element"));
		this->arr[i] = el;
		this->size++;
		return 0;
	}

	int Set::find_el(const char el) {
		for (int i = 0; i != this->size; i++)
			if (this->arr[i] == el)
				return 1;
		return 0;
	}

	void Set::checkSize(int size) {
		if (size > this->MAX || size < 0)
			throw std::invalid_argument("Invalid size");
	}

	int getNaturalInt(int* a) {
		int n;
		do {
			n = scanf("%d", a);
			if (n < 0)
				return 0;
			if (n == 0 || *a < 0) {
				printf("%s\n", "Error! Please, repeat your input: ");
				scanf("%*[^\n]");
			}
		} while (n == 0 || *a < 0);
		return 1;
	}



	int dialog(const char* msgs[], int N) {
		std::string errmsg;
		int rc;
		do {
			std::cout << errmsg;
			errmsg = "You are wrong. Repeat, please\n";
			for (int j = 0; j < N; ++j)
				puts(msgs[j]);
			std::cout << "Make your choice:";

			if (getNaturalInt(&rc) == 0) { rc = 0; }
		} while (rc < 0 || rc >= N);
		return rc;
	}

	int dialog_summ(Set& Set1, Set& Set2, Set& Set3) {
		Set3 = summ(Set1, Set2);
		std::cout << "Your resolting massege:";
		Set3.getARR();
		std::cout << std::endl;
		return 1;
	}

	int dialog_summ_char(Set& Set1, Set& Set2, Set& Set3) {
		char a;
		std::cout << "Add char to set1" << std::endl << "Enter char:";
		std::cin >> a;
		Set1.add_el(a);
		std::cout << "Your resolting massege:";
		Set1.getARR();
		std::cout << std::endl;
		return 1;
	}

	int dialog_multiplication(Set& Set1, Set& Set2, Set& Set3) {
		Set3 = multiplication(Set1, Set2);
		std::cout << "Your resolting massege:";
		Set3.getARR();
		std::cout << std::endl;
		return 1;
	}

	int dialog_subtraction(Set& Set1, Set& Set2, Set& Set3) {
		Set3 = subtraction(Set1, Set2);
		std::cout << "Your resolting massege:";
		Set3.getARR();
		std::cout << std::endl;
		return 1;
	}

	int dialog_set_message(Set& Set1, Set& Set2, Set& Set3) {
		std::cout << "Enter massedge for set1:";
		Set1.push();
		std::cout << "Enter massedge for set2:";
		Set2.push();
		return 1;
	}

	int dialog_get_arr(Set& Set1, Set& Set2, Set& Set3) {
		std::cout << "Str1: ";
		Set1.getARR();
		std::cout << "Str2: ";
		Set2.getARR();
		return 1;
	}
}