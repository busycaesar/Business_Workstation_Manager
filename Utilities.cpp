// Name: DEV JIGISHKUMAR SHAH
// Seneca Student ID: 131623217
// Seneca email: djshah11@myseneca.ca
// Date of completion: 16/11/2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include"Utilities.h"

namespace sdds
{

	char Utilities::d_delimiter = '\n';

	std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more)
	{

		// VARIABLE DECLARATION.
		std::string data = str;
		size_t next_delimiter = 0;

		more = false;

		if (str[next_pos] == d_delimiter) throw std::invalid_argument("Invalid argument!");

		if (next_pos) data = str.substr(next_pos);

		next_delimiter = data.find_first_of(d_delimiter);

		if (next_delimiter && next_delimiter < data.size())
		{

			next_pos += next_delimiter + 1;
			data = get_data_till(data, d_delimiter);
			more = true;

		}

		if (d_width_field < data.size())d_width_field = data.size();

		trim_word(data);

		return data;

	}

	void trim_word(std::string& f_word)
	{

		// VARAIBLE DECLARATION.
		size_t length = f_word.size() - 1;

		if (is_string_empty(f_word)) f_word = "";
		else
		{

			// THIS WILL TRIM ALL THE SPACES AFTER THE WORD.
			while ((f_word[length] == ' ') && length < f_word.size())
			{

				f_word = f_word.substr(0, length);
				length--;

			}

			// THIS WILL TRIM ALL THE SPACES BEFORE THE WORD.
			while (f_word[0] == ' ')f_word.erase(0, 1);

		}

	}

	std::string get_data_till(std::string& f_data, const char f_delim)
	{

		// VARIABLE DECLARATION.
		size_t t_position = 0;
		std::string t_temp = "";

		// THIS WILL FIND THE INDEX OF DELIM FROM THE STRING.
		t_position = f_data.find(f_delim);

		if (t_position)
		{

			// THIS WILL STORE THE COMMA SEPERATED DATA IN THE VARIABLE.
			t_temp = f_data.substr(0, t_position);

			// THIS WILL TRIM THE DATA.
			trim_word(t_temp);

			// THIS WILL ERASE THE COMMA SEPERATED DATA FROM THE MAIN DATA.
			f_data.erase(0, t_position + 1);

		}
		else { f_data.erase(0, 1); }

		return t_temp;

	}

	bool is_string_empty(std::string string)
	{

		// VARIABLE DECLARATION.
		size_t empty_places = 0;

		for (size_t i = 0; i < string.size(); i++)
		{

			if (string[i] == ' ') empty_places++;

		}

		return empty_places == string.size();

	}

	size_t find_next_position_of(std::string data, const char delimiter)
	{

		//VARIABLE DECLARATION.
		size_t position = data.find_first_of(delimiter);

		get_data_till(data, delimiter);

		position += data.find_first_of(delimiter);

		return position;

	}

}