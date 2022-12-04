// Name: DEV JIGISHKUMAR SHAH
// Seneca Student ID: 131623217
// Seneca email: djshah11@myseneca.ca
// Date of completion: 25/11/2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include"CustomerOrder.h"

namespace sdds
{

	size_t CustomerOrder::d_width_field = 0;

	void CustomerOrder::m_set_empty()
	{

		d_customer_name = "";
		d_product = "";
		d_total_items = 0;
		d_list_of_items = nullptr;

	}

	CustomerOrder::CustomerOrder(const std::string& data)
	{

		// VARIABLE DECLARATION.
		Utilities for_extraction;
		size_t next_data = 0;
		bool extracted = false;
		std::vector<Item*> array_of_items;
		Item* new_item = nullptr;

		m_set_empty();

		d_customer_name = for_extraction.extractToken(data, next_data, extracted);
		d_product = for_extraction.extractToken(data, next_data, extracted);

		while (extracted)
		{

			new_item = new Item(for_extraction.extractToken(data, next_data, extracted));
			array_of_items.push_back(new_item);

		}

		d_total_items = array_of_items.size();
		d_list_of_items = new Item * [d_total_items];

		for (size_t i = 0; i < d_total_items; i++) d_list_of_items[i] = array_of_items[i];

		if (d_width_field < for_extraction.getFieldWidth())d_width_field = for_extraction.getFieldWidth();

	}

	CustomerOrder::CustomerOrder(CustomerOrder&& source) noexcept
	{

		m_set_empty();

		*this = std::move(source);

	}

	CustomerOrder::~CustomerOrder()
	{

		for (size_t i = 0; i < d_total_items; i++) delete d_list_of_items[i];

		delete[] d_list_of_items;

	}

	CustomerOrder& CustomerOrder::operator=(CustomerOrder&& source) noexcept
	{

		if (this != &source)
		{

			if (d_list_of_items != nullptr)
			{

				for (size_t i = 0; i < d_total_items; i++) delete d_list_of_items[i];

				delete[] d_list_of_items;

			}

			d_customer_name = source.d_customer_name;
			d_product = source.d_product;
			d_total_items = source.d_total_items;
			d_list_of_items = source.d_list_of_items;
			source.d_list_of_items = nullptr;

			source.m_set_empty();

		}

		return *this;

	}

	bool CustomerOrder::isOrderFilled() const
	{

		for (size_t i = 0; i < d_total_items; i++) { if (!d_list_of_items[i]->d_is_filled)return false; }

		return true;

	}

	bool CustomerOrder::isItemFilled(const std::string& itemName) const
	{

		for (size_t i = 0; i < d_total_items; i++) { if (d_list_of_items[i]->d_item_name == itemName && !d_list_of_items[i]->d_is_filled) return false; }

		return true;

	}

	void CustomerOrder::fillItem(Station& station, std::ostream& os)
	{

		//VARIABLE DECLARATION.
		bool filled = false;

		for (size_t i = 0; i < d_total_items; i++)
		{

			if (d_list_of_items[i]->d_item_name == station.getItemName() && !d_list_of_items[i]->d_is_filled && !filled)
			{

				if (station.getQuantity() >= 1)
				{

					station.updateQuantity();
					d_list_of_items[i]->d_serial_number = station.getNextSerialNumber();
					d_list_of_items[i]->d_is_filled = true;
					os << "    Filled " << d_customer_name << ", "
						<< d_product << " [" << d_list_of_items[i]->d_item_name << "]" << std::endl;
					filled = true;
				}
				else
				{

					os << "    Unable to fill " << d_customer_name << ", " << d_product
						<< " [" << d_list_of_items[i]->d_item_name << "]" << std::endl;

				}

			}

		}

	}

	void CustomerOrder::display(std::ostream& os) const
	{

		os << d_customer_name << " - " << d_product << std::endl;

		for (size_t i = 0; i < d_total_items; i++)
		{

			os << "[" << std::setw(6) << std::right << std::setfill('0') << d_list_of_items[i]->d_serial_number << "] "
				<< std::setw(d_width_field) << std::left << std::setfill(' ') << d_list_of_items[i]->d_item_name
				<< "   - " << (d_list_of_items[i]->d_is_filled ? "FILLED" : "TO BE FILLED") << std::endl;
		
		}

	}

}