#include <iostream>

using namespace std;

    // effectively passing back 2 values
      // the array of numbers read (via int *)
    // and the number of values read (via size)
int* read_data(int& size){
    int init_size = size;
    int times = 2;
    int * nums = new int[size]; //make array big enough for users rough guess at quantity
    int num_read = 0;
    int quantity =0;
    int remaining;     //how much space remains in the array
    cin >> num_read;
    int index =0;
    while(num_read != -1){
        quantity++;
        nums[index] = num_read;
        index++;
        remaining--;
        if(remaining == 0){
            int * numsBigger = new int[init_size * times];
            //copy contents to new array
            for(int i =0; i < size ; i++){
                numsBigger[i] = nums[i];
            }
            //let nums be this new array
        nums = numsBigger;
        times++; //next array will have to be bigger again
        }
    cin >> num_read; //read next number
    }
    cout << "[read " << quantity << "]" << endl;
    size = quantity;
    return nums;
    }

int main()
{
    int total_user_numbers =0;
    cout << "Roughly how many numbers will you input? ";
    cin >> total_user_numbers;
    //make initial array this big
    //but  count the number actually read
    int * numbers = read_data(total_user_numbers);
    cout << "collected " << total_user_numbers << endl;
    for(int i = 0; i < total_user_numbers; i++){
        cout << numbers[i] << endl;
    }
    delete [] numbers;
    }
