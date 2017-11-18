#include <iostream>
#include "LinkedStack.h"
using namespace std;
int main() {
	string s1;
	string s2;

	cout<<"Enter a very large number: "<<endl;
	cin>>s1;

	cout<<"Enter another very large number: "<<endl;
	cin>> s2;

	LinkedStack<int> stack1;
	LinkedStack<int> stack2;
	LinkedStack<int> result;

	// the following two for loops add the string contents into
	// their respective stacks
	for(size_t i = 0; i<s1.size(); i++) {
		char ch = s1[i];
		int adding; // current int to be added to stack
		adding = ch-'0';
		stack1.push(adding);
	}

	for(size_t i = 0; i<s2.size(); i++) {

		char ch = s2[i];
		int adding; // current int to be added to stack
		adding = ch-'0';
		stack2.push(adding);
	}


	/* For the while loop below, carry becomes true if a value should be
	 * added to the next "place" (or "digit")
	 * example:
	 * 		if the sum is 13 for "ones place",
	 * 		the ones place of the result will be 3, and the remaining
	 * 		10 in the ones place will become a 1 in the tens place.
	 * Since each place is managed separately, the bool carry becomes
	 * true in order to tell the program that the sum has carried over
	 * into the next digit.
	 */
	bool carry = 0;
	int thisDigit; // current digit

	while( (!stack1.isEmpty()) && (!stack2.isEmpty()) ) {
		int first = stack1.pop();
		int second = stack2.pop();

		if( first + second > 9 ) {

			thisDigit = first + second - 10;
			if (carry) {
				thisDigit++;
			}
			carry = 1;
		}

		else {
			if(!carry) {
				thisDigit = first + second;
			}

			// carry is true
			else {
				// will need to carry
				if(1 + first + second == 10) {
					thisDigit = 0;
					carry = 1;
				}

				// won't need to carry
				else {
					thisDigit = 1 + first + second;
					carry = 0;
				}
			}

		}

		result.push(thisDigit);
	}

	// if stack1 is shorter, it will become empty first,
	// and there will be some values in stack2 to add to the result
	if(stack1.isEmpty()) {

		while(!stack2.isEmpty()) {

			int current = stack2.pop();

			if(carry) {
				if(current < 9) {
					thisDigit = current + 1;
					carry = 0;
				}

				// current == 9, so carry to next
				else {
					thisDigit = 0;
					carry = 1;
				}
			}

			// !carry
			else {
				thisDigit = current;
			}
			result.push(thisDigit);

		}
	}

	else if(stack2.isEmpty()) {

		while(!stack1.isEmpty()) {

			int current = stack1.pop();

			if(carry) {
				if(current < 9) {
					thisDigit = current + 1;
					carry = 0;
				}

				// current == 9, so carry to next
				else {
					thisDigit = 0;
					carry = 1;
				}
			}

			// !carry
			else {
				thisDigit = current;
			}
			result.push(thisDigit);

		}
	}


	// all input stacks are empty, but we may still need to carry
	if(carry) {
		thisDigit = 1;
		result.push(thisDigit);
		carry = 0; // for the sake of completion
	}

	cout<<"result: "<<result;
}
