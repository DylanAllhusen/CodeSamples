#include "../Linear/Stack.hpp"
#include "../String/String.hpp"
#include"../Functions/functions.hpp"
//this is the compile line I used for the tests
//g++ -std=c++11 source/Algorithms/twostack.tests.cpp source/Linear/Stack.cpp source/Linear/SLL.cpp source/String/string.cpp source/Functions/functions.cpp  && ./a.out


/** Djikstra's Two Stack Algorithm
 * big O is always going to be n becasue no matter what 
 * the algorithm will have to run all the way through looking 
 * at every index
 * O(n) Omega(n) theta(n)
 */
double twostack(char * exp)
{
String str = String(exp);

Stack nums = Stack();
Stack ops = Stack();
  int leftP = 0;
  int rightP = 0;
for (int k =0;k < str.size(); k++)
{
  if(str.at(k) == '(')
  {
    leftP++;
    }
  else if(str.at(k) ==')')
  {
    rightP++;
  }
} 
if(leftP == rightP && leftP != 0 && rightP != 0)
{
for(int i,j = 0; i < str.size();i++,j++)
{
  
  if(str.at(i) == ' ')
  {
    //don't neeed to push
  }
  else if(str.at(i) == '(')
  {
    //don't neeed to push
  }
  else if(str.at(i) == '+')
  {
    ops.push('+');
  }
  else if(str.at(i) == '-')
  {
    ops.push('-');
  }
  else if(str.at(i) == '*')
  {
    ops.push('*');
  }
  else if(str.at(i) == '/')
  {
    ops.push('/');
  }
  else if(str.at(i) == '^')
  {
    ops.push('^');
  }
  else if(isdigit(str.at(i)))
  { 
            int sum = 0; 
            //while i is still a num (aka making sure it gets all digits of a num)
            while(j < str.size() &&  isdigit(str.at(j))) 
            { 
              //sum of this line will give the intire num (aka 176!=1,7,6  176==176)
                sum = (sum*10) + (str.at(i)-'0'); 
                 ++j;
            } 
            --j;
            nums.push(sum); 
           
  }
  //when you hit an right braket do computations for all nums and ops in stacks
  else if(str.at(i) == ')')
  {
    double val = 0.0;
    double numR = nums.top();//we know that the number to the right of the op will have been added after the one on the left
    nums.pop();//pop numR
    double numL = nums.top();//now the top is the num to the left of the op
    nums.pop();
    
    if(ops.top() == '+')
    {
    val = numL + numR;
    
    ops.pop();
    nums.push(val);
    }
    else if(ops.top() == '-')
    {
    val = numL - numR;
    ops.pop();
    nums.push(val);
    }
    else if(ops.top() == '*')
    {
    val = numL * numR;
    ops.pop();
    nums.push(val);
    }
    else if(ops.top() == '/')
    {
    val = numL / numR;
    ops.pop();
    nums.push(val);
    }
    else if(ops.top() == '^')
    {
    val = numL - numR;

      for (int i = 0; i < numR; ++i) 
      {
        val *= numL;
      }
    return val;
    ops.pop();
    nums.push(val);
    }

  }
return nums.top(); //this should return the last num in the num stack as the answer
}
}
else
{
  throw "bad exp";
}
}


//pusdo
//for the length of the exp
//-if you hit a white space or left Parenthesis ignore it
//-if you hit a num push into num stack
//-if you hit a op push it into op stack
//-if you hit a right parenthesis evaluate what you have in the stack
//have a statment that tells the computer what to do with each op
//pop an operstor and two nums needed for operation (gonna have to work on multi digits like 10 as well) 
//do the computation and return the post operation value to the num stack
//keep doing this until the operator stack is empty
//once you reach the end you should only have one num in your num stack
//return the top of num stack as your answer

//keep in mind that for - and / the first num poped should be the num on the right in the op
