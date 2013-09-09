#include <iostream>
#include <map>
#include <sstream>
using namespace std;
int main()
{ 
    string a,b,c,d;
    map <string,string>M;
    while(getline(cin,c),c.size())
    { 
        stringstream SS;
        SS << c;
        SS >> a>> b;
        M[b]=a;
    }

    while(cin>>d)   cout << (M.count(d) ? M[d] : "eh") << endl;

 /*
if(M.find(d)!=M.end())cout<<M[d]<<endl;
        else cout<<"eh\n";
*/

    return 0;
}
