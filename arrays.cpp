#include<iostream>
using namespace std;

const int MAX = 6;
const int R = 10;
const int C = 10;

void input_array(int a[]);
void print_array(int a[]);
int sum_of_elements(int a[]);
int max_element(int a[]);
int min_element(int a[]);
void reverse(int a[]);
int frequency_of_element(int a[],int b);
void even_and_odd(int a[]);
bool ascending_sorted(int a[]);
bool descending_sorted(int a[]);
bool palindrome_array(int a[]);
int second_max(int a[]);

   // 2D Arrays

void print_matrix(int a[][C] , int r , int c);
int sum_matrix(int a[][C] , int s);
void sum_rows_and_cols(int a[][C] , int s);
void transpose(int a[][C] , int r , int c);
bool is_symmetric(int a[][C] , int r , int c);
void diagonal_sum(int a[][C] , int r , int c);
void rotate_90(int a[][C] , int r , int c);
void saddle_point(int a[][C] , int r , int c);

int main(){
    
    int n;
    cout << "Enter Size : ";
    cin >> n;
    cout << endl;
    int* arr = new int[n];
    cout << " Enter Elements : ";
    for(int i=0;i<n;i++){
         cin >> arr[i];
    }
    cout << endl << " The Elements are : ";
    for(int i=0;i<n;i++){
         cout << arr[i] << " ";
    }

    delete[] arr;

    
    return 0;
}

void input_array(int a[]){
    cout << "Enter Elements Of Array : ";
        for(int i=0;i<MAX;i++){
            cin >> a[i];
        }
}
void print_array(int a[]){
        cout << "The Array is : { ";
        for(int i=0;i<MAX;i++){
            cout << a[i] << " ";
        }
        cout << "}" << endl;
}
int sum_of_elements(int a[]){
     int sum = 0;
     for(int i=0;i<MAX;i++){
        sum = sum + a[i];
     }
     return sum;
}
int max_element(int a[]){
     int max = a[0];
     for(int i=0;i<MAX;i++){
        if(max<a[i]){
            max = a[i];
        }
     }
     return max;
}
int min_element(int a[]){
     int min = a[0];
     for(int i=0;i<MAX;i++){
        if(min>a[i]){
            min = a[i];
        }
     }
     return min;
}
void reverse(int a[]){
    cout << "The Array In Reverse Order Is : ";
    for(int i=MAX-1;i>=0;i--){
        cout << a[i] << " ";
    }
}
int frequency_of_element(int a[],int b){
    int f = 0;
    for(int i=0;i<MAX;i++){
        if(a[i] == b){
            f++;
        }
    }
    return f;
}
void even_and_odd(int a[]){
    int even = 0 , odd = 0;
    for(int i=0;i<MAX;i++){
        if(a[i]%2 == 0){
            even++;
        }
        else 
            odd++;
    }
    cout << "Even Numbers : " << even << endl;
    cout << "Odd Numbers : " << odd;
}
bool ascending_sorted(int a[]){
    for(int i=0;i<MAX - 1;i++){
        if(a[i] > a[i+1]){
            return false;
        }
    }
    return true;
}
bool descending_sorted(int a[]){
    for(int i=0;i<MAX - 1;i++){
        if(a[i] < a[i+1]){
            return false;
        }
    }
    return true;
}
bool palindrome_array(int a[]){
    for(int i=0,j=MAX-1;i<MAX/2;i++,j--){
        if(a[i] != a[j]){
            return false;
        }
    }
    return true;
}
int second_max(int a[]){
    int max_1 = INT16_MIN;
    int max_2 = INT16_MIN;
    for(int i=0;i<MAX;i++){
        if(max_1<a[i]){
            max_2 = max_1;
            max_1 = a[i];
        }
        else if(a[i] > max_2 && a[i] != max_1){
            max_2 = a[i];
        }
    }
    return max_2;
}

    // 2D Arrays 

void print_matrix(int a[][C] , int r , int c){
    cout << endl;
    for(int i=0;i<r;i++){
        cout << "| ";
        for(int j=0;j<c;j++){
            cout << *(*(a+i)+j) << " ";
        }
        cout << "|" << endl;
    }
    cout << endl;
}
int sum_matrix(int a[][C] , int s){
    int sum = 0;
    for(int i=0;i<s;i++){
        for(int j=0;j<s;j++){
            sum = sum + a[i][j];
        }
    }
    return sum;
}
void sum_rows_and_cols(int a[][C] , int s){
    int sum_rows = 0;
    for(int i=0;i<s;i++){
        for(int j=0;j<s;j++){
            sum_rows = sum_rows + a[i][j];
        }
        cout << "Sum Of Row " << i+1 << " : " << sum_rows << endl;
        sum_rows = 0;
    }
    
    int sum_cols = 0;
    for(int i=0;i<s;i++){
        for(int j=0;j<s;j++){
            sum_cols = sum_cols + a[j][i];
        }
        cout << "Sum Of Column " << i+1 << " : " << sum_cols << endl;
        sum_cols = 0;
    }
}
void transpose(int a[][C] , int r , int c){
    int r1 = c;
    int c1 = r;
    int transpose[r1][c1] = {0};
    for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
            transpose[i][j] = a[j][i];
        }
    }
    cout << "The Transpose Of Matrix is : " << endl;
    for(int i=0;i<r1;i++){
        cout << "| ";
        for(int j=0;j<c1;j++){
            cout << *(*(transpose+i)+j) << " ";
        }
        cout << "|" << endl;
    }
    
}
bool is_symmetric(int a[][C] , int r , int c){
    if(r != c){return false;}
    else
      for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(a[i][j] != a[j][i]){
                return false;
            }
        }
      }
      return true;
}
void diagonal_sum(int a[][C] , int r , int c){
    if( r != c){
        cout << "Diagonal Does Not Exist.";
        return;
    }
    else {
        int sum = 0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(i == j){
                    sum = sum + a[i][j];
                }
            }
        }
        cout << "Sum Of Primary Diagonal Is : " << sum << endl;
        sum = 0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(i+j == r-1){
                    sum = sum + a[i][j];
                }
            }
        }
        cout << "Sum Of Secondary Diagonal Is : " << sum;
    }
}
void rotate_90(int a[][C] , int r , int c){
    int r1 = c;
    int c1 = r;
    int transpose[r1][c1] = {0};
    for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
            transpose[i][j] = a[j][i];
        }
    }
    int rotate_90[r1][c1] = {0};
    for(int i=0;i<r1;i++){
        for(int j=0,k=c1-1;j<c1;j++,k--){
            rotate_90[i][j] = transpose[i][k];
        }
    }
    cout << "After Rotating The Matrix 90 degrees." << endl;
    for(int i=0;i<r1;i++){
        cout << "| ";
         for(int j=0;j<c1;j++){
            cout << rotate_90[i][j] << " ";
         }
         cout << "|" << endl;
    }
}
void saddle_point(int a[][C] , int r , int c){
    bool not_found = true;
      for(int i=0;i<r;i++){
          int row_min = a[i][0];
          int col = 0;
         for(int j=1;j<c;j++){
            if(a[i][j] < row_min){
                row_min = a[i][j];
                col = j;
            }
         }
         bool is_saddle = true;
          for(int k=0;k<r;k++){
                if(a[k][col] > row_min){
                    is_saddle = false;
                    break;
                }
            }
            if(is_saddle){cout << "Saddle Point is : " << row_min << " at Index [ " << i << " " << col << " ]" << endl;
               not_found = false;}
          
        }
        if(not_found){cout << "No Saddle Points Found.";}
}


