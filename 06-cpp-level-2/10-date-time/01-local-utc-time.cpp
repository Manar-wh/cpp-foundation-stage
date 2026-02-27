#include <iostream>
#include <ctime>

#pragma warning(disable : 4996) ;

using namespace std;


int main()
{

    time_t t = time(0);
    cout << t;

    /*char* dt = ctime(&t);
    cout << "Local Date and Time is : " << dt << endl;

    tm* UTCtime = gmtime(&t);
    dt = asctime(UTCtime);
    cout << "UTC Date and Time is : " << dt << endl;*/

    return 0;
}
