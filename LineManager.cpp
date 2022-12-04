// Name: DEV JIGISHKUMAR SHAH
// Seneca Student ID: 131623217
// Seneca email: djshah11@myseneca.ca
// Date of completion: 03/12/2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include"LineManager.h"

namespace sdds
{

	void LineManager::m_set_empty()
	{

		d_total_customer_orders = 0;
		d_first_station = nullptr;

	}

	LineManager::LineManager(const std::string& file_name, const vector_of_workstation& stations)
	{

		// VARIABLE DECLARATION.
		Utilities for_extraction;
		std::ifstream data_file(file_name);

		m_set_empty();

		if (data_file)
		{

			while (!data_file.eof())
			{

				// VARIABLE DECLARATION.
				std::string data = "", workstation_item = "", next_workstation_item = "";
				size_t next_position = 0;
				bool more_data = false;
				Workstation* workstation = nullptr;
				Workstation* next_workstation = nullptr;

				std::getline(data_file, data);

				workstation_item = for_extraction.extractToken(data, next_position, more_data);
				if (more_data)
				{
					next_workstation_item = for_extraction.extractToken(data, next_position, more_data);
				}

				for_each(stations.begin(), stations.end(), [&workstation, &next_workstation, workstation_item, next_workstation_item](Workstation* temp)
					{

						if (temp->getItemName() == workstation_item)workstation = temp;
						else if (temp->getItemName() == next_workstation_item) next_workstation = temp;

					});

				if (!d_active_line.size()) d_first_station = workstation;

				workstation->m_set_next_station(next_workstation);
				d_active_line.push_back(workstation);
				d_total_customer_orders = g_pending.size();

			}
			data_file.close();

		}
		else throw std::string("Unable to open file.");

	}

	void LineManager::reorderStations()
	{

		// VARIABLE DECLARATION.
		vector_of_workstation reordered_list;
		Workstation* previous_workstation = nullptr;

		for (size_t j = 0; j < d_active_line.size(); j++)
		{

			for (size_t i = 0; i < d_active_line.size(); i++)
			{

				if (d_active_line[i]->m_get_next_station() == previous_workstation)
				{

					reordered_list.push_back(d_active_line[i]);
					previous_workstation = d_active_line[i];
					break;

				}

			}

		}

		std::reverse(reordered_list.begin(), reordered_list.end());
		d_first_station = reordered_list[0];
		d_active_line = reordered_list;

	}

	bool LineManager::run(std::ostream& os)
	{

		// VARIABLE DECLARATION.
		static size_t current_iteration_number = 0;
		current_iteration_number++;

		os << "Line Manager Iteration: " << current_iteration_number << std::endl;

		if (!g_pending.empty())
		{

			*d_first_station += std::move(g_pending.front());
			g_pending.pop_front();

		}

		for (size_t i = 0; i < d_active_line.size(); i++) d_active_line[i]->m_fill(os);

		for (size_t i = 0; i < d_active_line.size(); i++) d_active_line[i]->m_attempt_to_move_order();

		for (size_t i = 0; i < d_active_line.size(); i++){ if (!d_active_line[i]->empty())return false; }

		return true;

	}

}