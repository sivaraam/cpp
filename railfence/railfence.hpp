#include <string>

namespace railfence {
	std::string encrypt(std::string p_text, unsigned group_chars);
	std::string decrypt(std::string c_text, unsigned group_chars);
}
