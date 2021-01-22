#define _CRT_SECURE_NO_WARNINGS
#include "Set.h"

namespace prog3_2 {

	Set::Set() : size_(0) {
		std::cout << "constructor for " << this << std::endl;
		for (int i = 0; i < size_; this->arr_[i] = 32 + i, i++);
	}

	Set::Set(int size) {
		std::cout << "constructor for " << this << std::endl;
		this->checkSize(size);
		this->size_ = size;
		for (int i = 0; i < size; this->arr_[i] = 32 + i, i++);
	}

	Set::Set(const char* arr) : size_(0) {
		std::cout << "constructor for " << this << std::endl;
		for (int i = 0; arr[i];
			!this->find_el(arr[i]) ? this->arr_[i] = arr[i] : throw std::exception("Duplicate an element! str#21 \n"),
			i++, this->size_ = i);
	}

	Set::Set(const Set& other) {
		std::cout << "copy for   " << this << std::endl;
		this->size_ = other.size_;
		for (int i = 0; i < other.size_; this->arr_[i] = other.arr_[i], i++);
	}



	void Set::setSize(int size) {
		this->checkSize(size);
		this->size_ = size;
	}

	void Set::setARR(char* arr) {
		this->size_ = 0;
		for (int i = 0; arr[i];
			!this->find_el(arr[i]) ? this->arr_[i] = arr[i] : throw std::invalid_argument("Duplicate an element \n"),
			i++, this->size_ = i);
	}


	Set& operator + (Set& left, Set& right) {
		Set Str(left);
		for (int i = 0; i < right.size_;
			!left.find_el(right.arr_[i]) ? Str.arr_[Str.size_] = right.arr_[i], Str.size_ += 1, i++ : i++);
		return Str;
	}

	//Set& Set::operator + (const Set& other) {
	//	Set Str(*this);
	//	for (int i = 0; i < other.size_;
	//		!Str.find_el(other.arr_[i]) ? Str.arr_[Str.size_] = other.arr_[i], Str.size_ += 1, i++ : i++);
	//	return Str;
	//}

	Set& Set::operator += (const char a) {
		this->add_el(a);
		return *this;
	}

	Set& operator * (const Set& right, Set& left) {
		Set Str;
		int j, i;
		for (i = 0, j = 0; i < right.size_;
			left.find_el(right.arr_[i]) ? Str.arr_[j] = right.arr_[i], j++, i++ : i++);
		Str.size_ = j;
		return Str;
	}

	Set& operator - (Set& right, Set& left) {
		int i, j;
		Set Str;
		for (i = 0, j = 0; i < left.size_;
			!right.find_el(left.arr_[i]) ? Str.arr_[j] = left.arr_[i], j++, i++ : i++);
		Str.size_ = j;
		return Str;
	}

	std::ostream& operator << (std::ostream& s, const Set& other) {
		other.getARR();
		return s;
	}

	//std::istream& operator >> (std::istream& s, Set& other) {
	//	std::cin >> other.arr;
	//	int i;
	//	for (i = 0; other.arr[i]; i++);
	//	other.size = i;
	//	return s;
	//}

	std::istream& operator >> (std::istream& s, Set& other) {
		try {
			char b = '\n';
			other.size_ = 0;
			while (b == '\n')
				b = std::cin.get();
			do {
				other.add_el(b);
				b = std::cin.get();
			} while (b != '\n');
		}
		catch (std::exception& ex) {
			std::cout << ex.what();
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
		}
		return s;
	}


	int Set::add_el(const char el) {
		int i;
		for (i = 0; i < this->size_; !this->find_el(el) ? i++ : throw std::exception("Duplicate an element str#119 \n"));
		this->arr_[i] = el;
		this->size_++;
		return 0;
	}

	int Set::find_el(const char el) {
		for (int i = 0; i != this->size_; i++)
			if (this->arr_[i] == el)
				return 1;
		return 0;
	}

	void Set::checkSize(int size) {
		if (size > this->MAX || size < 0)
			throw std::exception("Invalid size! str#134 \n");
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
		std::cout << "Enter massedge for set2:";
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