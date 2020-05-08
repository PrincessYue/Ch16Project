

#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
using namespace std;

class Employee
{
private:
	string name;
	int number;
	string hireDate;
public:
	class InvalidEmployeeNumber
	{};
	Employee()
	{
		name = "";
		number = 0;
		hireDate = "";
	}


	string getName() const
	{
		return name;
	}

	int getNumber() const
	{

		return number;
	}

	string getHireDate() const
	{
		return hireDate;
	}
	void setName(string name1)
	{
		name = name1;
	}

	void setNumber(int number1)
	{
		if (number1 >= 0 && number1 <= 9999)
		{
			number = number1;
		}
		else
		{
			throw InvalidEmployeeNumber();
		}
	}
	void setHireDate(string hireDate1)
	{
		hireDate = hireDate1;
	}
};


class ProductionWorker : public Employee
{
protected:
	int shift;
	double hourlyPayRate;
public:
	class InvalidShift
	{};

	class InvalidPayRate
	{};

	ProductionWorker()
	{
		shift = 0;
		hourlyPayRate = 0.0;
	}

	ProductionWorker(int shift1)
	{
		if (shift1 == 1)
		{
			cout << "Production worker's shift: day" << endl;

		}
		if (shift1 == 2)
		{
			cout << "Production worker's shift: night" << endl;
		}
	}
	int getShift() const
	{
		return shift;
	}
	double getHourlyPayRate() const
	{
		return hourlyPayRate;
	}
	void setShift(int shift1)
	{
		if (shift1 != 1 && shift1 != 2)
		{
			throw InvalidShift();
		}
		else
		{

			shift = shift1;
		}
	}

	void setHourlyPayRate(double hourlyPayRate1)
	{
		if (hourlyPayRate1 < 0.0)
		{
			throw InvalidPayRate();
		}
		else
		{

			hourlyPayRate = hourlyPayRate1;
		}
	}

};
class ShiftSupervisor : public Employee
{
protected:
	double salary;
	double productionBonus;
public:
	ShiftSupervisor() {
		salary = 0;
		productionBonus = 0;
	}


	double getSalary() const
	{
		return salary;
	}
	double getProductionBonus() const
	{
		return productionBonus;
	}
	void setSalary(double salary1)
	{
		salary = salary1;
	}
	void setProductionBonus(double productionBonus1)
	{
		productionBonus = productionBonus1;
	}
};

class TeamLeader : public ProductionWorker
{
protected:
	double hourlyPay;
	double fixedMonthlyBonus;
	int trainingHoursRequired;
	int trainingHoursAccrued;

public:
	TeamLeader() {
		hourlyPay = 0.0;
		fixedMonthlyBonus = 0.0;
		trainingHoursRequired = 0;
		trainingHoursAccrued = 0;
	}
	TeamLeader(int trainingHoursAccrued1, int trainingHoursRequired1)
	{
		if (trainingHoursAccrued1 >= trainingHoursRequired1)
		{
			cout << "The team leader has accrued enough training hours. ";
		}
		else if (trainingHoursAccrued1 < trainingHoursRequired1)
		{
			cout << "The team leader has not yet accrued the required amount of training hours.";
		}
	}
	double getHourlyPay() const
	{
		return hourlyPay;
	}
	double getFixedMonthlyBonus() const
	{
		return fixedMonthlyBonus;
	}
	int getTrainingHoursRequired() const
	{
		return trainingHoursRequired;
	}
	int getTrainingHoursAccrued() const
	{
		return trainingHoursAccrued;
	}
	void setHourlyPay(double hourlyPay1)
	{
		hourlyPay = hourlyPay1;
	}
	void setFixedMonthlyBonus(double fixedMonthlyBonus1)
	{
		fixedMonthlyBonus = fixedMonthlyBonus1;
	}
	void setTrainingHoursRequired(double trainingHoursRequired1)
	{
		trainingHoursRequired = trainingHoursRequired1;
	}
	void setTrainingHoursAccrued(double trainingHoursAccrued1)
	{
		trainingHoursAccrued = trainingHoursAccrued1;
	}

};

