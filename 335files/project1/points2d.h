// Ashfak Uddin
/*
	This class can take in any type of objects, but it's meant for ints/doubles. An object of the class can take in a
	list of numbers with the >> operator, and can print itself with the << operator. A user can add together two
	Point2D objects, where the length of the resulting object is the bigger length between the two that're getting added.
	You can copy over, move-assign, move, and delete from memory, objects created from this class.

	It has two instance variables; a size_, and a sequence.
	The size_ represents the size of the object, and will be the length of the sequence variable.
	The sequence variable is a size X 2 2D array, where there are size amount of rows and each row has two indices.
	Each row represents a (x, y) point - that's why the class is meant for ints/doubles.

	For inputting data into an object, the user first inputs a number that will be the size of the object. Afterwards, they have to input size*2
	amount of numbers (for size amount of pairs). If they input more than that, it's okay - the extra numbers might be used on the next >> call.

	It has some input validation, where you can't enter a fractional value for the size of a sequence, and you can't enter any letters
	at all (because that doesn't make much sense, does it?). If you do, it throws an error and aborts the program entirely.

	Also, if the user inputted too little numbers (2 3 4 5, as an example), the program aborts the same.
*/

#ifndef CSCI335_HOMEWORK1_POINTS2D_H_
#define CSCI335_HOMEWORK1_POINTS2D_H_

#include <array>
#include <iostream>
#include <cstddef>
#include <string>
#include <sstream>

/*
	@param std::string zero, will be a value the user inputted

	This function was my attempt on input validation - it rejects any non-digit characters, but if it's a period (for a fractional value),
	it continues on but keeps note that it already found a period. If it finds another one, it rejects the string.

	@return-value bool, returns true if it's a valid number by my conditionals, false otherwise.

*/
bool validNumber(std::string zero)
{
	size_t len = zero.length();
	bool onePeriod = false;
	for (size_t j = 0; j < len; j++)
	{
		if (j == 0 && zero[j] == '-') // negative sign at beginning of string is allowed
			continue;
		if (zero[j] == '.')
		{
			if (onePeriod)
				return false;
			onePeriod = true; // keeping track of if we've already seen a dot
			if (j < len - 1) // checking if . is before end of string
				continue;
			else
				return false;
		}
		if (!isdigit(zero[j])) // if not number, auto false
		{
			return false;
		}
	}
	return true;
}
namespace teaching_project {

// Place comments that provide a brief explanation of the class,
// and its sample usage.
template<typename Object>
class Points2D
{
	public:
		// Default "big five" -- you have to alter them for your assignment.
		// That means that you will remove the "= default" statement.
		//  and you will provide an implementation.

		// Zero-parameter constructor.
		// Set size to 0, and sequence to a nullptr.
		Points2D()
		{
			size_ = 0;
			sequence_ = nullptr;
		}
		// Copy-constructor
	        // copies over the values from an already setup Point2D to this new object.
               	Points2D(const Points2D &rhs)
		{
			size_ = rhs.size_;
			sequence_ = new std::array<Object, 2>[size_];
			for (size_t i = 0; i < size_; i++)
			{
				sequence_[i][0] = rhs.sequence_[i][0];
				sequence_[i][1] = rhs.sequence_[i][1];
			}
		}
                // overloading the = operator, making the left side equal to the right side in all aspects.
		Points2D& operator=(const Points2D &rhs)
		{
			size_  = rhs.size_;
			sequence_ = new std::array<Object, 2>[size_];
			for (size_t i = 0; i < size_; i++)
			{
				sequence_[i][0] = rhs.sequence_[i][0];
				sequence_[i][1] = rhs.sequence_[i][1];
			}
			return *this;
		}

		// Move-constructor.
                // swaps two Point2D objects when one is not needed anymore
		Points2D(Points2D &&rhs)
		{
			std::swap(rhs.size_, this->size_);
			std::swap(rhs.sequence_, this->sequence_);
			rhs.size_ = 0;
//                        delete rhs.sequence_;
			rhs.sequence_ = nullptr;
		}
		// Move-assignment.
		// Just use std::swap() for all variables.
		Points2D& operator=(Points2D &&rhs)
		{
			std::swap(rhs.size_, this->size_);
			std::swap(rhs.sequence_, this->sequence_);
			return rhs;
		}
                //deallocates memory when the Point2D object isn't needed anymore
		~Points2D()
		{
                        delete sequence_;
                        sequence_ = nullptr;
		}

