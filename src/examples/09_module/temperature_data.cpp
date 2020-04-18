//temperature_data.cpp
#include "temperature_data.h"


void TemperatureData::save_temps(vector<Temperature>& ts)
{
	std::ofstream file_out(file_name, std::ios_base::trunc);

	for (auto temp : ts)
	{
	file_out << temp.get_hour();
	file_out << " ";
	file_out << temp.get_reading();
	file_out << "\n";
	}

	file_out.close();
}

vector<Temperature> TemperatureData::get_temps()const
{
	vector<Temperature> temps;
	std::ifstream read_file(file_name);

	int hour;
	double reading;

	if (read_file.is_open())
	{
		while (read_file >> hour >> reading)
		{
			Temperature temp(hour, reading);
			temps.push_back(temp);
		}
	}
	read_file.close();

	return temps;
}
