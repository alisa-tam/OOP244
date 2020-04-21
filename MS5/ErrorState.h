#ifndef _SICT_ERRORSTATE_H
#define _SICT_ERRORSTATE_H

#include <iostream>

namespace AMA {

	class ErrorState {
	private:
		char* error;
	
	public:

		explicit ErrorState(const char* errorMessage = nullptr);

		ErrorState(const ErrorState& em) = delete; //don't need to implement, telling the compiler not to automatically make this constructor
													//cannot assign this class

		ErrorState& operator=(const ErrorState& em) = delete;
		//doing these three together means you cannot copy the class

		virtual ~ErrorState();

		void clear();

		bool isClear() const;

		void message(const char* str);

		const char* message() const;


	};

	std::ostream& operator<<(std::ostream&, const ErrorState&);
}
#endif
