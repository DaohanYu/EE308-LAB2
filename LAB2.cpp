#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<vector>
using namespace std;

string key_word[32]=
{
		"auto","break","case","char","const","continue","default","double",
		"do","else","enum","extern","float","for","goto","if","int","long",
		"register","return","short","signed","sizeof","static","struct",
		"switch","typedef","union","unsigned","void","volatile","while"
};

vector<int>Case_num;
int switch_num=0;
int case_num=0;
int total_num=0;
int stack[1000]={0};
int ifelse_num=0;
int if_elseif_Else_num=0;
int top=-1;


bool Jud_1(string x,string y)//Keyword for comparison
{
	int Jud_2(char str);
	int position=x.find(y,0);
	int len=y.length();	
	if(position!=string::npos)
	{
		if(position==0) 
		{
			if(Jud_2(x[position+len]) ==0)
			{
				return 1;
			}
			else 
			  	return 0;
		}
		else
		{
			if(Jud_2(x[position+len])== 0&&Jud_2(x[position-1])==0)
			{
				return 1;
			}
			else
				return 0;
		}
	}
	return 0;
}



bool Jud_2(char str)//Check for letters
{
	if((str<='z'&&str >='a')||(str<='Z'&&str>='A'))
		return 1;
	else
		return 0;
}



void lev_12(string str)//Core character comparison, and count the number of switch-case 
{
	for(int i=0;i<32;i++)
	{
		if(Jud_1(str,key_word[i])==1)
		{
			if(Jud_1(str,"switch"))
			{
				Case_num.push_back(case_num);
				switch_num++;
				case_num = 0;
			}
			if(Jud_1(str,"case"))
			{
				case_num++;
			}
			total_num++;
			break;
		}
	}
}


void lev_34(string str)//If else counts and if elseif else nested counts 
{
	if(Jud_1(str,"else if"))
	{
		top++;
		stack[top]=2;
	}	
	else
	{
		if(Jud_1(str,"else"))
		{
			if(stack[top]==1)
			{
				ifelse_num++;
				top--;
			}
			else
			{
				if( stack[top] == 2 )
				{
			 		if_elseif_Else_num++;
			 		top--;
				}
			}
		}
		else
		{
			if( Jud_1( str ,"if" ) )
			{
				top++;
				stack[top] = 1;
			}
		}
	}
}



int main()
{
	int Lev;
	string Myfile,temp;
	cout << "请输入文件路径：" << endl;
	cin >> Myfile;

	ifstream myfile(Myfile.c_str());
	bool Jud_1(string x,string y);
	bool jud_2(char str);
	void lev_12(string str);
	void lev_34(string str); 
	while(getline(myfile ,temp))//Read the file
	{
		istringstream is (temp);
		string s;
		if(Lev>=3)
		{
			lev_34(temp);
		}
		while(is>>s) 
		{
			lev_12(s);
		}
	}
	if(Lev>=1) 
	{
		cout << "Total num:" <<total_num<<endl;
	}
	if(Lev>=2)
	{
		cout<<"Switch num:" <<switch_num<<endl;
		if(!Case_num.empty())
		{
			Case_num.push_back(case_num);
		}
		else
		{
			Case_num.push_back(0);
		}
		cout << "Case_num :";
		for(int i=1;i<=switch_num;i++)
		{
			cout<<Case_num[i]<<" ";
		}
		cout<<endl;
	}
	if(Lev>=3)
	{
		cout<<"If-else num:"<<ifelse_num<<endl;
	}
	if(Lev>=4)
	{
		cout<<"If-elseif-else num:"<<if_elseif_Else_num;
	}
}
