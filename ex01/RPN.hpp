#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <iostream>
#include <string>

class   RPN {

	private :
	
		void    			stockResult(char &oper);
		std::stack<int>		numbers;

 	public :

		RPN(char *args);
		RPN(const RPN &other);
		RPN& operator=(const RPN &other);
		~RPN();

};


#endif