#include <iostream>
namespace Prog3_1 {

	class Set {
	private:
		static const int MAX = 100;
		int size;
		char arr[MAX];
	public:
		Set();
		Set(int);
		Set(const char*);
		Set(const Set&);
		~Set() { std::cout << "desstructor for  " << this << std::endl; }

		void setSize(int);
		void setARR(char*);

		int getSize() const { return size; }
		int getMaxSize() const { return MAX; }
		void getARR() const { for (int i = 0; i < this->size; std::cout << this->arr[i], i++); std::cout << std::endl; }


		friend Set& summ(Set&, Set&);
		friend Set& multiplication(Set&, Set&);
		friend Set& subtraction(Set&, Set&);
		void push();

		int add_el(const char);
		int find_el(const char);
		void checkSize(int);
	};

	int getNaturalInt(int*);
	int dialog(const char* [], int);
	int dialog_summ(Set&, Set&, Set&);
	int dialog_summ_char(Set&, Set&, Set&);
	int dialog_multiplication(Set&, Set&, Set&);
	int dialog_subtraction(Set&, Set&, Set&);
	int dialog_set_message(Set&, Set&, Set&);
	int dialog_get_arr(Set&, Set&, Set&);
}

