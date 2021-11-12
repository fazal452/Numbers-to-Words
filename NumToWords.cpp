#include <iostream>;
#include <string>
using namespace std;

//converts 1 digit number to string
string prefix(int number);

//converts 3 digit numbers to string
string numToEnglish(int number);

//converts 2 x (3 digits numbers) to form 5 digit number
string intToString(int number);

//Prints out intervals of strings
void printIntStrings(int start, int end, int interval);


/*
int main() {

	printIntStrings(-32, 99999, 9927);

	return(0);
}
*/

// RETURN ENGLISH REPRESENTATION OF NUMBER FROM 0 - 10
string prefix(int number) {

	if (number == 0) {
		return("zero");
	}
	if (number == 1) {
		return("one");
	}
	if (number == 2) {
		return("two");
	}
	if (number == 3) {
		return("three");
	}
	if (number == 4) {
		return("four");
	}
	if (number == 5) {
		return("five");
	}
	if (number == 6) {
		return("six");
	}
	if (number == 7) {
		return("seven");
	}
	if (number == 8) {
		return("eight");
	}
	if (number == 9) {
		return("nine");
	}

	//If prefix is not in range (Shouldnt happen!)
	else {
		return("error");
	}
}


// Turn 3 digit number into a word
string numToEnglish(int number) {

	// String that gets updated as you go
	string out_string = "";

	// Digits of each number
	int ones = 0;
	int tens = 0;
	int hundreds = 0;
	ones = number % 10;
	tens = (number / 10) % 10;
	hundreds = (number / 100) % 10;

	//First check Hundreds digit
	if (hundreds != 0) {

		out_string.append(prefix(hundreds) + " hundred ");

		//add and if tens or ones is present
		if (tens != 0 || ones != 0) {
			out_string.append("and ");
		}
	}
	//Next check tens place
	if (tens != 0) {

		//if tens is 6,7 or 9, simply add "ty"
		//else you have to adjust and add new string
		if (tens == 6 || tens == 7 || tens == 9) {
			out_string.append(prefix(tens) + "ty");
		}
		if (tens == 8) {
			out_string.append("eighty");
		}
		if (tens == 5) {
			out_string.append("fifty");
		}
		if (tens == 4) {
			out_string.append("forty");
		}
		if (tens == 3) {
			out_string.append("thirty");
		}
		if (tens == 2) {
			out_string.append("twenty");
		}

		//Adding a dash between numbers if needed
		if (ones != 0 && tens != 1) {
			out_string.append("-");
		}

		//Check logic for "teens"
		if (tens == 1) {

			if (ones == 0) {
				out_string.append("ten");
			}
			if (ones == 1) {
				out_string.append("eleven");
			}
			if (ones == 2) {
				out_string.append("twelve");
			}
			if (ones == 3) {
				out_string.append("thirteen");
			}
			if (ones == 4) {
				out_string.append("fourteen");
			}
			if (ones == 5) {
				out_string.append("fifteen");
			}
			if (ones == 6) {
				out_string.append("sixteen");
			}
			if (ones == 7) {
				out_string.append("seventeen");
			}
			if (ones == 8) {
				out_string.append("eighteen");
			}
			if (ones == 9) {
				out_string.append("nineteen");
			}

			//Return The string prematurely if the tens place starts with a 1
			return(out_string);

		}
	}

	//Simply add prefix of ones
	if (ones != 0) {
		out_string.append(prefix(ones));
	}

	//Return string of three digit number
	return(out_string);
}


//converts 2 x (3 digits numbers) to form 5 digit number
string intToString(int number) {

	//Error Checking
	if (number < 0 || number > 99999) {
		return("error");
	}

	//Getting the digit places of the number
	int ones = 0;
	int tens = 0;
	int hundreds = 0;
	int thousands = 0;
	int ten_thousands = 0;
	ones = number % 10;
	tens = (number / 10) % 10;
	hundreds = (number / 100) % 10;
	thousands = (number / 1000) % 10;
	ten_thousands = (number / 10000) % 10;

	//Create variable for string to be updated as you go
	string out_string = "";

	//Any number under 999,999 can be split into two parts
	//There is the First half followed by thousands
	//And the second half by itself

	//halving the number
	int first_half = 0;
	int second_half = 0;
	first_half = number / 1000;
	second_half = number % 1000;

	//Deal with first half(ten thou and thou)
	if (first_half != 0) {

		out_string.append(numToEnglish(first_half) + " thousand");

		//Add , or space if second half is present or empty
		if (second_half != 0 && hundreds != 0) {
			out_string.append(", ");
		}
		else {
			out_string.append(" ");
		}

	}

	// Rule 4: "and" between thousands and tens/ones if no hundred
	// If the thousands number exists
	if (thousands != 0 || ten_thousands != 0) {
		//Check for absence in hundreds and presence in tens or ones
		if ((hundreds == 0) && ((tens != 0) || (ones != 0))) {
			out_string.append("and ");
		}
	}
	// Add the second half of number
	if (second_half != 0) {

		out_string.append(numToEnglish(second_half));
	}

	//Check for if whole number is 0
	if (first_half == 0 && second_half == 0) {
		return("zero");
	}

	//return final updated string
	return(out_string);
}

//Prints out intervals of strings
void printIntStrings(int start, int end, int interval) {

	//Check for Wrong Order
	if (end < start) {
		int temp = 0;
		temp = start;
		start = end;
		end = temp;
	}

	//Go through range with given interval
	for (int i = start; i <= end; i += interval) {
		cout << intToString(i) << endl;
	}

}

