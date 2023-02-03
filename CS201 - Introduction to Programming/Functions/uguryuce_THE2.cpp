#include <iostream>
using namespace std;

// function1
 bool totalBudget(int firstBudget)
{	
	if (firstBudget < 0)
	{
		cout << "Budget cannot be negative." << endl;
		return false;
	}
	else 
	{
		return true;
	}
}
// function2
bool quantities(int quantity1, int quantity2, int quantity3)
{
	if (quantity1 > 0 && quantity2 > 0 && quantity3 > 0)
	{
		return true;
	}
	else
	{
		cout << "All quantities must be positive." << endl;
		return false;
	}
}
//function3
int totalPrice(int quan1, int quan2, int quan3)
{
	int cur_price, price1, price2, price3;
	price1 = 5;
	price2 = 10;
	price3 = 15;

	cur_price = (quan1*price1) + (quan2*price2) + (quan3*price3); 
	return cur_price;
}
//function4
int condMaxOper(int previous_max_price, int current_price, int budget)
{
	if (previous_max_price > current_price || current_price > budget)
	{
		return previous_max_price;
	}
	else
	{		return current_price;	}
}
//function5
void mixof3and4(int q1, int q2, int q3, int budget, int &max_price)
{
	int curr_price;
	curr_price = totalPrice(q1,q2,q3);
	max_price = condMaxOper(max_price, curr_price, budget);
}
//function6
int permutation(int q1, int q2, int q3, int budget)
{	
	int max_price = 0;
	mixof3and4(q1,q2,q3, budget, max_price); //1
	mixof3and4(q1,q3,q2, budget, max_price); //2
	mixof3and4(q2,q1,q3, budget, max_price); //3
	mixof3and4(q2,q3,q1, budget, max_price); //4
	mixof3and4(q3,q2,q1, budget, max_price); //5
	mixof3and4(q3,q1,q2, budget, max_price); //6
	return max_price;
}
//function7
void runner()
{
	int budget, previous_max_price, price, max_price, q1, q2, q3;
	cout << "Please enter your budget: ";
	cin >> budget;
	if (totalBudget(budget)) //func1
	{
		cout << "Please enter three quantities: ";
		cin >> q1 >> q2 >> q3;
		if (quantities(q1,q2,q3)) //func2
		{
			// totalPrice(q1, q2, q3); //func3
			// condMaxOper(previous_max_price, price, budget); //func4
			mixof3and4(q1, q2, q3, budget, max_price); //func5
			// permutation(q1, q2, q3, budget); //func6
			// cout << budget - permutation(q1, q2, q3, budget);
			if ((permutation(q1, q2, q3, budget)) == 0)
			{
				cout << "You cannot afford any of the permutations with these quantities and budget." << endl;
			}
			else
			{
				cout << "You have " << (budget - permutation(q1, q2, q3, budget)) << " liras left." << endl;
			}
		}
	}
}

int main()
{
	runner();
	cout << endl;
	runner();
	cout << endl;
	cout << "Goodbye!" << endl;
	return 0;
}