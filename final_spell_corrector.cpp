#include "bst.cpp"
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm> 
#include <fstream>
#include <sstream>
#include<cmath>
#include<ctime>
using namespace std;
bool CHECKED=true;
string EXT;
string newEq="";
bool lTwopp=true;
bool SpecialChar=false;
	int hammingDist(string str1, string str2){ 
    int i = 0, count = 0; 
    while (str1[i] != '\0') 
    { 
        if (str1[i] != str2[i]) 
            count++; 
        i++; 
    } 
    return count; 
} 
 
class Process
{
public:
	char toLowerCase(char ch){
		ch=ch+32;
		return ch;	
	}	
	
	string ingFix(string str){		
		if(str[str.length()-1]=='g'&&str[str.length()-2]=='n'&&str[str.length()-3]=='i')
		{CHECKED=false;
		EXT="ing";
			str.erase(remove(str.end()-3, str.end(), 'i'), str.end());
			str.erase(remove(str.end()-3, str.end(), 'n'), str.end());
			str.erase(remove(str.end()-3, str.end(), 'g'), str.end());
		}	
		return str;
	}
	
	string sCheck(string str){	
		if(str[str.length()-1]=='s')
		{CHECKED=false;
	//	cout<<"good"<<endl;
		EXT="s";	
			str.erase(remove(str.end()-2, str.end(), 's'), str.end());
		}	
//		cout<<str<<endl;
		return str;
	}
	
	
	string es_ed_Check(string str){		
		if(str[str.length()-2]=='e' && str[str.length()-1]=='d')
		{CHECKED=false;
		EXT="ed";

			str.erase(remove(str.end()-2, str.end(), 'e'), str.end());
			str.erase(remove(str.end()-1, str.end(), 'd'), str.end());
		}
		else if(str[str.length()-2]=='e' && str[str.length()-1]=='s')
		{CHECKED=false;
		EXT="es";
			str.erase(remove(str.end()-2, str.end(), 'e'), str.end());
			str.erase(remove(str.end()-1, str.end(), 's'), str.end());
		}
		return str;
	}
	
	string lyCheck(string str){		
		if(str[str.length()-2]=='l' && str[str.length()-1]=='y')
		{CHECKED=false;
		EXT="ly";
			str.erase(remove(str.end()-2, str.end(), 'l'), str.end());
			str.erase(remove(str.end()-2, str.end(), 'y'), str.end());
		}	
		return str;
	}
	
	string iesCheck(string str){	
				
		if(str[str.length()-3]=='i' && str[str.length()-2]=='e' && str[str.length()-1]=='s')
		{CHECKED=false;
		EXT="ies";
			str.erase(remove(str.end()-3, str.end(), 'i'), str.end());
			str.erase(remove(str.end()-2, str.end(), 'e'), str.end());
			str.erase(remove(str.end()-1, str.end(), 's'), str.end());
			str=str+'y';
		}	
		return str;

	}
	
	string preProcess(string str){
	//surity for lowercase
	for (int i=0; i<str.length(); i++)
    if (isupper(str[i]))
    str[i]=toLowerCase(str[i]);
    bool CHECKED=true;

    
    //surity for no 'ies'
    if(CHECKED){

    str=iesCheck(str);}
        
            // surity for no 'ing'
    if(CHECKED){
    str=ingFix(str);

   }

	// surity for no 's'
	if(CHECKED){
    str=sCheck(str);

	}
    
    
    // surity for no 'es' ,'ed' 
    if(CHECKED){
    str=es_ed_Check(str);
    
	}
    


    if(CHECKED){

    str=lyCheck(str);}
	
    return str;
	}

	
 	string specialChar(string sub,char track){
 				if(track==',')
		sub.erase(remove(sub.end()-1, sub.end(), ','), sub.end());
		else if(track=='.')
		sub.erase(remove(sub.end()-1, sub.end(), '.'), sub.end());
		else if(track=='?')
		sub.erase(remove(sub.end()-1, sub.end(), '?'), sub.end());
		else if(track=='!')
		sub.erase(remove(sub.end()-1, sub.end(), '!'), sub.end());
		return sub;
	 }
}p;



class spell
{
	string word;
public:
	
	string checker(string str)
	{
		clock_t time_start, time_end;
		bool prePro=true;
		int dis=3;
		string exp;
		bool done=true;
		EXT="\0";
		char track=str[str.length()-1];
		if(track==','||track=='.'||track=='!'||track=='?')
		{
		str=p.specialChar(str,track);
		SpecialChar=true;	
		}
		if(prePro)
		str=p.preProcess(str);
		time_start = clock();
		
		if(b.search(str))
		{
		time_end = clock();
		cout<<"Time taken is " <<(float)(time_end-time_start)/CLOCKS_PER_SEC<<" seconds"<<endl;
		return "found";	
		
		}
		else if(EXT=="ing")
		{
			str=str+'e';
			prePro=false;
//			lTwopp=false;
//			newEq=str;
			if(b.search(str))
			return "found";
			else
			return "not";	

		}
		else if(EXT=="es"||EXT=="ed")
		{
			str=str+'e';
			if(b.search(str))
			return "found";
			else
			return "not";	
			
		}
		else 
		{
		return "not";
		}
	}

string corrector(string exp)
	{
		
	string sugg,sub;
		ifstream read("dict.txt");
		while (!read.eof())
	{
		
		getline(read,sugg,'\n');
	if(sugg[0]==exp[0]&&hammingDist(exp,sugg)<2&&sugg.length()<exp.length()+2)
	{
		cout<<sugg<<endl;
	}}
		wrong:
		cout<<endl<<"\t\tso what word you choose instead of "<<exp<<endl;
		string st;
		cin>>st;
		if(b.search(st))
		{
			return st+EXT;
		}
		
		else
		{
		cout<<"invalid choice "<<endl;
		goto wrong;	
		} 
		
	}

}s;


class fildHandler
{
	string exp,sub;
	char track;
	
public:
	
	void doFiles()
	{
			ifstream dic;
		dic.open("dict.txt");
	
		while (!dic.eof()){
	
		
		getline(dic,exp,'\n');
		if(isupper(exp[0])) exp[0]=p.toLowerCase(exp[0]);
			istringstream iss(exp);
			while(iss >> sub)
		b.insert(exp);
	}
	
		ifstream read("read.txt");
		ofstream write("write.txt");
		while (!read.eof())
	{
		getline(read,exp,'\n');
		
		track='\0';		
	istringstream iss(exp);
	while(iss >> sub)
	{
		if(s.checker(sub)=="found")
		{
		corrected:
		write<<sub;

		if(SpecialChar)
		write<<track;
		write<<" ";			
		}
	
	else{
		sub=p.preProcess(sub);
		sub=s.corrector(sub);
		goto corrected;
	}
	}
	write<<"\n";
	}

	}	
}f;


int main()
{
	
	f.doFiles();

return 0;	
}

