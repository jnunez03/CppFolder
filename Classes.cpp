#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
using namespace std;

// Class Movie and all of its member functions...

class Movie {
public:
	string name,
		MPAArating;
double  rating_1,
		rating_2,
		rating_3,
		rating_4,
		rating_5;
	Movie() {}    // Default constructor
	Movie(string movie_name, string MPAA_rating) {  //constructor that allows access to member data
		name = movie_name;
		MPAArating = MPAA_rating;

		rating_1 = 0;
		rating_2 = 0;
		rating_3 = 0;
		rating_4 = 0;
		rating_5 = 0;
	}

	void setName(string movie) {       //Mutator function to set name of movie

		name = movie;
	}
	void setMPAARating(string rating) {   // Mutator Function to set rating of movie

		MPAArating = rating;
	}
	void addRating(int rate) {      //Mutator Function
		switch (rate)
		{
		case 1:
			++rating_1;
			break;
		case 2:
			++rating_2;
			break;
		case 3:
			++rating_3;
			break;
		case 4:
			++rating_4;
			break;
		case 5:
			++rating_5;
			break;
		default: cout << "Enter a non-fractional number between 1 & 5. " << endl;
		}


	}
	void printInfo() {             //Accessor Function
		cout << "Name of the movie: " << name << endl;
		cout << "MPAA Rating: " << "rated " << "\"" << MPAArating << "\"";
		cout << endl;
	}

	// Getting average of all ratings;
	double getAverage() {

		double total = (rating_1 + rating_2 + rating_3 + rating_4 + rating_5); //total

		double r1 = (rating_1 / total); //Percentages
		double r2 = (rating_2 / total);
		double r3 = (rating_3 / total);
		double r4 = (rating_4 / total);
		double r5 = (rating_5 / total);

		// weighing each percentage
		double one = r1 * (1);
		double two = r2 * (2);
		double three = r3 * (3);
		double four = r4 * (4);
		double five = r5 * (5);

		double x = (one + two + three + four + five);  //add them to get avg rating and return that value
		return x;
	}
};
// Main function for testing.
int main() {

	//Movie array of 3 objects of type Movie
	Movie Movies[3] = { { "Avengers", "PG-13" },
	{ "Snowden", "R" },
	{ "Last Call", "R" } };

	Movies[0].addRating(2);
	Movies[0].addRating(4);
	Movies[0].addRating(4);
	Movies[0].addRating(3);
	Movies[0].addRating(5);
	Movies[0].printInfo();
	double  x = Movies[0].getAverage();
	cout << fixed;
	cout << setprecision(2);
	cout << "Average Rating for Avengers is " << x << endl;
	cout << endl;


	Movies[1].addRating(5);
	Movies[1].addRating(4);
	Movies[1].addRating(5);
	Movies[1].addRating(5);
	Movies[1].addRating(5);
	Movies[1].printInfo();
	double  y = Movies[1].getAverage();
	cout << "Average Rating for Snowden is " << y << endl;
	cout << endl;


	Movies[2].addRating(1);
	Movies[2].addRating(1);
	Movies[2].addRating(1);
	Movies[2].addRating(3);
	Movies[2].addRating(5);
	Movies[2].printInfo();
	double  z = Movies[2].getAverage();
	cout << "Average Rating for Last Call is " << z << endl;

	cout << endl;

	system("pause");

	return EXIT_SUCCESS;
}
