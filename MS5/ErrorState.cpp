#include <cstring>
#include <iostream>
#include "ErrorState.h"

#define _CRT_SECURE_NO_WARNINGS



AMA::ErrorState::ErrorState(const char * errorMessage)
{
	if (errorMessage == nullptr) {
		error = nullptr;
	}
	else {
		error = new char[std::strlen(errorMessage) + 1];
		strcpy(error, errorMessage);
	}
}

AMA::ErrorState::~ErrorState()
{
	clear();
}

void AMA::ErrorState::clear()
{
	if (error != nullptr) {
		
		delete[] error;
		error = nullptr;
	}
	
}

bool AMA::ErrorState::isClear() const
{
	if (error == nullptr) {
		return true;
	}
	else {
		return false;
	}

}

void AMA::ErrorState::message(const char * str)
{
	clear();
	error = new char[std::strlen(str) + 1];
	strcpy(error, str);

}

const char * AMA::ErrorState::message() const
{
	return error;
}

std::ostream & AMA::operator<<(std::ostream & os, const ErrorState & errorstate)
{
	if (!errorstate.isClear())  {
		os << errorstate.message();
		return os;
	}
	
	// TODO: insert return statement here
	return os;
}


