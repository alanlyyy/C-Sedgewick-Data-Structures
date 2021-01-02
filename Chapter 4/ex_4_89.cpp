#include "String_mod.h"

int main_4_89() {

	String ms(1);
	String ms2(2);

	char myarr[] = "alphabet_soup";
	char myarr2[] = " peanut butter soup";

	//test insert char[] into String object.
	ms.insert_entire_string(myarr, (sizeof(myarr) / sizeof(myarr[0])));
	ms2.insert_entire_string(myarr2, (sizeof(myarr2) / sizeof(myarr2[0])));

	//test string equality and string size
	std::cout << (ms == ms2) << std::endl;
	std::cout << ms.get_string_size() << std::endl;
	std::cout << ms2.get_string_size() << std::endl;

	std::cout << "ms: " << std::endl;
	ms.print_string();

	std::cout << "ms2: " << std::endl;
	ms2.print_string();

	//test string concatenation
	std::cout << "ms + ms2: " << std::endl;
	ms += ms2;
	ms.print_string();


	std::cout << ms.get_string_size() << std::endl;


	//test deleting char at arbitrary position
	ms.delete_char(10);
	ms.delete_char(10);
	ms.print_string();

	std::cout << ms.get_string_size() << std::endl;


	//test copy constructor
	String ms3 = ms2;

	std::cout << "ms3: " << std::endl;
	ms3.print_string();

	return 0;
}