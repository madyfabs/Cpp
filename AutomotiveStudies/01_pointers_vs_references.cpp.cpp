/*
 * Exercise: Pointers vs References
 *
 * Create two functions to swap the values of two integers:
 *
 * 1. swapPointers(int* a, int* b)
 *    - Use pointers to access and modify the values.
 *
 * 2. swapReferences(int& a, int& b)
 *    - Use references to access and modify the values.
 *
 * In the main() function:
 * - Read two integer values from the user.
 * - Display the values before the swap.
 * - Call swapPointers() and display the result.
 * - Call swapReferences() and display the result again.
 *
 * Requirements:
 * - Use a temporary variable to perform the swap.
 * - The pointer version must use dereferencing (*).
 * - The reference version must not use pointers.
 * - Do not return the values from either function.
 */

#include <iostream>

using namespace std;


void swapPointers(int* a, int* b){

    int temp;

    temp = *a;
    *a = *b;
    *b = temp;

}

void swapReferences(int& a, int& b){

    int temp;

    temp = a;
    a = b;
    b = temp;

}

int main(void){
    
    int a = 10, b = 20;

    cout<<"Before the swap:"<<endl;
    cout<<a<<endl;
    cout<<b<<endl<<endl;
    
    swapPointers(&a, &b);
    cout<<"After using pointers:"<<endl;
    cout<<a<<endl;
    cout<<b<<endl<<endl;    
    
    swapReferences(a, b);
    cout<<"After using references:"<<endl;
    cout<<a<<endl;
    cout<<b<<endl;

    return 0;
}