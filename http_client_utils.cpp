#include <cstdio>
#include <string>
#include <http_client_utils.hpp>

std::string int2str(int n) {
	char* _str = new char[0x100];
	::sprintf(_str, "%u", n);
	delete _str;
	return std::string(_str);
}

inline bool is_digit(char ch) {return ('0' <= ch && ch <= '9');}
int str2int(const std::string& src) {
	int n = 0;
	uint32_t p = 0;
	bool _signed = (src[0] == '-');
	
	while(!is_digit(src[p])) ++p;
	for(p=(_signed ? ++p : p); is_digit(src[p]); ++p)
		n = (n * 10) + (src[p] - '0');
	
	if(_signed) n *= -1;
	return n;
}
