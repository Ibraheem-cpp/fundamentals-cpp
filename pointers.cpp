#include<iostream>
using namespace std;

const int S = 3;


void swap_values(int* a , int* b);
void swap_address(int** a , int** b);
void twice(int* a);
int* max(int* a , int* b);
void print_ptr(int* a , int s);
void even_and_odd(int* a , int s);
float average(int* a , int s);
void reverse_arr(int* a , int s);
int* min(int* a);
int* swap_first_last(int* a);
void copy_arr(int* a , int* b , int s);
void copy_arr_reverse(int* a , int* b , int s);
int is_sorted(int* a , int s);
int sum_of_squares(int* a , int s);
int* increment_1(int* a , int s);
int* all_square(int* a , int s);
int* rotate_right(int*a , int s);
int* move_zero_to_end(int* a , int s);
void remove_duplicates(int* a , int s);

      // DYNAMIC MEMORY
      
void input(int* a , int n);
int* create_array(int n);
void free_memory(int*& a);
int** create_matrix(int r , int c);
void enter_matrix(int** mat , int r , int c);
void print_matrix(int** mat , int r , int c);
void free_matrix(int**& mat , int r , int c);
int** tranpose(int** mat , int r , int c);
bool is_identity(int** mat , int r , int c);
bool is_upper_triangular(int** mat , int r , int c);
bool is_lower_triangular(int** mat , int r , int c);
int main(){

    int rows,cols;
    cout << "Enter Rows And Columns of Matrix : ";
    cin >> rows >> cols;
    int** matrix = create_matrix(rows,cols);
    enter_matrix(matrix,rows,cols);
    print_matrix(matrix,rows,cols);
    
    if(is_lower_triangular(matrix,rows,cols)){cout << "It is a Lower Triangular Matrix.";}
    else {cout << "It is not a Lower Triangular Matrix.";}

    free_matrix(matrix,rows,cols);
   

    return 0;
}
void twice(int* a){
    *a = *a * 2;
}
int* max(int* a , int* b){
    if(*a > *b){return a;}
    else return b;
}
void print_ptr(int* a , int s){
    cout << endl << "The Array is : { ";
    for(int i=0;i<s;i++){
        cout << *(a+i) << " ";
    }
    cout << "}" << endl;
}
void even_and_odd(int* a , int s){
    int even = 0 , odd = 0;
    for(int i=0;i<S;i++){
        if(*(a+i)%2 == 0){
            even++;
        }
        else 
            odd++;
    }
    cout << "Even Numbers : " << even << endl;
    cout << "Odd Numbers : " << odd;
}
float average(int* a , int s){
    float sum = 0 , avg;
    for(int i=0;i<S;i++){
        sum = sum + *(a+i);
    }
    avg = sum/S;
    return avg;
}
void swap_values(int* a , int* b){
     int temp;
     temp = *a;
     *a = *b;
     *b = temp;
}
void swap_address(int** a , int** b){
     int* temp = *a;
     *a = *b;
     *b = temp;
}
void reverse_arr(int* a , int s){
    int* arr = new int[s];
    for(int i=s-1 , j=0;i>=0;i--,j++){
        arr[j] = *(a+i);
    }
    for(int i=0;i<s;i++){
        *(a+i) = *(arr+i);
    }
    delete[] arr;
    print_ptr(a,s);
}
int* min(int* a){
    int* min = a;
    for(int i=0;i<S;i++){
        if(*(a+i) < *(min)){
            (min) = (a+i);
        }
    }
    return min;
}
int* swap_first_last(int* a){
    int temp = *(a);   // temp = a[0]
    *(a) = *(a+S-1);   // a[0] = a[S-1]
    *(a+S-1) = temp;   // a[S-1] = temp
    return a;
}
void copy_arr(int* a , int* b , int s){
    for(int i=0;i<s;i++){
        *(b+i) = *(a+i);
    }
}
void copy_arr_reverse(int* a , int* b , int s){
    for(int i=0,j=S-1;i<s;i++,j--){
        *(b+i) = *(a+j);
    }
}
int is_sorted(int* a , int s){
    int f = 1;
    for(int i=0;i<s-1;i++){
        if(*(a+i) > *(a+i+1)){
            f = 1;
            break;
        }
        else 
           f++;
    }
       if(f==s){return 1;}

     for(int i=0;i<s-1;i++){
        if(*(a+i) < *(a+i+1)){
            f = 1;
            break;
        }
        else 
           f++;
    }
      if(f==s){return 0;}
          else 
           return -1;
}
int sum_of_squares(int* a , int s){
    int f = 0;
    for(int i=0;i<s;i++){
        f = f + (*(a+i) * *(a+i));
    }
    return f;
}
int* increment_1(int* a , int s){
    for(int i=0;i<s;i++){
        *(a+i) = *(a+i) + 1;
    }
    return a;
}
int* all_square(int* a , int s){
    for(int i=0;i<s;i++){
        *(a+i) = *(a+i) * *(a+i);
    }
    return a;
}
int* rotate_right(int*a , int s){
    int temp = *(a+s-1);
    for(int i=s-1;i>0;i--){
        *(a+i) = *(a+i-1);
    }
    *(a) = temp;
    return a;
}
int* move_zero_to_end(int* a , int s){
    for(int i=0;i<s;i++){
        if(*(a+i) == 0){
            for(int j=s-1;j>i;j--){
                if(*(a+j) != 0){
                    swap(*(a+i),*(a+j));
                    break;
                }
            }
        }
    }
    return a;
}
void remove_duplicates(int* a , int s){
    int s1 = s;
    for(int i=0;i<s1;i++){
        for(int j=i+1;j<s1;j++){
            if(*(a+i) == *(a+j)){
                while(j<s1-1){
                    swap(*(a+j) , *(a+j+1));
                    j++;
                }
                s1--;
                i--;
            }
        }
    }
    cout << "After Removing Duplicates. ";
    print_ptr(a,s1);
}

         // DYNAMIC MEMORY
  
