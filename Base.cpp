                                                                            //Please read the README.txt file. It contains important information


#include <iostream>                                                     //Including the <cstring> library for strlen() and strtoull(), and the iostream library for input/output"
#include <cstring>

using namespace std;

void Base(int base,unsigned long long int number);
bool InputBase(int &base);
bool InputNumber(unsigned long long int& number);
void Base(int base, unsigned long long int number);
bool ChekNumbers(char* number);                                                                                     

int main(){

unsigned long long int number;

int base;

char c;

while(true){

    if(InputNumber(number)==true&&InputBase(base)==true){                //if the input of the number and the input of the base are false you need to re-enter the number and the base


    if(number==0){cout<<"0"<<endl;}else{

        Base(base, number);

        cout<<endl;

        cout<<"End program? [1]Yes [Any other key]No:";

        cin>>c;

        if(c=='1')exit(1);}

    }else{
        
        cout<<"Please re-enter the number and the base correctly."<<endl;

    }

}

    return 0;
}

bool InputBase(int &base){                              //check the input of the base
    
    char cnumbers[9999];
    
    bool res;
    
    cout<<"Enter the base: ";
    
    cin>>cnumbers;
    
    res=ChekNumbers(cnumbers);
    
    if(res==false){
    
        cout<<"You must use only integer number (positive)[max 19 digits]!!"<<endl;
    
        return false;
    
    }
    
    base=strtoull(cnumbers,nullptr,10);                  //strtoull returns an unsigned long long int from an array of char
    
    if(base>62){
    
        cout<<"Base greater than 62. Error!!"<<endl;
    
        return false;
    
    }

    if(base<2){

        cout<<"Base must be a Natural number (b>1)"<<endl;
    
        return false;
    }
    
    return true;
}




bool InputNumber(unsigned long long int& number){           //check the input of the number

    char cnumbers[99];

    bool res;

    cout<<"Enter the number: ";
    cin>>cnumbers;
    res=ChekNumbers(cnumbers);

    if(res==false){

        cout<<"You must use only number integer (positive)[max 19 digits]!!"<<endl;

        return false;

    }
     
    number=strtoull(cnumbers,nullptr,10);
    
    if(number<0){

        cout<<"Number must be a Natural number (n>=0)"<<endl;
    
        return false;
    }

    return true;

}


void Base(int base,unsigned long long int number) {                 //from decimal base to the base selected by the user

    
    
    if(number<=0)return;
    
    int modulus = number % base;
    
    Base(base, number / base);
    
    if(modulus>35){
    
        char b=(char) ('a'+(modulus-36));
    
        cout<<b;
    
    }
    
    else if (modulus > 9) {
    
        char b=(char) ('A'+(modulus-10));
    
        cout<<b;
    
    } else {
    
    
        cout<<modulus;
    
    }
    
}



bool ChekNumbers(char* number){                         //check if the string is correct, so if it is a Natural number (n>=0)

    int lenght=strlen(number);
    
    if(lenght+1>19)return false;

    for(int i=0;i<lenght;i++){

        if(number[i]<'0'||number[i]>'9'){

            return false;

        }

    }

    return true;

}





