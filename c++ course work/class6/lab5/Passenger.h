#include<string>

using namespace std;

class Passenger{
	string pName;
	int age;
	char gender;
	int seatnum;
	string coach;
public:
	Passenger(string name, int p_age, char p_gender, string p_coach, int p_seat);
	string showPassenger();
};
