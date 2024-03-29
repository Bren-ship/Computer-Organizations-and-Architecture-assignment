
#include <iostream>
#include <string>
#define TEXTTABLE_ENCODE_MULTIBYTE_STRINGS
#define TEXTTABLE_USE_EN_US_UTF8
#include "textTable.h"

using namespace std;
void Binary(){
int a[10], n, i;
cout<<"\nEnter the number to convert: ";
cin>>n;
string y= to_string(n);
for(i=0; n>0; i++)
{
a[i]=n%2;
n= n/2;
}
cout<<"\n==============================";
cout<<"\nBinary value of "<<y<<" is: ";
for(i=i-1 ;i>=0 ;i--)
{
cout<<a[i];
}
cout<<"\n==============================\n";
}
//convert decimal value to octal
int Octal(int decimal){
   int octal = 0;
   string temp = "";
   while (decimal > 0) {
      int remainder = decimal % 8;
      temp = to_string(remainder) + temp;
      decimal /= 8;
   }
   for (int i = 0; i < temp.length(); i++)
      octal = (octal * 10) + (temp[i] - '0');
   return octal;
}
//convert decimal value to hexadecimal
string Hexadecimal(int decimal){
   string hex = "";
   while (decimal > 0) {
      int remainder = decimal % 16;
      if (remainder >= 0 && remainder <= 9)
         hex = to_string(remainder) + hex;
      else
         hex = (char)('A' + remainder % 10) + hex;
      decimal /= 16;
   }
   return hex;
}
//convert decimal value to HTML
string HTML(int decimal){
   string html = to_string(decimal);
   html = "&#" + html + ";";
   return html;
}
//calculate the ASCII lookup table
void ASCIIlookuptable(char ch){
   int decimal = ch;
   string oct="" +Octal(decimal);
   TextTable t( '-', '|', '+' );
    t.add("Octal value");
    t.add("Decimal value");
    t.add("Hexadecimal value");
    t.add("HTML");
    t.endOfRow();

    t.add(to_string(Octal(decimal)));
    t.add(to_string(decimal));
    t.add(Hexadecimal(decimal));
    t.add(HTML(decimal));
    t.endOfRow();
    t.setAlignment( 2, TextTable::Alignment::RIGHT );
   cout<<endl;
   std::cout << t;

}

int main()
{
cout<<"Note:\n";
cout<<"\n 1. Number systems are used in a computer system \n for various operations such as storage, arithmetic operations among others.\n";
cout<<"\n 2. The ASCII look up operation below depicts various\n conversions of the user friendly keyboard input from the computer to\ndesired machine language for computations";
cout<<"\n 3. Binary is the basic computer arithmetic language.\n To perform an operation, the input has to be converted to base 2\n. Base 10 to base 2 below illustrates decimal computations";
int opt;
do {
   cout<<"\nChoose your desired test operation\n";
   cout<<"\n 1. Decimal to Binary Conversion\n 2. ASCII Lookup \n 3.Exit\n";
   cin>>opt;
   if(opt==1){
        Binary();
   } else if(opt==2){
// used to show how a computer looks up various number systems from the keyboard input
    char ch;
    cout<<"\n Enter a character"<<endl;
    cin>>ch;
    ASCIIlookuptable(ch);

   }

} while(opt!=3);

return 0;
}
