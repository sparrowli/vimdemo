#ifndef _SPARROW_STRING_H_
#define _SPARROW_STRING_H_

#include <string.h>
class SparrowString {
private:
	const char* c_string_;
	const SparrowString& operator=(const SparrowString& rhs);

public:
	static const char* CloneCString(const char* a_c_string);

	SparrowString() : c_string_(NULL) {}

	explicit SparrowString(const char* a_c_string) : c_string_(NULL) {
		Set(a_c_string);
	}

	SparrowString(const SparrowString& string) : c_string_(NULL) {
		Set(string.c_string_);
	}

	~SparrowString() { delete[] c_string_; }

	const char* c_string() const { return c_string_; }

	size_t Length() const {
		return c_string_ == NULL ? 0 : strlen(c_string_);
	}

	void Set(const char* a_c_string);
};
#endif // _SPARROW_STRING_H_
