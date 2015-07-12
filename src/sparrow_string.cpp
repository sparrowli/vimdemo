#include "sparrow_string.h"

const char* SparrowString::CloneCString(const char* a_c_string)
{
	if (a_c_string == NULL) return NULL;

	const size_t len = strlen(a_c_string);
	char* const clone = new char[ len + 1 ];
	memcpy(clone, a_c_string, len + 1);

	return clone;
}
void SparrowString::Set(const char* a_c_string)
{
	const char* const temp = CloneCString(a_c_string);
	delete[] c_string_;
	c_string_ = temp;
}
