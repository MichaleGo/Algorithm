#include<stdio.h> 
#include<string.h> 
#include<map> 
#include<stack> 
#include<math.h> 
#include<iostream> 
using namespace std; 
 
 
map<string, int> Varible; 
stack<char> Op; 
stack<int>  Opnum; 
string Instruction; 
string tmp; 
 
int GetproiIncoming(char c)    //??????
{ 
    switch (c) 
 { 
  case('+') : return 3; 
  case('-') : return 3; 
  case('*') : return 5; 
  case('/') : return 5; 
  case('%') : return 5; 
  case('(') : return 10; 
 case('^') : return 8; 
  } 
} 
 
int GetproInstack(char c)   //??????
{ 
   switch (c) 
 { 
  case('+') : return 4; 
  case('-') : return 4; 
  case('*') : return 6; 
  case('/') : return 6; 
  case('%') : return 6; 
  case('(') : return 1; 
  case('^') : return 7; 
  } 
} 
 
int comput(char c, int a, int b) 
{ 
    switch (c) 
 { 
  case('+') : return a+b; 
    case('-') : return a-b; 
    case('*') : return a*b; 
    case('/') : return a/b; 
    case('%') : return a%b; 
    case('^') : return (int)pow(double(a),double(b)); 
  } 
} 
 
int Getvar(string tmp) 
{ 
  int num = 0; 
   for (int i = 0; tmp[i]; i++) 
   { 
      if (tmp[i] >= '0'&&tmp[i] <= '9') 
        { 
          num = num * 10 + tmp[i] - '0'; 
     } 
      else if (tmp[i] >= 'a'&&tmp[i] <= 'z') 
       { 
          string var; 
            int k = i; 
         while (tmp[k] >= 'a'&&tmp[k] <= 'z') 
         { 
              k++; 
           } 
          var = tmp.substr(i, k-i); 
          Opnum.push(Varible[var]); 
          i = k - 1; 
     } 
      else if (!(tmp[i] >= '0'&&tmp[i] <= '9') && !(tmp[i] >= 'a'&&tmp[i] <= 'z')) 
       { 
          if (tmp[i] == '=') continue; 
           if ((tmp[i - 1] >= '0'&&tmp[i - 1] <= '9')) 
          { 
              Opnum.push(num); num = 0; 
          } 
          else if (!(tmp[i - 1] >= '0'&&tmp[i - 1] <= '9') && !(tmp[i - 1] >= 'a'&&tmp[i - 1] <= 'z')&&(tmp[i]=='+'||tmp[i]=='-')) 
           { 
              i++; int k = i; 
                while (tmp[k] && (tmp[k] >= '0'&&tmp[k] <= '9')) 
             { 
                  num = num * 10 + tmp[k] - '0'; k++; 
                } 
              if (tmp[i - 1] == '-') num *= -1;   i = k - 1; continue; 
           } 
          if (Op.empty()||tmp[i]=='(') 
           { 
              Op.push(tmp[i]); continue; 
         } 
          else if (tmp[i] == ')') 
            { 
              char op; 
               while (!Op.empty() && (op = Op.top()) != '(') 
              { 
                  int b = Opnum.top(); Opnum.pop(); 
                  int a = Opnum.top(); Opnum.pop(); 
                  if (b == 0 && op == '/') 
                       continue; 
                  else { Opnum.push(comput(op,a,b)); } 
                   Op.pop(); 
              } 
              Op.pop(); 
            } 
            else 
           { 
              int Incoming = GetproiIncoming(tmp[i]); 
                int Instack; 
               char op; 
               while (!Op.empty()&&(Instack = GetproInstack(Op.top())) > Incoming) 
             { 
                  op = Op.top(); 
                 int b = Opnum.top(); Opnum.pop(); 
                  int a = Opnum.top(); Opnum.pop(); 
                  if (b == 0 && op == '/') 
                       continue; 
                  else { Opnum.push(comput(op, a, b)); } 
                 Op.pop(); 
              } 
              Op.push(tmp[i]); 
           } 
      } 
  } 
  if (tmp[tmp.length()-1] >= '0'&&tmp[tmp.length()-1] <= '9') 
      Opnum.push(num); 
   if (!Op.empty()||!Opnum.empty()) 
   { 
 
     while (!Op.empty()) 
        { 
          char op = Op.top(); 
            int b = Opnum.top(); Opnum.pop(); 
          int a = Opnum.top(); Opnum.pop(); 
          if (b == 0 && op == '/') 
               continue; 
          else { Opnum.push(comput(op, a, b)); } 
         Op.pop(); 
      } 
      return Opnum.top(); 
    } 
  else return num; 
} 
int main() 
{ 
    //freopen("1.txt", "r", stdin); 
    while (getline(cin,Instruction)) 
   { 
      if (Instruction == "end") 
          break; 
     while (!Op.empty()) 
            Op.pop(); 
      while (!Opnum.empty()) 
         Opnum.pop(); 
       if (Instruction[0] == '?') 
     { 
          tmp = Instruction.substr(2); 
           int num = Varible.find(tmp)->second; 
            cout << tmp<< '='<<num<< endl; 
     } 
      else if (Instruction[0] >= 'a'&&Instruction[0] <= 'z') 
       { 
          int i = 0; 
         string varble; 
         while (Instruction[i] != '=') 
          { 
              i++; 
           } 
          varble = Instruction.substr(0, i); 
         if (Varible.count(varble) == 0) 
            { 
              Varible[varble] = 0; 
                
           } 
          string tmp = Instruction.substr(i); 
            Varible[varble] = Getvar(tmp); 
     } 
  } 
  return 0; 
}