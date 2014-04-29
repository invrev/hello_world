#include<iostream>
#include<math.h>
using namespace std;

//Repeated exponentiation
int get_exp (int a,int n) {
    if ( n == 0) {
        return 1;
    } else if (n == 1) {
       return a;
    } else {
     int temp_ = 0;
     temp_ = get_exp (a,n/2);
     return  (temp_ * temp_ * pow(a,n%2));
    }
}

//a : number n : exponent  m : mod
//Mod property : ab % m = ((a%m) (b%m)) % m
//Also note : 0 % n = 0 
//t(n) : log (n)
int get_mod_exp(int a,int n,int m) {
    if (n == 0) {
        return 1;
    } else if (n == 1) {
        return a % m;
    }else {
        int temp_ = 0;
        int ans_ = 0;
        temp_ = get_mod_exp (a,n/2,m);
        temp_ = (temp_ % m);
        ans_  = (temp_*temp_*pow(a,n%2)) ;
        ans_ = ans_ % m;
        return (ans_);
    }
}



int main () {
    cout << "get_exp () = " << get_exp (2,5) << endl;
    cout << "get_exp () = " << get_exp (2,4) << endl;
    cout << "get_mod_exp() = " << get_mod_exp (3,5,7) << endl;
}