		// End of big-five.

		// One parameter constructor.
                // initializes sequence with a 1D std:;array of even length
       		Points2D(const std::array<Object, 2>& item)
		{
			size_ = item.size()/2;
			sequence_ = new std::array<Object, 2>[size_];
			for (size_t i = 0; i < size_; i++)
			{
				sequence_[i][0] = item[i*2];
				sequence_[i][1] = item[i*2+1];
			}
		}

                // returns size of object
		size_t size() const
		{
			return size_;
		}

		// @location: an index to a location in the sequence.
		// @returns the point at @location.
		// const version.
		// abort() if out-of-range.
		const std::array<Object, 2>& operator[](size_t location) const
		{
			if (location >= size_ || location < 0)
				abort();
			return sequence_[location];
		}

		//  @c1: A sequence.
		//  @c2: A second sequence.
		//  @return their sum. If the sequences are not of the same size, append the
		//    result with the remaining part of the larger sequence.
		friend Points2D operator+(const Points2D &c1, const Points2D &c2)
		{
			Points2D ret;
			int a_size = c1.size_, b_size = c2.size_, i = 0;
			ret.sequence_ = new std::array<Object, 2>[std::max(a_size, b_size)];
			ret.size_ = std::max(a_size, b_size);
			while (i < a_size && i < b_size)
			{
				ret.sequence_[i][0] = (c1[i][0] + c2[i][0]);
				ret.sequence_[i][1] = (c1[i][1] + c2[i][1]);
				i++;
			}
			while (i < a_size)
			{
				ret.sequence_[i][0] = (c1[i][0]);
	                        ret.sequence_[i][1] = (c1[i][1]);
	                        i++;
			}
			while (i < b_size)
			{
 				ret.sequence_[i][0] = (c2[i][0]);
                                ret.sequence_[i][1] = (c2[i][1]);
                                i++;
			}
			return ret;
		}

		// Overloading the << operator.
                // prints each row in a (x, y) fashion, and goes to a new line after
		friend std::ostream &operator<<(std::ostream &out, const Points2D &some_points)
		{
                        if (some_points.size_ < 0)
                                return out;
			if (some_points.size_ == 0)
				out << "()";
			for (size_t i = 0; i < some_points.size_; i++)
				out << "(" << some_points[i][0] << ", " << some_points[i][1] << ") ";
			out << "\n";
			return out;
		}

		// Overloading the >> operator.
		// Read a chain from an input stream (e.g., standard input).
                // accepts a number as size_, then requires 2*size_ values to fill in array.
                // any non-number value, not enough values, or a fractional value for size will cause program to abort();
		friend std::istream &operator>>(std::istream &in, Points2D &some_points)
		{
			std::string string_size_holder = "";
			if (in >> string_size_holder && validNumber(string_size_holder))
			{
				if (string_size_holder.find('.') != std::string::npos)
				{
//					std::cerr << "size has to be whole number!\n";
					std::cerr << "ERROR\n";
					abort();
				}
				int num = std::stoi(string_size_holder);
				some_points.size_ = num;
			}
			else
			{
				std::cerr << "ERROR\n";
				//std::cerr << "Inputted an invalid string to be converted into a number\n";
				abort();
			}
			if (some_points.sequence_ != nullptr)
			{
				delete some_points.sequence_;
				some_points.sequence_ = nullptr;
			}
			some_points.sequence_ = new std::array<Object, 2>[some_points.size_];
			std::string zero = "", one = "";
			for (size_t i = 0; i < some_points.size_; i++)
			{
				if (!(in >> zero >> one))
                                {
					std::cerr << "ERROR\n";
					//std::cerr << "\nDidn't give enough inputs\n";
					abort();
				}
				else
				{
					if (!validNumber(zero) || !validNumber(one))
					{
						std::cerr << "ERROR\n";
						//std::cerr << "Inputted an invalid string to be converted into a number\n";
						abort();
					}
					// I wanted to check if the current type was int but user inputted a double, but didn't know how to do that without googling
					some_points.sequence_[i][0] = std::stod(zero);
					some_points.sequence_[i][1] = std::stod(one);
				}
			}
                        std::cout << "\n";
			return in;
		}
	private:
		// Sequence of points.
		std::array<Object, 2> *sequence_;
		// Size of sequence.
		size_t size_;
};

}  // namespace teaching_project
#endif // CSCI_335_HOMEWORK1_Points2D_H_
