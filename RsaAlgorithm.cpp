#include<iostream>
#include<stdio.h>
#include<string>
#include<math.h>
int gcd(int a, int b)
{
    // Everything divides 0
    if (a == 0)
       return b;
    if (b == 0)
       return a;
  
    // base case
    if (a == b)
        return a;
  
    // a is greater
    if (a > b)
        return gcd(a-b, b);
    return gcd(a, b-a);
}



// First select two numbers that are prime and are not equal for RSA to be successful.
int main(){
    std::cout << "Enter prime number P such that it is larger that 1" <<std::endl;
    double P;
    std::cin>>P;
    std::cout<<"Enter another prime number Q such that it is not equal to P"<<std::endl;
    double Q;
    std::cin>>Q;
    
    std::cout<<"Now we calculating n which is p*q"<<std::endl;
    double N;
    N=P*Q;
    std::cout<<"N = "<< N <<std::endl;

    std::cout<<"Lets calculate phi(n) which will be phi"<<std::endl;
    double phi;
    phi=(P-1)*(Q-1);
    std::cout<<"Value of phi is "<<phi<<std::endl;
    
    std::cout<<"Enter a value e such that gcd(phi,e) should be equal to 1"<<std::endl;
    std::cout <<"Condition of e should be such that e should be greater than 1 and less than phi(n)"<<std::endl;
    double e;
    bool gcd_True;
    while(gcd_True=true){
        std::cin>>e;
       if (gcd(phi,e)==1){
           break;
       }
    }
    std::cout<<"The value of e is "<<e<<std::endl;
    std::cout<<"gcd of ph1 and e are "<< gcd(phi,e)<<"<-- This step is for confirmation purposes"<<std::endl;
    
    // now that we have calculated e which is the public key in this algorithm the next step is to calcualte d
   

    
    double temp=1/e;
    std::cout<<temp<<std::endl;
    double d =fmod(temp,phi);
    std::cout<<"The value of the private key is "<<d<<std::endl;    
    
    std::cout<<"Enter a message after converting it from ascii to decimal"<<std::endl;
    double message;
    std::cin>>message;

    double cipher;
    cipher = pow(message,e);
    cipher = fmod(cipher,N);
    std::cout<<"The cipher of the message is "<<cipher<<std::endl;
    
    std::cout<<"Enter the key to cipher"<<std::endl;
    double decryption;
    double key;
    std::cin>>key;
    decryption = pow(cipher,key);
    decryption=fmod(decryption,N);
    std::cout<<"After deciphering, the message is "<<decryption<<std::endl;

    
    
    return 0;



}
