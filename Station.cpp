// Name: DEV JIGISHKUMAR SHAH
// Seneca Student ID: 131623217
// Seneca email: djshah11@myseneca.ca
// Date of completion: 16/11/2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include"Station.h"

namespace sdds
{

	void Station::m_set_empty()
	{

		d_station_id = 0;
		d_item_name = "";
		d_description = "";
		d_next_serial_number = 0;
		d_items_in_stock = 0;

	}

	size_t Station::d_width_field = 0;
	size_t Station::d_id_generator = 1;

	Station::Station(const std::string& data)
	{

		// VARIABLE DECLARATION.
		Utilities for_extraction;
		bool is_extracted = false;
		size_t position = 0;

		m_set_empty();

		try
		{

			d_station_id = Station::d_id_generator;
			Station::d_id_generator++;

			d_item_name = for_extraction.extractToken(data, position, is_extracted);
			d_next_serial_number = std::stoi(for_extraction.extractToken(data, position, is_extracted));
			d_items_in_stock = std::stoi(for_extraction.extractToken(data, position, is_extracted));

			if (Station::d_width_field < for_extraction.getFieldWidth())Station::d_width_field = for_extraction.getFieldWidth();

			d_description = for_extraction.extractToken(data, position, is_extracted);

		}
		catch (std::invalid_argument& error) { throw error; }

	}

	void Station::display(std::ostream& os, bool full) const
	{

		os << std::setw(3) << std::setfill('0') << std::right << d_station_id
			<< " | " << std::setw(d_width_field) << std::setfill(' ') << std::left << d_item_name << "  | "
			<< std::setw(6) << std::right << std::setfill('0') << d_next_serial_number << " | ";
		
		if (full)
		{

			os << std::setw(4) << std::setfill(' ') << std::right << d_items_in_stock << " | "
				<< d_description;
		
		}
		
		os << std::endl;

	}

}