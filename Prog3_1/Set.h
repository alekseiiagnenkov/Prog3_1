#include <iostream>
namespace prog3_3 {

	class Set {
	private:
		int size;
		char* arr;
	public:
		Set();
		Set(int);
		Set(const char*);
		Set(const Set&);
		~Set();


		void setSize(int);
		void setARR(char*);


		int getSize() const { return size; }
		//const char* getARR() const { return arr; }
		void getARR() const { for (int i = 0; i < this->size; std::cout << this->arr[i], i++); std::cout << std::endl; }


		Set operator + (const Set&);
		Set& operator += (const char);
		friend Set operator * (const Set&, Set&);
		friend Set operator - (Set&, Set&);
		Set& operator = (const Set& other);
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