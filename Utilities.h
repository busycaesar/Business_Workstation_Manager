// Name: DEV JIGISHKUMAR SHAH
// Seneca Student ID: 131623217
// Seneca email: djshah11@myseneca.ca
// Date of completion: 16/11/2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H

#include<iostream>
#include<string>

namespace sdds
{

	// CLASS.
	class Utilities
	{

		// CLASS NAME AND PURPOSE.
		// NAME: UTILITIES
		// PURPOSE: PARSING THE STRING DATA FROM INPUT FILES AND OTHER BASIC FUNCTIONALITY.

		// DATA MEMBERS.
		size_t d_width_field;
		static char d_delimiter;

		// METHODS.
		void m_set_empty() { d_width_field = 1; }

	public:

		// METHODS.

		// CONSTRUCTORS AND DESTRUCTOR.
		Utilities() { m_set_empty(); }

		// OPERATORS.

		// QUERIES.
		size_t getFieldWidth() const { return d_width_field; }
		static char m_get_delimiter() { return d_delimiter; }

		// METHODS.
		void m_set_field_width(size_t arg_new_width) { d_width_field = arg_new_width; }
		std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
		static void setDelimiter(char new_delimiter) { d_delimiter = new_delimiter; }

		// HELPER FUNCTIONS.

	};

	// FUNCTIONS.

	// ARGUMENT : STRING.
	// RETURNS  : TRIMMED STRING.
	// FUNCTION : TRIMS THE SPACE FROM THE FRONT AND BACK OF THE STRING.
	void trim_word(std::string& f_word);

	// ARGUMENT : STRING, DELIM CHARACER
	// RETURNS  : TRIMMED STRING TILL THE FIRST DELIM CHARACTER.
	// FUNCTION : ERASE THE DATA TILL THE FIRST DELIM CHARACTER FROM THE STRING.
	std::string get_data_till(std::string& f_data, const char f_delim = '\n');

	// FUNCTION : THIS WILL RETURN TRUE IF THE STRING IS EMPTY AND VISE-VERSA. 
	bool is_string_empty(std::string string);

	size_t find_next_position_of(std::string data, const char delimiter);

}

#endif // !SDDS_UTILITIES_H
