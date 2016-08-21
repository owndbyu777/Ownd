#include "OwndConversions.h"
#include <sstream>

namespace OWND {
	std::string intToString(int i) {
		std::istringstream istr;
		istr >> i;
		return istr.str();
	}
}