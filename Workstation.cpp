// Name: DEV JIGISHKUMAR SHAH
// Seneca Student ID: 131623217
// Seneca email: djshah11@myseneca.ca
// Date of completion: 03/12/2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include"Workstation.h"

namespace sdds
{

	bidirectional_customerorder_array g_pending{};
	bidirectional_customerorder_array g_completed{};
	bidirectional_customerorder_array g_incomplete{};

	Workstation& Workstation::operator+=(CustomerOrder&& new_order)
	{

		d_orders.emplace_back(std::move(new_order));

		return *this;

	}

	bool Workstation::m_attempt_to_move_order()
	{

		// VARIABLE DECLARATION.
		bool moved = false;

		if (d_orders.front().isItemFilled(getItemName()) || !getQuantity())
		{


			//MOVE TO THE NEXT STATION.
			if (d_next_workstation == nullptr)
			{

				if (d_orders.front().isOrderFilled())g_completed.emplace_back(std::move(d_orders.front()));
				else g_incomplete.emplace_back(std::move(d_orders.front()));

			}
			else (*d_next_workstation) += std::move(d_orders.front());

			d_orders.pop_front();

			moved = true;

		}

		return moved;

	}

	void Workstation::m_display(std::ostream& out)const
	{

		out << Station::getItemName() << " --> ";

		if (d_next_workstation == nullptr) out << "End of Line";
		else out << d_next_workstation->getItemName();

		out << std::endl;

	}

}