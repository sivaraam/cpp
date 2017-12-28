#include <iostream>
#include <cstring>
#include <algorithm>

using std::cout;
using std::cin;

int main() {
	char *s = "abcdef123@#$";
//	char *span="qwertyuiopasdfghjklzxcvbnm";
	char *span="0987654321";
	char *cspan_1="!@#$%^&*()_-+=}{[]:;\"'|\<,>.?/|\~`";
	char *cspan_2="1234567890!@#$%^&*()_-+=}{[]:;\"'|\<,>.?/|\~`";

	std::cout<<"strspn: First "<<std::strspn(s, span)<<" charactrers of 's' are characters of 'span'"<<'\n';
	std::cout<<"strcspn: First "<<std::strcspn(s, cspan_1)<<" charactrers of 's' are NOT characters of 'cspan_1'"<<'\n';
	std::cout<<"strcspn: First "<<std::strcspn(s, cspan_2)<<" charactrers of 's' are NOT characters of 'cspan_2'"<<'\n';

//	std::sort(span, span+strlen(span)-1);

	std::string span_str (span);

//	std::copy
	std::sort(span_str.begin(), span_str.end());

	std::cout<<"Sorted span: "<<span_str<<'\n';

}
