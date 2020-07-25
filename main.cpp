#include <iostream>
#include <iomanip>
#include <string>
#include <random>

using namespace std;

int main()
{
	srand(time(0));
	string lotteryGame(int);

	void megaBall();
	void lotto();
	void megaMillions();
	void luckyMoney();
	void fantasyFive();
	void pickFour();
	void pickThree();

	//Display name
	string intro = "Parker Redford's Lottery Games!!!\n";
	cout << intro
		<< setfill('*') << setw((int)intro.length() + 1) << "\n\n" << setfill(' ');

	do
	{
		int selection;
		cout << "\nPlease select a lottery game to continue:\n" <<
			"1) Powerball\n" <<
			"2) Lotto\n" <<
			"3) Mega Millions\n" <<
			"4) Lucky M$ney\n" <<
			"5) Fantasy 5\n" <<
			"6) Pick 4\n" <<
			"7) Pick 3\n" <<
			"0) Exit\n";

		cin >> selection;

		cout << "\nYou entered " << selection << ": " << lotteryGame(selection) << "\n";

		switch (selection)
		{
		case 0:
			//Exit
			return false;
		case 1:
			megaBall();
			break;
		case 2:
			lotto();
			break;
		case 3:
			megaMillions();
			break;
		case 4:
			luckyMoney();
			break;
		case 5:
			fantasyFive();
			break;
		case 6:
			pickFour();
			break;
		case 7:
			pickThree();
			break;
		default:
			continue;
		}
	} while (true);
}
void megaBall()
{
	void playLottery(int const, int const, int const, int*);

	const int LENGTH = 5, MAX = 69, POWER = 26;
	int* numbers = new int[LENGTH];

	playLottery(LENGTH, MAX, POWER, numbers);
}
void lotto()
{
	void playLottery(int const, int const, int const, int*);

	const int LENGTH = 5, MAX = 53, MEGA = 0;
	int* numbers = new int[LENGTH];

	playLottery(LENGTH, MAX, MEGA, numbers);

}
void megaMillions()
{
	void playLottery(int const, int const, int const, int*);

	const int LENGTH = 5, MAX = 70, MEGA = 25;
	int* numbers = new int[LENGTH];

	playLottery(LENGTH, MAX, MEGA, numbers);

}
void luckyMoney()
{
	void playLottery(int const, int const, int const, int*);
	
	const int LENGTH = 4, MAX = 47, LUCKY = 17;
	int* numbers = new int[LENGTH];

	playLottery(LENGTH, MAX, LUCKY, numbers);

}
void fantasyFive()
{
	void playLottery(int const, int const, int const, int*);

	const int LENGTH = 4, MAX = 36, FANTASY = 0;
	int* numbers = new int[LENGTH];

	playLottery(LENGTH, MAX, FANTASY, numbers);
}
void pickFour()
{
	void playLottery(int const, int const, int const, int*);

	const int LENGTH = 3, MAX = 9, PICK = 0;
	int* numbers = new int[LENGTH];

	playLottery(LENGTH, MAX, PICK, numbers);

}
void pickThree()
{
	void playLottery(int const, int const, int const, int*);

	const int LENGTH = 2, MAX = 9, PICK = 0;
	int* numbers = new int[LENGTH];

	playLottery(LENGTH, MAX, PICK, numbers);
}
void playLottery(int const LENGTH, int const MAX, int const MAGICNUMBER, int* numbers)
{
	int* generateNumbers(int, int, int);
	void displayNumbers(int*, const int);

	//Randomly generated
	numbers = generateNumbers(LENGTH, MAX, MAGICNUMBER);

	//Show results
	displayNumbers(numbers, LENGTH);
}

//Game name associated with their int value
string lotteryGame(int game)
{
	switch (game)
	{
	case 0:
		return "to exit the lottery games";
	case 1:
		return "Powerball";
		break;
	case 2:
		return "Lotto";
		break;
	case 3:
		return "Mega Millions";
		break;
	case 4:
		return "Lucky M$ney";
		break;
	case 5:
		return "Fantasy 5";
		break;
	case 6:
		return "Pick 4";
		break;
	case 7:
		return "Pick 3";
		break;
	default:
		return "an invalid input";
	}
}

//Return the generated numbers
int* generateNumbers(int LENGTH, int MAX, int MAGICNUMBER)
{
	int* arr = new int[LENGTH]; //Initialize local array for return
	int max = MAX;

	bool hasDuplicate(int*, int);

	//Generate numbers
	for (int i = 0; i <= LENGTH; i++)
	{
		if (i == LENGTH && MAGICNUMBER != 0)
			max = MAGICNUMBER;

		do
		{
			arr[i] = 1 + rand() % max;
		} while (hasDuplicate(arr, i)); //Check for distinctive, if not, reassign number to a new random number
	}

	return arr;
}

//Return true if array has duplicates
bool hasDuplicate(int* array, int LENGTH)
{
	bool b = false;
	for (int i = 0; i <= LENGTH; i++)
	{
		for (int j = i + 1; j <= LENGTH; j++)
		{
			if (array[i] == array[j])
				b = true;
		}
	}
	return b;
}

void displayNumbers(int* array, const int LENGTH)
{
	cout << "Your lottery numbers are: ";
	for(int i = 0; i <= LENGTH; i++)
		if (i != LENGTH)
			cout << array[i] << ", ";
		else
			cout << array[i];

	cout << "\n";
}