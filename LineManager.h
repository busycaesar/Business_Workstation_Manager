// Name: DEV JIGISHKUMAR SHAH
// Seneca Student ID: 131623217
// Seneca email: djshah11@myseneca.ca
// Date of completion: 03/12/2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_LINEMANAGER_H
#define SDDS_LINEMANAGER_H

#include<vector>
#include"Workstation.h"
#include <fstream>
#include<algorithm>

#define vector_of_workstation std::vector<Workstation*>

namespace sdds
{

	// CLASS.
	class LineManager
	{

		// ==DATA MEMBERS==

		// INSTANCE VARIABLES.
		vector_of_workstation d_active_line;
		size_t d_total_customer_orders;
		Workstation* d_first_station;

		// CLASS VARAIBLES.

		// ==METHODS==
		void m_set_empty();

	public:

		// ==METHODS==

		// CONSTRUCTORS AND DESTRUCTOR.
		LineManager(const std::string& file_name, const vector_of_workstation& stations);

		// OPERATORS.

		// QUERIES.

		// METHODS.
		void reorderStations();
		bool run(std::ostream& os);
		void display(std::ostream& os) const{ for (size_t i = 0; i < d_active_line.size(); i++) d_active_line[i]->m_display(os); }

		// HELPER FUNCTIONS.

	};

}

#endif // !SDDS_LINEMANAGER_H