int main()
{
	string name;
	int number;
	string hireDate;
	int shift;
	double hourlyPayRate;
	string shiftName;

	ProductionWorker person;
	cout << "Please enter the employee's name. " << endl;
	getline(cin, name);
	cout << endl;
	cout << "Please enter " << name << "'s employee ID number." << endl;
	cin >> number;
	cin.ignore();

	cout << endl;

	try
	{
		person.setNumber(number);
	}
	catch (Employee::InvalidEmployeeNumber)
	{
		cout << "Error: Employee number must be greater than 0 or and less than 9999\n";
		return 0;
	}

	cout << endl;

	cout << "Please enter " << name << "'s hire date." << endl;
	getline(cin, hireDate);
	cout << endl;
	cout << "Please enter " << name << "'s shift (1 for night or 2 for day)." << endl;
	cin >> shift;
	cout << endl;
	try
	{
		person.setShift(shift);
	}
	catch (ProductionWorker::InvalidShift)
	{
		cout << "Error: Shift must be 1 (day) or 2(night)\n";
		return 0;
	}
    
	cout << endl;

	cout << "Please enter " << name << "'s hourly pay rate." << endl;
	cout << "$";
	cin >> hourlyPayRate;
	cout << endl;

	person.setName(name);

	person.setHireDate(hireDate);
	person.setShift(shift);

	try
	{
		person.setHourlyPayRate(hourlyPayRate);
	}
	catch (ProductionWorker::InvalidPayRate)
	{
		cout << "Error: Pay rate must not be a negative number\n";
		return 0;
	}
	



	cout << "Production worker's name: " << person.getName() << endl;
	cout << "Production worker's number: " << person.getNumber() << endl;
	cout << "Production worker's hire date: " << person.getHireDate() << endl;
	cout << "Production worker's hourly pay rate: $" << setprecision(2) << fixed << person.getHourlyPayRate() << endl;
	person = ProductionWorker(shift);

	system("pause");

	ShiftSupervisor shiftSupervisorEmployee;
	double salary1;
	char productionGoals;
	double productionBonus = 0.0;


	cout << "Please enter the shift supervisor's salary. " << endl;
	cout << "$";
	cin >> salary1;
	cout << "Were production goals met? Please enter Y for yes or N for no. " << endl;
	cin >> productionGoals;
	toupper(productionGoals);

	if (productionGoals == 'Y')
	{
		productionBonus = salary1 * .05;
	}

	shiftSupervisorEmployee.setSalary(salary1);
	shiftSupervisorEmployee.setProductionBonus(productionBonus);

	cout << "The shift supervisor's salary is $" << setprecision(2) << fixed << shiftSupervisorEmployee.getSalary() << endl;
	if (productionBonus == 0.0)
	{
		cout << "The shift supervisor has no bonus this year. " << endl;
	}
	if (productionBonus != 0.0)
	{
		cout << "The shift supervisor has a bonus of $" << setprecision(2) << fixed << shiftSupervisorEmployee.getProductionBonus() << " this year." << endl;
	}

	system("pause");

	TeamLeader teamLeader;
	double fixedMonthlyBonus1;
	int trainingHoursAccrued1;
	double hourlyPay1;
	int trainingHoursRequired1;
	double overallPay;

	cout << "What is the team leader's hourly pay?" << endl;
	cout << "$";
	cin >> hourlyPay1;
	teamLeader.setHourlyPay(hourlyPay1);
	cout << "What is the team leader's fixed monthly bonus?" << endl;
	cout << "$";
	cin >> fixedMonthlyBonus1;
	teamLeader.setFixedMonthlyBonus(fixedMonthlyBonus1);
	cout << endl;
	cout << "How many training hours is the team leader required to attend yearly?";
	cout << endl;
	cin >> trainingHoursRequired1;
	teamLeader.setTrainingHoursRequired(trainingHoursRequired1);
	cout << "How many training hours has the team leader accrued this year?" << endl;
	cin >> trainingHoursAccrued1;
	teamLeader.setTrainingHoursAccrued(trainingHoursAccrued1);
	cout << endl;

	teamLeader = TeamLeader(trainingHoursAccrued1, trainingHoursRequired1);

	overallPay = (hourlyPay1 * 2080) + (12 * fixedMonthlyBonus1);
	cout << endl;
	cout << "The team leader should earn $" << setprecision(2) << fixed << overallPay << " per year.";



}

