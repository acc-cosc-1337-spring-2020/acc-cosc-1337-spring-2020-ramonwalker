//temperature_data.h
#include<fstream>
#include<string>
#include<vector>
#include"temperature.h"

#ifndef TEMPERATURE_DATA_H
#define TEPERATURE_DATA_H

using std::vector;
using std::string;

class TemperatureData
{
public:
	void save_temps(vector<Temperature>& ts);
	vector<Temperature>get_temps()const;

private:
	const std::string file_name{ "temperature.dat" };
};

#endif; // ! TEMPERATURE_DATA_H