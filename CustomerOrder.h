// Name: DEV JIGISHKUMAR SHAH
// Seneca Student ID: 131623217
// Seneca email: djshah11@myseneca.ca
// Date of completion: 25/11/2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_CUSTOMERORDER_H
#define SDDS_CUSTOMERORDER_H

#include<string>
#include"Station.h"
#include"Utilities.h"
#include<vector>

namespace sdds
{

	// STRUCT.
	struct Item
	{

		// VARIABLE DECLARATION.
		std::string d_item_name;
		size_t d_serial_number{ 0 };
		bool d_is_filled{ false };

		Item(const std::string& src) : d_item_name(src) {};

	};

	// CLASS.
	class CustomerOrder
	{

		// CLASS NAME AND PURPOSE.
		// NAME: CUSTOMER ORDER
		// PURPOSE: THIS CLASS MANAGES THE ORDERS OF EACH CUSTOMERS.

		// DATA MEMBERS.

		// INSTANCE VARIABLES.
		std::string	d_customer_name, d_product;
		size_t d_total_items;
		Item** d_list_of_items;

		// CLASS VARAIBLES.
		static size_t d_width_field;

		// METHODS.
		void m_set_empty();

	public:

		// METHODS.

		// CONSTRUCTORS AND DESTRUCTOR.
		CustomerOrder() { m_set_empty(); }
		CustomerOrder(const std::string& data);
		CustomerOrder(const CustomerOrder& source) { throw std::string("Invalid Argument"); }
		CustomerOrder(CustomerOrder&& source) noexcept;

		~CustomerOrder();

		// OPERATORS.
		CustomerOrder& operator=(const CustomerOrder& source) = delete;
		CustomerOrder& operator=(CustomerOrder&& source) noexcept;

		// QUERIES.
		bool isOrderFilled() const;
		bool isItemFilled(const std::string& itemName) const;

		// METHODS.
		void fillItem(Station& station, std::ostream& os);
		void display(std::ostream& os) const;

		// HELPER FUNCTIONS.

	};

}

#endif // !SDDS_CUSTOMERORDER_H
