#include <vector>
#include <string>
#include <iostream>
using namespace std;
class SequenceMap
{
	private:
		string recognition_sequence_;
		vector<string> enzyme_acronyms_;

	public:

		vector<string> getAcronyms()
		{
			return enzyme_acronyms_;
		}
		SequenceMap() = default;
		SequenceMap(const SequenceMap &rhs) = default;
        SequenceMap& operator=(const SequenceMap &rhs) = default;
		SequenceMap(SequenceMap &&rhs) = default;
		SequenceMap& operator=(SequenceMap &&rhs) = default;
        ~SequenceMap() = default;

		SequenceMap(const string &a_rec_seq, const string &an_enz_acro)
		{
			recognition_sequence_ = a_rec_seq;
			enzyme_acronyms_.push_back(an_enz_acro);
		}

		friend bool operator<(const SequenceMap& c1, const SequenceMap& c2)
		{
			return c1.recognition_sequence_ < c2.recognition_sequence_;
		}
		friend bool operator>(const SequenceMap& c1, const SequenceMap& c2)
		{
			return c1.recognition_sequence_ > c2.recognition_sequence_;
		}
		friend std::ostream &operator<<(std::ostream &out, const SequenceMap &some_points)
		{
			for (size_t i = 0; i < some_points.enzyme_acronyms_.size(); i++)
				out << some_points.enzyme_acronyms_[i] <<  " ";
			out << "\n";
			return out;
		}
		void Merge(const SequenceMap &other_sequence)
		{
			for (size_t i = 0;  i< other_sequence.enzyme_acronyms_.size(); i++)
				enzyme_acronyms_.push_back(other_sequence.enzyme_acronyms_[i]);
		}
		// Overloading the >> operator.
		// Read a chain from an input stream (e.g., standard input).
                // accepts a number as size_, then requires 2*size_ values to fill in array.
                // any non-number value, not enough values, or a fractional value for size will cause program to abort();
		friend std::istream &operator>>(std::istream &in, SequenceMap &some_points)
		{
			std::string holder;
			while (in >> holder)
				some_points.enzyme_acronyms_.push_back(holder);
            std::cout << "\n";
			return in;
		}
};
