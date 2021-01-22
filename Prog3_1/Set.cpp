#define _CRT_SECURE_NO_WARNINGS
#include "Set.h"

namespace prog3_3 {

	Set::Set() : size(0), arr(nullptr) {
		std::cout << "constructor for " << this << std::endl;
	}

	Set::Set(int size) {
		std::cout << "constructor for " << this << std::endl;
		this->checkSize(size);
		this->size = size;
		this->arr = new char[size];
		for (int i = 0; i < size; this->arr[i] = 32 + i, i++);
	}

	Set::Set(const char* arr) : size(0) {
		std::cout << "constructor for " << this << std::endl;
		for (this->size = 0; arr[this->size]; this->size++);
		this->arr = new char[this->size];
		for (int i = 0; arr[i];
			!this->find_el(arr[i]) ? this->arr[i] = arr[i] : throw std::invalid_argument("Duplicate an element \n"),
			i++, this->size = i);
	}

	Set::Set(const Set& other) {
		std::cout << "copy for   " << this << std::endl;
		this->size = other.size;
		this->arr = new char[this->size];
		for (int i = 0; i < other.size; this->arr[i] = other.arr[i], i++);
	}

	Set::~Set() {
		std::cout << "desstructor for  " << this << std::endl;
		if (this->arr != nullptr) {
			delete[] this->arr;
			this->arr = nullptr;
		}
		this->size = 0;
	}



	void Set::setSize(int size) {
		this->checkSize(size);
		this->size = size;
	}

	void Set::setARR(char* arr) {
		if (this->arr != nullptr) {
			delete[] this->arr;
			this->arr = nullptr;
		}

		for (this->size = 0; arr[this->size]; this->size++);
		this->arr = new char[this->size];

		for (int i = 0; arr[i];
			!this->find_el(arr[i]) ? this->arr[i] = arr[i] : throw std::exception("Duplicate an element str#60 \n"),
			i++);
	}

	Set Set::operator + (const Set& other) {
		Set Str(*this);
		for (int i = 0; i < other.size; i++)
			if (!Str.find_el(other.arr[i]))
				Str += other.arr[i];
		return Str;
	}

	Set& Set::operator += (const char a) {
		if (this->find_el(a))
			throw std::exception("Duplicate an element #str74 \n");
		this->add_el(a);
		return *this;
	}

	Set operator * (const Set& right, Set& left) {
		Set Str;
		int i;
		for (i = 0; i < right.size;
			left.find_el(right.arr[i]) ? Str += right.arr[i], i++ : i++);
		return Str;
	}

	Set& Set::operator = (const Set& other) {
		if (this->arr != nullptr) {
			delete[] this->arr;
			this->arr = nullptr;
		}
		this->size = other.size;
		for (int i = 0; i < other.size; this->add_el(other.arr[i]), i++);
		return *this;
	}

	Set operator - (Set& right, Set& left) {
		int i, j;
		Set Str;
		for (i = 0, j = 0; i < left.size;
			!right.find_el(left.arr[i]) ? Str += left.arr[i], j++, i++ : i++);
		Str.size = j;
		return Str;
	}

	std::ostream& operator << (std::ostream& s, const Set& other) {
		other.getARR();
		return s;
	}

	std::istream& operator >> (std::istream& s, Set& other) {
		try {
			char b = '\n';
			other.size = 0;
			while (b == '\n')
				b = std::cin.get();
			do {
				other.add_el(b);
				b = std::cin.get();
			} while (b != '\n');
			return s;
		}
		catch (std::exception& ex) {
			std::cout << ex.what();
			std::cin.ignore(INT_MAX, '\n');
			std::cin.clear();
		}
	}


	int Set::add_el(const char el) {
		char* a;
		int i;
		if (this->arr) {
			if (this->find_el(el))
				throw std::exception("Duplicate an element str#119 \n");
			a = new char[this->size];
			for (i = 0; i < this->size; a[i] = this->arr[i], i++);
			delete[] this->arr;
			this->arr = nullptr;

			this->arr = new char[this->size + 1];
			for (i = 0; i < this->size; this->arr[i] = a[i], i++);
			delete[] a;
			a = nullptr;

			this->arr[i] = el;
			this->size++;
		}
		else {
			this->arr = new char[1];
			this->arr[0] = el;
			this->size = 1;
		}
		return 0;
	}

	int Set::find_el(const char el) {
		for (int i = 0; i != this->size; i++)
			if (this->arr[i] == el)
				return 1;
		return 0;
	}

	void Set::checkSize(int size) {
		if (size < 0)
			throw std::exception("Invalid size! str#167");
	}

	int getNaturalInt(int* a) {
		do {
			std::cin >> *a;
			if (*a < 0)
				return 0;
			if (*a == 0 || *a < 0) {
				std::cout << "Error! Please, repeat your input: ";
				std::cin.clear();
				std::cin.ignore(INT_MAX, '\n');
			}
		} while (*a == 0 || *a < 0);
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

	int dialogSumm(Set& S1, Set& S2, Set& S3) {
		S3 = S1 + S2;
		std::cout << "Your resolting massege:" << S3 << std::endl;
		return 1;
	}

	int dialogSummChar(Set& S1, Set& S2, Set& S3) {
		char a;
		std::cout << "Add char to set1" << std::endl << "Enter char:";
		std::cin >> a;
		S1 += a;
		std::cout << "Your resolting massege:" << S3 << std::endl;
		return 1;
	}

	int dialogMultiplication(Set& S1, Set& S2, Set& S3) {
		S3 = S1 * S2;
		std::cout << "Your resolting massege:" << S3 << std::endl;
		return 1;
	}

	int dialogSubtraction(Set& S1, Set& S2, Set& S3) {
		S3 = S1 - S2;
		std::cout << "Your resolting massege:" << S3 << std::endl;
		return 1;
	}

	int dialogSetMessage(Set& S1, Set& S2, Set& S3) {
		std::cout << "Enter massedge for set1:";
		std::cin >> S1;
		std::cout << "Enter massege for set2:";
		std::cin >> S2;
		return 1;
	}

	int dialogGetArr(Set& S1, Set& S2, Set& S3) {
		std::cout << "Enter massege for set1:";
		S1.getARR();
		std::cout << "Enter massege for set2:";
		S2.getARR();
		std::cout << std::endl;
		return 1;
	}
}