#include <cstring>

#include "smbios.h"

auto smbios::dmi_string(
	const smbios::dmi_header* dm, BYTE src
) -> const char*
{
	std::size_t length{};
	std::size_t i{};

	char* bp = (char*)dm;
	//reinterpret_cast<char*> (dm);

	if (src == 0) { return "Not specified"; }
	bp += dm->length;

	while (src > 1 && *bp) {
		bp += std::strlen(bp);
		bp++;
		src--;
	}

	if (!*bp) { return "BAD_INDEXING"; }



	//
	// filtering ASCII
	// removal of junk data
	//

	length = std::strlen(bp);
	for (int i = 0; i < length; i++) {
		if (bp[i] < 32 || bp[i] == 127) { bp[i] = '.'; }
	}
	return bp;

}