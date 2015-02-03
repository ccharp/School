# include <iostream>
using namespace std;

int main()
{
      const int SIZE_OF_ARRAY = 6;
      int i, temp_array[SIZE_OF_ARRAY];
      cout<<"Enter 6 temperatures:\n";

      // Get 6 temperatures from the user
      for(i=0; i<SIZE_OF_ARRAY; i++)
      {
        cin>>temp_array[i];
      }

      // Output the user entered temperatures
      cout<<"---------Temperature List-----------"<<endl;
      for(i=0; i<SIZE_OF_ARRAY; i++)
      {
        cout<<temp_array[i]<<", ";
      }

      cout<<"----------"<<endl;      
      cout<<"The 4th temperature you entered is: "<<temp_array[3]<<endl;

      cout<<"The first and last temperatures are: "<<temp_array[0]<<" and "<<temp_array[SIZE_OF_ARRAY-1]<<endl;

      return 0;
}


