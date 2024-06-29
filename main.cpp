#include <iostream>

using namespace std;

// Class representing a dynamic array (similar to a vector or ArrayList)
class ArrayList {
public:
    int size;          // Number of elements in the array list
    string* elements;  // Pointer to the array of elements

    // Constructor to initialize the array list with given elements
    ArrayList(int initial_size, string* initial_elements) {
        size = initial_size;
        elements = new string[size];
        for (int i = 0; i < size; ++i) {
            elements[i] = initial_elements[i];
        }
    }

    // Destructor to clean up dynamically allocated memory
    ~ArrayList() {
        delete[] elements;
    }

    // Method to add a new element to the array list
    void addElement(string new_element) {
        string* new_array = new string[size + 1];  // Step 1: Allocate new array with one extra space
        for (int i = 0; i < size; ++i) {  // Step 2: Copy existing elements to the new array
            new_array[i] = elements[i];
        }
        new_array[size] = new_element;  // Step 3: Add new element at the end
        delete[] elements;  // Step 4: Delete old array
        elements = new_array;  // Step 5: Update pointer to new array
        ++size;  // Step 6: Increment size
    }

    // Method to remove an element from the array list at a specified index
    void removeElement(int index) {
        for (int i = 0; i < size - 1; ++i) {
            if (i >= index) {
                elements[i] = elements[i + 1];
            }
        }
        --size;  // Decrement size
    }

    // Method to display all elements in the array list
    void displayElements() {
        for (int i = 0; i < size; ++i) {
            cout << elements[i] << endl;
        }
    }
};

int main() {
    // Initialize an array of initial elements
    string* initial_elements = new string[2];
    initial_elements[0] = "Hello, ";
    initial_elements[1] = "My";

    // Create an ArrayList object with the initial elements
    ArrayList arrayList(2, initial_elements);

    // Add new elements to the array list
    arrayList.addElement("Name");
    arrayList.addElement("is");
    arrayList.addElement("Santhosh");

    // Display all elements in the array list
    arrayList.displayElements();

    // Clean up dynamically allocated memory for initial elements
    delete[] initial_elements;

    return 0;
}
