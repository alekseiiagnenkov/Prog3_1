#include <iostream>
namespace prog3_2 {

	class Set {
	private:
		static const int MAX = 100;
		int size_;
		char arr_[MAX];
	public:
		Set();
		Set(int);
		Set(const char*);
		Set(const Set&);

		~Set() { std::cout << "desstructor for  " << this << std::endl; }


		void setSize(int);
		void setARR(char*);


		int getSize() const { return size_; }
		int getMaxSize() const { return MAX; }
		//const char* getARR() const { return arr; }
		void getARR() const { for (int i = 0; i < this->size_; std::cout << this->arr_[i], i++); std::cout << std::endl; }

		friend Set& operator + (Set&, Set&);
		//Set& operator + (const Set&);
		Set& operator += (const char);
		friend Set& operator * (const Set&, Set&);
		friend Set& operator - (Set&, Set&);
		friend std::ostream& operator << (std::ostream&, const Set&);
		friend std::istream& operator >> (std::istream&, Set&);


		int add_el(const char);
		int find_el(const char);
		void checkSize(int);
	};

	int getNaturalInt(int*);
	int dialog(const char* [], int);
	int dialogSumm(Set&, Set&, Set&);
	int dialogSummChar(Set&, Set&, Set&);
	int dialogMultiplication(Set&, Set&, Set&);
	int dialogSubtraction(Set&, Set&, Set&);
	int dialogSetMessage(Set&, Set&, Set&);
	int dialogGetArr(Set&, Set&, Set&);
}
