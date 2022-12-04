// Name: DEV JIGISHKUMAR SHAH
// Seneca Student ID: 131623217
// Seneca email: djshah11@myseneca.ca
// Date of completion: 03/12/2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_WORKSTATION_H
#define SDDS_WORKSTATION_H

// REQUIRED HEADER FILES.
#include <deque>
#include"CustomerOrder.h"

#define bidirectional_customerorder_array std::deque<CustomerOrder>

namespace sdds
{

	// VARIABLE DECLARATION.
	extern bidirectional_customerorder_array g_pending;
	extern bidirectional_customerorder_array g_completed;
	extern bidirectional_customerorder_array g_incomplete;

	class Workstation : public Station
	{

		// ==DATA MEMBERS==

		// INSTANCE VARIABLES.
		bidirectional_customerorder_array d_orders;
		Workstation* d_next_workstation;

		// CLASS VARAIBLES.
		// VOID.

		// ==METHODS==

		void m_set_empty() { d_next_workstation = nullptr; }

	public:

		// ==METHODS==

		// CONSTRUCTORS AND DESTRUCTOR.
		Workstation(const Workstation& source) = delete;
		Workstation(Workstation&& source) = delete;
		Workstation(const std::string& station_data) :Station(station_data) { m_set_empty(); }

		// OPERATORS.
		Workstation& operator=(const Workstation& source) = delete;
		Workstation& operator=(Workstation& source) = delete;
		Workstation& operator+=(CustomerOrder&& new_order);

		// QUERIES.
		Workstation* m_get_next_station() const { return d_next_workstation; }
		bool empty()const { return d_orders.empty(); }

		// METHODS.
		void m_fill(std::ostream& out) { if (!d_orders.empty()) d_orders.front().fillItem(*this, out); }
		bool m_attempt_to_move_order();
		void m_set_next_station(Workstation* next_station) { d_next_workstation = next_station; }
		void m_display(std::ostream& out)const;

		// HELPER FUNCTIONS.

	};

}

#endif // !SDDS_WORKSTATION_H