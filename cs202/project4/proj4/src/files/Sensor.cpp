//Nicholas Ang
//Project 4
//Sensor Class Source File

//Libraries and Header Files
#include <files/Sensor.h>
#include <files/my_string.h>

//Global Price Constants
#define gpsprice 5.0
#define radarprice 20.0
#define lidarprice 15.0
#define cameraprice 10.0
#define noneprice 0.0

//Initial Counts of sensors
int Sensor::gps_cnt = 0;
int Sensor::lidar_cnt = 0;
int Sensor::radar_cnt = 0;
int Sensor::camera_cnt = 0;

//Checks if sensors are the same with each other
bool operator==(const Sensor &sensor1,const Sensor &sensor2)
{
	int same;
	same = myStringCompare(sensor1.m_type,sensor2.m_type);
	if (same == 0)
	{
	return false;
	}
	return true;
}

//Sensor Default Constructor
Sensor::Sensor()
{
	myStringCopy(m_type, "none");
	m_extracost = noneprice;
}

//Sensor Parameterized Constructor
Sensor::Sensor(char *Sensortype)
{
	myStringCopy(m_type,Sensortype);
	if(myStringCompare(m_type, "gps") == 0)
	{
		m_extracost = gpsprice;
		Sensor::gps_cnt++;
	}
	else if(myStringCompare(m_type, "lidar") == 0)
	{
		m_extracost = lidarprice;
		Sensor::lidar_cnt++;
	}
	else if(myStringCompare(m_type, "radar") == 0)
	{
		m_extracost = radarprice;
		Sensor::radar_cnt++;
	}
	else if(myStringCompare(m_type, "camera") == 0)
	{
		m_extracost = cameraprice;
		Sensor::camera_cnt++;
	}
	else if(myStringCompare(m_type, "{gps") == 0)
	{
		m_extracost = gpsprice;
		Sensor::gps_cnt++;
	}
	else if(myStringCompare(m_type, "{lidar") == 0)
	{
		m_extracost = lidarprice;
		Sensor::lidar_cnt++;
	}
	else if(myStringCompare(m_type, "{radar") == 0)
	{
		m_extracost = radarprice;
		Sensor::radar_cnt++;
	}
	else if(myStringCompare(m_type, "{camera") == 0)
	{
		m_extracost = cameraprice;
		Sensor::camera_cnt++;
	}
	else if(myStringCompare(m_type, "none") == 0)
	{
		m_extracost = noneprice;
	}
	else
	{
		myStringCopy(m_type, "none");
		m_extracost = noneprice;
	}
}

//Sensor Copy Constructor
Sensor::Sensor(const Sensor &sensor)
{
	myStringCopy(m_type,sensor.m_type);
	if(myStringCompare(m_type, "gps") == 0)
	{
		m_extracost = gpsprice;
		Sensor::gps_cnt++;
	}
	else if(myStringCompare(m_type, "lidar") == 0)
	{
		m_extracost = lidarprice;
		Sensor::lidar_cnt++;
	}
	else if(myStringCompare(m_type, "radar") == 0)
	{
		m_extracost = radarprice;
		Sensor::radar_cnt++;
	}
	else if(myStringCompare(m_type, "camera") == 0)
	{
		m_extracost = cameraprice;
		Sensor::camera_cnt++;
	}
	else if(myStringCompare(m_type, "{gps") == 0)
	{
		m_extracost = gpsprice;
		Sensor::gps_cnt++;
	}
	else if(myStringCompare(m_type, "{lidar") == 0)
	{
		m_extracost = lidarprice;
		Sensor::lidar_cnt++;
	}
	else if(myStringCompare(m_type, "{radar") == 0)
	{
		m_extracost = radarprice;
		Sensor::radar_cnt++;
	}
	else if(myStringCompare(m_type, "{camera") == 0)
	{
		m_extracost = cameraprice;
		Sensor::camera_cnt++;
	}
	else if(myStringCompare(m_type, "none") == 0)
	{
		m_extracost = noneprice;
	}
	else
	{
		myStringCopy(m_type, "none");
		m_extracost = noneprice;
	}
}


//Getters and Resetters of Sensors
int Sensor::getGps()
{
	return gps_cnt;
}
int Sensor::getLidar()
{
	return lidar_cnt;
}
int Sensor::getRadar()
{
	return radar_cnt;
}
int Sensor::getCamera()
{
	return camera_cnt;
}

void Sensor::resetGps()
{
	gps_cnt = 0;
}
void Sensor::resetLidar()
{
	lidar_cnt = 0;
}
void Sensor::resetCamera()
{
	camera_cnt = 0;
}
void Sensor::resetRadar()
{
	radar_cnt = 0;
}


//Get type and Set Type of sensor
char *Sensor::getType()
{
	return m_type;
}
void Sensor::setType(char *type)
{
	myStringCopy(m_type,type);
}

//Get and Set Extra Cost of Sensor
void Sensor::setExtraCost(double cost)
{
	m_extracost = cost;
}
double Sensor::getExtraCost() const
{
	return m_extracost;
}
