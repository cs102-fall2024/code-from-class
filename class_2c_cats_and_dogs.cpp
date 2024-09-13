#include <iostream>
#include <string>

using namespace std;

const int NUM_PETS = 1000;

/**
 * @brief Calculates the average of numbers in nums up to (not including) index size
 * 
 * @param nums - array of numbers
 * @param size - size of nums
 * @return double - average of numbers in array
 */
double average(double nums[], int size) {
    double sum = 0;
    for (int i = 0; i < size; i ++) {
        sum += nums[i];
    }
    return sum / size;
}

//controls the program
//requires file redirect to class_2b_input.txt as input
//this command is:
// ./array_average < class_2b_input.txt
int main() {
    // If you assign fewer value than elements in the array, this will 
    // automatically set the rest to 0!

    double dog_weights[NUM_PETS] = {0.0};
    double cat_weights[NUM_PETS] = {0.0};

    double weight;
    string animal_type;
    int dog_index = 0;
    int cat_index = 0;

    cin >> animal_type;

    while (animal_type != "end"){
            cin >> weight;

            if (animal_type == "dog") {
                dog_weights[dog_index] = weight;
                dog_index++;
            }
            else if (animal_type == "cat") {
                cat_weights[cat_index] = weight;
                cat_index++;
            }
            else {
                cout << "Unauthorized animal: " << animal_type << endl;
            }

            cin >> animal_type;
    }

    

    // Q: Why can we pass dog_index and cat_index as arguments to our average function?
    // A: we made the arrays bigger than necessary, since we didn't know
    // How many elements we woudl have. THe indices are at the right place
    // after we fill the arrays.
    cout << "The average dog weighs " << average(dog_weights, dog_index) << endl;
    cout << "The average cat weighs " << average(cat_weights, cat_index) << endl;
}