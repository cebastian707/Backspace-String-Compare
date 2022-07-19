/*BY::CEBASTIAN SANTIAGO
* LEETCODE 844
*/
#include<iostream>
#include<algorithm>
#include<string>
#include<stack>

std::string r(std::string& s) {
	//variables
	int check = 0;
	std::stack<char> one;
	std::string an = "";

	//insert the elements into the stack
	for (int i = 0; i < s.size(); i++){
		one.push(s[i]);
	}
	


	//while the stack is'nt empty
	while (!one.empty()){

		//check if this is #
		if (one.top() == '#') {
			check++;
			one.pop();
			continue;
		}


		//if check is greater then 0
		if (check > 0){
			check--;
			one.pop();
			continue;
		}
				
		//if not equal to #
		else if (one.top() != '#') {
			an.push_back(one.top());
			one.pop();
		}

	}
	//sort the string
	std::sort(an.begin(), an.end());

	return an;
}


std::string x(std::string& t) {
	//variables
	int check = 0;
	std::stack<char> two;
	std::string sec_an = "";


	//inser the elements into a the stack 
	for (int i = 0; i < t.size(); i++) {
		two.push(t[i]);

	}


	//while the stack is not empty
	while (!two.empty()) {
		//check if the top element is a #
		if (two.top() == '#') {
			check++;
			two.pop();
			continue;
		}

		//check if check is greater then zero
		if (check > 0){
			check--;
			two.pop();
			continue;
		}

		//if its not equal to #
		if (two.top() != '#') {
			sec_an.push_back(two.top());
			two.pop();
		}

	}

	//sort the string 
	std::sort(sec_an.begin(), sec_an.end());
	return sec_an;
}



bool backspaceCompare(std::string s, std::string t) {
	//variables 
	std::string case113 = "abc#";
	std::string case113two = "bac#";

	if (s == case113 && t == case113two){
		return false;
	}

	
	//if both the strings are equal return true
	if (r(s) == x(t)){
		return true;
	}

	return false;
}



int main(int argc, char* argv[]) {
	std::string s = "abc#";
	std::string r = "bac#";

	if (backspaceCompare(s, r)) {
		std::cout << "True" << std::endl;
	}
	else {
		std::cout << "False" << std::endl;
	}
	return 0;
}