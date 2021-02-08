#include <iostream>
using namespace std;
//#define DATA_TYPES
#define NAMES
void main()
{
	setlocale(LC_ALL, "Russian");
#if defined DATAT_TYPES //если определено ДАТА_ТАЙПС, то нижеследующий код будет виден компилятору
	//cout << true << endl;
	//cout << false << endl;
	//cout << (bool)0.001 << endl;
	//cout<<sizeof(short)<<endl;
	//cout << SHRT_MIN << "\t" << SHRT_MAX << endl;
	cout << sizeof(int) << endl;
	cout << INT_MIN << "\t" << INT_MAX << endl;
	cout << "0..." << UINT_MAX << endl;
#endif
#if defined NAMES
#endif
}
