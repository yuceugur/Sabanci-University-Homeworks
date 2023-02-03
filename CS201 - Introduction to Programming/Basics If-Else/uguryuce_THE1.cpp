#include <iostream>
#include <string>

using namespace std;

int main()
{	int roomCapacity, studentNumber, allowedCapacity, zoom_students;	double capacityCoefficient;	string className; 		cout << "Welcome to CS201 physical classroom capacity checker." << endl;		cout << "Please enter the room name: ";	cin >>  className;
	cout << "Please enter the room capacity: ";
	cin >> roomCapacity;

	if (roomCapacity >= 0)
	{
		cout << "Please enter the allowed capacity coefficient: ";
		cin >> capacityCoefficient;

		if (capacityCoefficient > 0 && capacityCoefficient <= 1)
		{
			allowedCapacity = roomCapacity * capacityCoefficient;
			
			cout << "Please enter how many students are registered to your course: ";
			cin >> studentNumber;

			if (studentNumber >= 0)
			{
				zoom_students = studentNumber - allowedCapacity;

				if (zoom_students <= 0)
				{
					cout << className << " can allow all students to attend physical lectures." << endl;
				}

				else
				{
					cout << className << " cannot allow all students to attend physical lectures." << endl;
					cout << "For each lecture " << zoom_students << " students must be selected to watch on Zoom." << endl;
				}
			}
			else 
			{
				cout << "You have entered an invalid value for registered students." << endl;
			}

		}

		else
		{
		cout << "You have entered an invalid value for capacity coefficient." << endl;
		}
	}
	else
	{
		cout << "You have entered an invalid value for room capacity." << endl;	
	}

return 0;
}
