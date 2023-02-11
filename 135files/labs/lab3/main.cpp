#include <fstream>
#include <cstdlib>
#include <climits>
#include <iostream>
using namespace std;

int main(){
    cout<< "Enter starting date: ";
    string start; cin >> start;
    cout << "Enter ending date: ";
    string end; cin >> end;
    
    double eastSt, eastEl, westSt, westEl;
    string date,junk;
    
    ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) {
        cerr << "File cannot be opened for reading." << endl;
        exit(1);
    }
	cout << 1 << endl;
    getline(fin,junk);
    while(fin >> date){
        if(date==start){
            break;
        }
        fin.ignore(INT_MAX, '\n');
    }
    while(fin >> eastSt >> eastEl >> westSt >> westEl){
        if(date == end){
            if(eastEl>westEl){
                cout << date << " East"<<endl;
                fin.close();
            }else if(eastEl<westEl){
                cout << date << " West"<<endl;
                fin.close();
            }else{
                cout << date << " Equal"<<endl;
                fin.close();
            }
        }
        else
		{
			if(eastEl>westEl){
    	 	    cout << date << " East"<<endl;
        	}else if(eastEl<westEl){
            	cout << date << " West"<<endl;
        	}else{
            	cout << date << " Equal"<<endl;
        
			}
		}
		//cout << "date: " << date << endl;
        fin.ignore(INT_MAX, '\n');
		fin >> date;
    }
    return 0;
}