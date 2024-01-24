//=======================================================================================================
//                                                                                                      =
//............................Pass-by-Pointer...........................................................=
//                                                                                                      =
//=======================================================================================================
#include <iostream>
// Pass-by-Pointer:

/*

It's a mechanism for passing arguments to functions where the memory address
of the variable is passed, rather than the value itself.

This allows the function to directly access and modify the original variable in the calling function.

Declare a pointer parameter using the asterisk (*) symbol in the function signature.
Pass the address of the variable using the & (address-of) operator when calling the function.
Changes made inside the function using the pointer are reflected in the original variable.

*/

void doubleValue(int* ptr) {  // ptr is a pointer to an integer
    *ptr = *ptr * 2;  // Dereference the pointer to modify the value
}


// Swapping two variables:  
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

//Modifying an array within a function:
void reverseArray(int* arr, int size) {
    for (int i = 0; i < size / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}

// Returning multiple values from a function:

void getMinMax(int arr[], int size, int* min, int* max) {
    *min = arr[0];
    *max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < *min) {
            *min = arr[i];
        }
        else if (arr[i] > *max) {
            *max = arr[i];
        }
    }
}

//=======================================================================================================
//                                                                                                      =
//............................Pass-by-Refrence...........................................................=
//                                                                                                      =
//=======================================================================================================


//  Pass-by-reference is a method for passing arguments to functions
//  where the memory address of the variable is passed,
//  instead of the value itself. This allows the function to directly
//  modify the original variable in the calling function, not just a copy.

/*

You declare the parameter with a reference symbol (&) in the function signature.
Any changes made inside the function are reflected in the original variable in the calling function.
This can be efficient for large data structures and situations where you need the function to modify the original variable.

*/



void adjustRectangleDimensions(int& width, int& height) {
    // Ensure width is always larger than height
    if (width < height) {
        int temp = width;
        width = height;
        height = temp;
    }

    // Adjust dimensions based on specific criteria
    width *= 1.2;  // Increase width by 20%
    height -= 5;   // Decrease height by 5 units
}


int main() {
    int num = 5;
    doubleValue(&num);  // Pass the address of num
    std::cout << num;  // Output: 10 (original value is doubled)

    //Swapping two variables:

    int x = 5, y = 10;
    swap(&x, &y);
    std::cout << "x: " << x << ", y: " << y; // Output: x: 10, y: 5

    //Modifying an array within a function:
    int arr[] = { 1, 2, 3, 4, 5 };
    reverseArray(arr, sizeof(arr) / sizeof(arr[0]));
    for (int num : arr) {
        std::cout << num << " "; // Output: 5 4 3 2 1
    }

    //  Returning multiple values from a function:
    int arr[] = { 4, 2, 7, 1, 9 };
    int min, max;
    getMinMax(arr, sizeof(arr) / sizeof(arr[0]), &min, &max);
    std::cout << "Min: " << min << ", Max: " << max; // Output: Min: 1, Max: 9
}
