// Name: DEV JIGISHKUMAR SHAH
// Seneca Student ID: 131623217
// Seneca email: djshah11@myseneca.ca
// Date of completion: 16/11/2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_STATION_H
#define SDDS_STATION_H

#include<string>
#include"Utilities.h"
#include<iomanip>

namespace sdds
{

	//CLASS.
	class Station
	{

		// CLASS NAME AND PURPOSE.
		// NAME: STATION
		// PURPOSE: STILL FIGURING OUT.

	// DATA MEMBERS.

		// INSTANCE VARIABLES.
		size_t d_station_id, d_next_serial_number, d_items_in_stock;
		std::string d_item_name, d_description;

		// CLASS VARAIBLES.
		static size_t d_width_field, d_id_generator;

		// METHOD.
		void m_set_empty();

	public:

		// METHODS.

		// CONSTRUCTORS AND DESTRUCTOR.
		Station() { m_set_empty(); }
		Station(const std::string& data);

		// OPERATORS.

		// QUERIES.
		const std::string& getItemName() const { return d_item_name; }
		size_t getNextSerialNumber();
		size_t getQuantity() const { return d_items_in_stock; }

		// METHODS.
		void updateQuantity() { if (d_items_in_stock > 1)d_items_in_stock--; }
		void display(std::ostream& os, bool full) const;

		// HELPER FUNCTIONS.

	};

}

#endif // !SDDS_STATION_H