void input(int* a , int n){
    cout << " Enter Elements : ";
    for(int i=0;i<n;i++){
         cin >> a[i];
    }
}
int* create_array(int n){
    int* arr = new int[n];
    input(arr,n);
    print_ptr(arr,n);
    return arr;
}
void free_memory(int*& a){
    delete[] a;
    a = nullptr;
}
int** create_matrix(int r , int c){
    int** matrix = new int*[r];
    for(int i=0;i<r;i++){
        matrix[i] = new int[c];
    }
    return matrix;
}
void enter_matrix(int** mat , int r , int c){
    cout << "Enter Elements : " << endl;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin >> mat[i][j];
        }
    }
}
void print_matrix(int** mat , int r , int c){
     cout << endl;
    for(int i=0;i<r;i++){
        cout << "| ";
        for(int j=0;j<c;j++){
            cout << mat[i][j] << " ";
        }
        cout << "|" << endl;
    }
    cout << endl;
}
void free_matrix(int**& mat , int r , int c){
      for(int i=0;i<r;i++){
        delete[] mat[i]; 
    }
    delete[] mat;
    mat = nullptr;
}
int** tranpose(int** mat , int r , int c){
      int r1 = c;
      int c1 = r;
      int** transp = create_matrix(r1,c1);
      for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
            transp[i][j] = mat[j][i];
        }
      }
      
      return transp;
}
bool is_identity(int** mat , int r , int c){
    if(r!=c){return false;}
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(i==j){
                if(mat[i][j] != 1){return false;}
            }
            else if(i!=j){
                if(mat[i][j] != 0){return false;}
            }
        }
    }
    return true;
}
bool is_upper_triangular(int** mat , int r , int c){
    if(r!=c){return false;}
    for(int i=0;i<r;i++){
        for(int j=0;j<i;j++){
            if(mat[i][j] != 0){return false;}
        }
    }
    return true;
}
bool is_lower_triangular(int** mat , int r , int c){
    if(r!=c){return false;}
    for(int i=0;i<r;i++){
        for(int j=c-1;j>i;j--){
            if(mat[i][j] != 0){return false;}
        }
    }
    return true;
}

