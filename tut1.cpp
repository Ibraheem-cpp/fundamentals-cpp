#include<iostream>
#include<cmath>
using namespace std;

int factorial(int a);
bool is_leap(int a);
void is_greatest(int a,int b,int c);
void table(int a);
int reverse(int a);
bool is_palindrome(int a);
int number_of_digits(int a);
int sum_of_digits(int a);
int product_of_digits(int a);
int occurence_of_digit(int a , int b);
int last_digit(int a);
int first_digit(int a);
void max_sum(int a , int b);
bool is_even_digits(int a);
bool is_Armstrong(int a);
void number_of_palindromes(int a , int b);
void number_of_Armstrong(int a , int b);
bool is_strong_number(int a);
void fibonacci_sequence();
bool is_prime(int n);

int main(){
    
    fibonacci_sequence();

    return 0;
}

int factorial(int a){
    int product = 1;
    for(int i=a;i>0;i--){
        product = product * i;
    }
    return product;
}
bool is_leap(int a){
    if(a%4!=0){
        return false;
    }
    else if(a%100==0){
        if(a%400==0){
            return true;
        }
        else
         return false;
    }
    else 
     return true;
}
void is_greatest(int a,int b,int c){

    if (a == b && b == c){
        cout << "All are equal.";
    }
    else if(a>=b && a>=c){
        if(a==b){
            cout << "a and b are greatest.";
        }
        else if(a==c){
            cout << "a and c are greatest.";
        }
        else 
         cout << a << " a Is Greatest.";
    }
    else if(b>=a && b>=c){

        cout << b << " b Is Greatest.";
    }
    else if(c>=b && c>=a){
        cout << c << " c Is Greatest.";
    }
}
void table(int a){
    for(int i=1;i<=10;i++){
        cout << a << " x " << i <<  " = " << a*i << endl;
    }
}
int reverse(int a){
    int num;
    int rev = 0;
    while (a > 0)
    {
        num = a%10;
        rev = (rev*10) + num;
        a = a/10;
    }
    return rev;
}
bool is_palindrome(int a){
    int num = a;
    if(reverse(num) == a){
        return true;
    }
    else
     return false;
}
int number_of_digits(int a){
    a = abs(a);
    int digits = 0;
    if(a == 0){
        return 1;
    }
    else {
        while(a>0){
            a = a/10;
            digits++;
        }
        return digits;
    }
}
int sum_of_digits(int a){
    a = abs(a);
    if(a==0){
        return 0;
    }
    else {
        int sum = 0 , num = 0;
        while(a>0){
            num = a%10;
            sum = sum + num;
            a = a/10;
        }
        return sum;

    }
}
int product_of_digits(int a){
    a = abs(a);
    if(a==0){
        return 0;
    }
        int product = 1 , num = 0;
        while(a>0){
            num = a%10;
            product = product * num;
            a = a/10;
        }
        return product;
    }
int occurence_of_digit(int a , int b){
    a = abs(a);
    if(a == 0 && b == 0){return 1;}
    int digit = 0 , num = 0;
    while(a>0){
         num = a%10;
         a = a/10;
         if(num == b){
            digit++;
         }
    }
    return digit;
}
int last_digit(int a){
    return a%10;
}
int first_digit(int a){
    int n = reverse(a);
    return n%10;
}
void max_sum(int a , int b){
    if(a>b){
        cout << "Invalid choice of Numbers.";
    }
    else {
       int num , sum , max_sum = 0;
        for(int i=a;i<=b;i++){
          sum = sum_of_digits(i);
           if(sum >= max_sum){
               max_sum = sum;
               num = i;
            }
        }
        cout << "The Number Whose Sum Of Digits is Greatest is : " << num << " , with a sum of : " << max_sum;
    }
     
}
bool is_even_digits(int a){
    a = abs(a);
    int num = 0;
    while(a>0){
        num = a%10;
        if(num%2 != 0){
            return false;
        }
        a = a/10;
    }
   return true;
}
bool is_Armstrong(int a){
    int digits = number_of_digits(a);
    int number_1 = a , number_2 = 0 , num = 0 , n;
    while(a>0){
        num = a%10;
        n = round(pow(num,digits));
        number_2 = number_2 + n;
        a = a/10; 
    }
    if(number_1 == number_2){
        return true;}
    else
     return false;
}
void number_of_palindromes(int a , int b){
    int count = 0;
    for(int i = a;i<=b;i++){
        if(is_palindrome(i)){
            count++;
        }
    }
    cout << "Number of Palindromes Between The Numbers Are : " << count << endl;
    int pal[count] = {0};
    int j=0;
    for(int i=a;i<=b;i++){
        if(is_palindrome(i)){
            pal[j] = i;
            j++;
        }
    }
    cout << "The Palindromes Are : ";
    for(int i=0;i<count;i++){
        cout << pal[i] << ",";
    }
}
void number_of_Armstrong(int a , int b){
        int count = 0;
    for(int i = a;i<=b;i++){
        if(is_Armstrong(i)){
            count++;
        }
    }
    cout << "Number of Armstrong Numbers Between The Numbers Are : " << count << endl;
    int arm[count] = {0};
    int j=0;
    for(int i=a;i<=b;i++){
        if(is_Armstrong(i)){
            arm[j] = i;
            j++;
        }
    }
    cout << "The Armstrong Numbers Are : ";
    for(int i=0;i<count;i++){
        if(i==0){cout << arm[i];}
        else
          cout << "," << arm[i];
    }
}
bool is_strong_number(int a){
    int number_1 = a , number_2 = 0 , num = 0 , n = 0;
    while(a>0){
        num = a%10;
        n = factorial(num);
        number_2 = number_2 + n;
        a = a/10;
    }
    if(number_1 == number_2){return true;}
    else {return false;}
}
void fibonacci_sequence(){
    int n;
    cout << "Enter the nth Fibonacci Number you want : ";
    cin >> n;
    long long int last_number = 1, second_last_number = 0, number;
    if(n >= 1){cout << 0 << " ";}
    if(n >= 2){cout << 1 << " ";}
    for(int i=2;i<n;i++){
            number = last_number + second_last_number;
            cout << number << " ";
            second_last_number = last_number;
            last_number = number;
    }
}
bool is_prime(int n){
    if(n == 0 || n == 1){return false;}
    else{
        for(int i=2;i<n;i++){
            if(n%i == 0){return false;}
        }
        return true;
    }
}





