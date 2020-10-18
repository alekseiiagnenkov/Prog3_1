#define _CRT_SECURE_NO_WARNINGS
#include "Set.h"

namespace prog3_1 {

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
				!this->find_el(arr[i]) ? this->arr_[i] = arr[i] : throw std::exception("Duplicate an element! str#21"),
				i++, this->size_ = i);
	}

	Set::Set(const Set& other) {
		std::cout << "copy for   " << this << std::endl;
		this->size_ = other.size_;
		for (int i = 0; other.arr_[i]; this->arr_[i] = other.arr_[i], i++);
	}



	void Set::setSize(int size) {
		this->checkSize(size);
		this->size_ = size;
	}

	void Set::setARR(char* arr) {
		this->size_ = 0;
		for (int i = 0; arr[i];
			!this->find_el(arr[i]) ? this->arr_[i] = arr[i] : throw std::exception("Duplicate an element!"),
			i++, this->size_ = i);
	}



	Set& summ(Set& left, Set& right)
	{
		Set Str;
		Str.size_ = left.size_;
		for (int i = 0; left.arr_[i]; Str.arr_[i] = left.arr_[i], i++);


		for (int i = 0; i < right.size_;
			!Str.find_el(right.arr_[i]) ? Str.arr_[Str.size_] = right.arr_[i], Str.size_ += 1, i++ : i++);
		return Str;
	}

	Set& multiplication(Set& left, Set& right) {
		Set Str;
		int j, i;
		for (i = 0, j = 0; i < right.size_;
			left.find_el(right.arr_[i]) ? Str.arr_[j] = right.arr_[i], j++, i++ : i++);
		Str.size_ = j;
		return Str;
	}

	Set& subtraction(Set& left, Set& right) {
		int i, j;
		Set Str;
		for (i = 0, j = 0; i < left.size_;
			!right.find_el(left.arr_[i]) ? Str.arr_[j] = left.arr_[i], j++, i++ : i++);
		Str.size_ = j;
		return Str;
	}

	void Set::push() {
		try {
			char b = '\n';
			this->size_ = 0;
			while (b == '\n')
				b = std::cin.get();
			do {
				this->add_el(b);
				b = std::cin.get();
			} while (b != '\n');
		}
		catch (std::exception& ex) {
			std::cout << ex.what() << std::endl;
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
		}
	}



	int Set::add_el(const char el) {
		int i;
		for (i = 0; i < this->size_; !this->find_el(el) ? i++ : throw std::exception("Duplicate an element! str#100"));
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
			throw std::exception("Invalid size! str#115");
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
		S3 = summ(S1, S2);
		std::cout << "Your resolting message:";
		S3.getARR();
		std::cout << std::endl;
		return 1;
	}

	int dialogSummChar(Set& S1, Set& S2, Set& S3) {
		char a;
		std::cout << "Add char to set1" << std::endl << "Enter char:";
		std::cin >> a;
		S1.add_el(a);
		std::cout << "Your resolting massege:";
		S1.getARR();
		std::cout << std::endl;
		return 1;
	}

	int dialogMultiplication(Set& S1, Set& S2, Set& S3) {
		S3 = multiplication(S1, S2);
		std::cout << "Your resolting massege:";
		S3.getARR();
		std::cout << std::endl;
		return 1;
	}

	int dialogSubtraction(Set& S1, Set& S2, Set& S3) {
		S3 = subtraction(S1, S2);
		std::cout << "Your resolting massege:";
		S3.getARR();
		std::cout << std::endl;
		return 1;
	}

	int dialogSetMessage(Set& S1, Set& S2, Set& S3) {
			std::cout << "Enter message for set1:";
			S1.push();
			std::cout << "Enter message for set2:";
			S2.push();
			return 1;
	}

	int dialogGetArr(Set& S1, Set& S2, Set& S3) {
		std::cout << "Str1: ";
		S1.getARR();
		std::cout << "Str2: ";
		S2.getARR();
		return 1;
	}
}