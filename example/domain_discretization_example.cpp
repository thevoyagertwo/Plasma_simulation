// compile g++ domain_discretization_example.cpp -o domain-test
#include <vector>
#include <iostream>
#include <fstream>

namespace Const {
    const double q =   1.602176634e-19;    // electronic charge
    const double eps = 8.854187812e-12;    // epsilon_0  permittivity
    const double me =  9.109383701e-31;    // mass of an electron
}
using namespace std;
using namespace Const;
// using dvector = vector<double>;    // can use this to make writing code easier

// function prototypes
bool outputData (double x0, double dx, const vector<double> &phix,
            const vector<double> &rhox, const vector<double> &efx);

int main () {
    const int nix = 101;               // number of nodes for x
    const double x0 = 0;              // x mesh origin
    const double xm = 1;              // x mesh ending
    double dx = (xm-x0)/(nix-1);      // x node spacing

    vector<double> phix(nix);         // x potential
    vector<double> rhox (nix,q*1e12); // x charge density  setting to 1e12 q
    vector<double> efx(nix);          // x electric field

    outputData(x0,dx,phix,rhox,efx);

return 0;
}

bool outputData (double x0, double dx, const vector<double> &phix,
            const vector<double> &rhox, const vector<double> &efx) {
                ofstream out("domain_example.csv"); // opens file to be written
                if (!out) { // checks if can open file for output if not returns false as outputData fun is bool
                    cerr << " could not open output csv file" << endl;
                    return false;
                }

                out << "x, potential,  charge density, electric field\n"; // writing csv header

                for (int i=0;i<phix.size();i++){
                    out << x0+i*dx;                                       // writing ith x position
                    out <<","<< phix[i] <<","<< rhox[i] <<","<< efx[i] ; // writing respective potential,e density,elec field
                    out << "\n";                                         // new line, endl not used for performance reasons(clears buffer)
                }

                return true; // file closes automatically when exiting bool
            }

