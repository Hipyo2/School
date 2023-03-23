//Nicholas Ang
//Project 4
//Sensor Class Header File

#ifndef SENSOR_H
#define SENSOR_H

//Global Constants
#define maxName 256

//Class Sensor Declaration
class Sensor
{
//Private Methods
private:
//Data Values
char m_type[maxName+1];
double m_extracost;
static int gps_cnt;
static int lidar_cnt;
static int radar_cnt;
static int camera_cnt;

//Public Methods
public:
//Constructors
Sensor();
Sensor(char *Sensortype);
Sensor(const Sensor &sensor);
//Getters and Setters for type
char *getType();
void setType(char *type);
//Getters and setters for extra cost of sensors
void setExtraCost(double cost);
double getExtraCost() const;

//Getters and Resetters of sensor counts
static int getGps();
static int getLidar();
static int getRadar();
static int getCamera();

static void resetGps();
static void resetLidar();
static void resetRadar();
static void resetCamera();


//Operator Overload to check if sensors are the same
friend bool operator==(const Sensor &sensor1,const Sensor &sensor2);
};

#endif /* SENSOR_H */
