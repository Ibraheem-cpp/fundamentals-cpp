#include<iostream>
using namespace std;

void right_angle_triangle(int a);
void inverted_right_angle_triangle(int a);
void pyramid(int a);
void number_triangle(int a);
void right_aligned_triangle(int a);
void diamond(int a);
void hourglass(int a);
void hollow_square(int a);
void hollow_pyramid(int a);
void X_pattern(int a);
void UK_flag(int a);

int main(){

    int n;
    cout << "Enter The Number : ";
    cin >> n;
    cout << endl;
    UK_flag(n);
    cout << endl;

    return 0;
}

void right_angle_triangle(int a){
    for(int i=0;i<a;i++){
        for(int j=0;j<=i;j++){
            cout << "*";
        }
        cout << endl;
    }
}
void inverted_right_angle_triangle(int a){
    for(int i=0;i<a;i++){
        for(int j=a-i-1;j>=0;j--){
            cout << "*";
        }
        cout << endl;
    }
}
void pyramid(int a){
    for(int i=0;i<a/2 + 1;i++){
        for(int j=0;j<a-i-1;j++){
               cout << " ";
        }
         for(int k=0;k<i*2 + 1;k++){
                     cout << "*";
            }
        cout << endl;
    }
}
void number_triangle(int a){
    int b=1;
    for(int i=1;i<=a;i++){
        for(int j=1;j<=i;j++){
            cout << b << " ";
            b++;
        }
        cout << endl;
    }
}
void right_aligned_triangle(int a){
    
    for(int i=0;i<a;i++){
        for(int j=0;j<a-i;j++){
            cout << " ";
        }
        for(int k=0;k<=i;k++){
            cout << "*";
            
        }
        cout << endl;
    }
}
void diamond(int a){
    for(int i=0;i<a/2;i++){ 
        for(int j=0;j<=(a/2)-i;j++){
               cout << " ";
        }
          for(int k=0;k<i*2 + 1;k++){
                     cout << "*";                       
            }
        cout << endl;
    }
    for(int i=0;i<a/2+1;i++){
      for(int j=0;j<=i;j++){
            cout << " ";
        }
        for(int k=0;k<a-(i+i);k++){
            cout << "*";
        }
       cout << endl;
    }
}
void hourglass(int a){
      for(int i=0;i<a/2;i++){
        
        for(int j=0;j<=i;j++){
            cout << " ";
        }
        for(int k=0;k<a-(i+i);k++){
            cout << "*";
        }
       cout << endl;
    }

    for(int i=0;i<a/2 + 1;i++){ 
        for(int j=0;j<=(a/2)-i;j++){
               cout << " ";
        }
          for(int k=0;k<i*2 + 1;k++){
                     cout << "*";
            }
        cout << endl;
    }


}
void hollow_square(int a){
        for(int i=0;i<a;i++){
            for(int j=0;j<a;j++){
                if(i==0 || i==a-1 || j==0 || j==a-1){
                    cout << "*";
                }
                else 
                  cout << " ";
            }
            cout << endl;
        }
}
void hollow_pyramid(int a){
        for(int i=0;i<a;i++){
            for(int j=0;j<a;j++){
                if(i+j==a/2 || j-i==a/2 || i==a/2){
                    cout << "*";
                }
                else
                    cout << " ";
            }
            cout << endl;
        }
}
void X_pattern(int a){
    for(int i=0;i<a;i++){
        for(int j=0;j<a;j++){
            if(i==j || i+j == a-1 || i==0 || i==a-1 || j==0 || j==a-1){
                cout << "*";
            }
            else{cout << " ";}
        }
        cout << endl;
    }
}
void UK_flag(int a){
    for(int i=0;i<a;i++){
        for(int j=0;j<a;j++){
            if(i==j || i+j == a-1 || i==0 || i==a-1 || j==0 || j==a-1 || i == a/2 || j == a/2){
                cout << "*";
            }
            else{
                cout << " ";
            }
        }
        cout << endl;
    }
}



