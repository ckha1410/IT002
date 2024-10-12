#include "list.h"
// Constructor
List::List() {
    size = 0;
}
/** Function to display the point coordinates
    Input: double x: the value to add to the list.
    Output: No return value. Adds x to the list and increments size. */
void List::Them(double x) {
    arr.push_back(x);
    size++;
}
/** Function to remove the first occurrence of a given element.
    Input: double x: the value to remove from the list.
    Output: No return value. Removes the first occurrence of x if it exists. */
void List::Xoa(double x) {
    for (auto i = arr.begin(); i != arr.end(); i++)
        if (*i == x) {
            i = arr.erase(i);
            size--;
            return;
        }
}
/** Function to remove all occurrences of a given element from the list.
    Input: no input values.
    Output: No return value. Removes all occurrences of x. */
void List::Xoahet(double x) {
    for (auto i = arr.begin(); i != arr.end();) {
        if (*i == x) {
            i = arr.erase(i);
            size--;
        } else i++;
    }
}
/** Function to replace an element at a given index.
    Input:
    - int index: the position in the list to replace (0-based).
    - double value: the new value to set at the index.
    Output: No return value. If index is valid, replaces the element at index. */
void List::Thaythe(int idx, double y) {
    if (idx >= 0 && idx < size)
        arr[idx] = y;
}
/** Function to print the list in the format [a,b,c,...].
    Input: No input.
    Output: Prints the current list. */
void List::Xuat() {
    cout << "List hien tai: [";
    for (unsigned int i = 0; i < size; ++i) {
        cout << arr[i];
        if (i < size - 1) cout << ",";
    }
    cout << "]\n";
}
